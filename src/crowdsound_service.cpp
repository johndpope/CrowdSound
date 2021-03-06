#include <chrono>
#include <iostream>
#include <grpc++/grpc++.h>

#include "crowdsound_service.hpp"
#include "proto/crowdsound_service.pb.h"
#include "proto/crowdsound_service.grpc.pb.h"
#include "proto/crowdsound_admin_service.pb.h"
#include "proto/crowdsound_admin_service.grpc.pb.h"

using namespace std;

using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerWriter;
using grpc::Status;
using grpc::StatusCode;

using CrowdSound::PingRequest;
using CrowdSound::PingResponse;
using CrowdSound::GetSessionDataRequest;
using CrowdSound::GetSessionDataResponse;
using CrowdSound::GetQueueRequest;
using CrowdSound::GetQueueResponse;
using CrowdSound::ListTrendingArtistsRequest;
using CrowdSound::ListTrendingArtistsResponse;
using CrowdSound::PostSongRequest;
using CrowdSound::PostSongResponse;
using CrowdSound::VoteSongRequest;
using CrowdSound::VoteSongResponse;
using CrowdSound::VoteSkipRequest;
using CrowdSound::VoteSkipResponse;

using CrowdSound::SkipStatusRequest;
using CrowdSound::SkipStatusResponse;
using CrowdSound::SkipRequest;
using CrowdSound::SkipResponse;

using skrillex::DB;
using skrillex::Mapper;
using skrillex::ResultSet;
using skrillex::ReadOptions;
using skrillex::WriteOptions;
using skrillex::SortType;
using skrillex::Song;
using skrillex::Artist;
using skrillex::Genre;

CrowdSoundImpl::CrowdSoundImpl(shared_ptr<Server> server)
: server_(server)
, db_(server->db_)
, mapper_(server_->db_)
{
}


Status CrowdSoundImpl::Ping(ServerContext* context, const PingRequest* request, PingResponse* resp) {
    cout << "[server] Received ping from: " << request->user_id() << endl;

    server_->updateActivity(request->user_id());

    return Status::OK;
}

Status CrowdSoundImpl::GetSessionData(ServerContext* context, const GetSessionDataRequest* request, GetSessionDataResponse* resp) {
    {
        lock_guard<mutex> lock(server_->settings_guard_);
        resp->set_session_name(server_->session_name_);
    }

    int users = 0;
    skrillex::Status status = db_->getSessionUserCount(users, server_->skrillex_read_options_);
    if (status != skrillex::Status::OK()) {
        return Status(StatusCode::INTERNAL, status.message());
    }

    resp->set_num_users(users);

    return Status::OK;
}

Status CrowdSoundImpl::GetPlaying(ServerContext* context, const GetPlayingRequest* request, GetPlayingResponse* response) {
    ResultSet<Song> resultSet;

    server_->updateActivity(request->user_id());

    skrillex::Status status = this->db_->getBuffer(resultSet);
    if (status != skrillex::Status::OK()) {
        return Status(StatusCode::INTERNAL, status.message());
    }

    if (resultSet.size() > 0) {
        response->set_name(resultSet.begin()->name);
        response->set_artist(resultSet.begin()->artist.name);
        response->set_genre(resultSet.begin()->genre.name);
    }

    return Status::OK;
}

Status CrowdSoundImpl::GetQueue(ServerContext* context, const GetQueueRequest* request, ServerWriter<GetQueueResponse>* writer) {
    ResultSet<Song> resultSet;

    server_->updateActivity(request->user_id());

    // First, send back the buffer
    skrillex::Status status = this->db_->getBuffer(resultSet);
    if (status != skrillex::Status::OK()) {
        return Status(StatusCode::INTERNAL, status.message());
    }

    int count = 0;
    bool first = true;
    for (Song s : resultSet) {
        if (first) {
            first = false;
            continue;
        }

        GetQueueResponse resp;
        resp.set_name(s.name);
        resp.set_artist(s.artist.name);
        resp.set_genre(s.genre.name);
        resp.set_isplaying(false);
        resp.set_isbuffered(true);

        if (!writer->Write(resp)) {
            break;
        }

        count++;
    }

    status = this->db_->getQueue(resultSet);
    if (status != skrillex::Status::OK()) {
        return Status(StatusCode::INTERNAL, status.message());
    }

    int queueSize = 0;
    {
        lock_guard<mutex> lock(server_->settings_guard_);
        queueSize = server_->queue_size_;
    }

    for (Song s : resultSet) {
        GetQueueResponse resp;
        resp.set_name(s.name);
        resp.set_artist(s.artist.name);
        resp.set_genre(s.genre.name);
        resp.set_isplaying(false);
        resp.set_isbuffered(false);

        if (!writer->Write(resp)) {
            break;
        }

        if (++count >= queueSize) {
            break;
        }
    }

    return Status::OK;
}

Status CrowdSoundImpl::ListTrendingArtists(ServerContext* context, const ListTrendingArtistsRequest* request, ServerWriter<ListTrendingArtistsResponse>* writer) {
    ReadOptions voteSort = server_->skrillex_read_options_;
    voteSort.sort = SortType::Votes;

    ResultSet<Artist> resultSet;
    skrillex::Status status = this->db_->getArtists(resultSet, voteSort);
    if (status != skrillex::Status::OK()) {
        return Status(StatusCode::INTERNAL, status.message());
    }

    int trendingArtistsSize = 0;
    {
        lock_guard<mutex> lock(server_->settings_guard_);
        trendingArtistsSize = server_->trending_artists_size_;
    }

    int count = 0;
    for (Artist s : resultSet) {
        ListTrendingArtistsResponse resp;
        resp.set_name(s.name);
        resp.set_score(s.votes);

        if (!writer->Write(resp)) {
            break;
        }

        if (++count >= trendingArtistsSize) {
            break;
        }
    }

    return Status::OK;
}

Status CrowdSoundImpl::PostSong(ServerContext* context, ServerReader<PostSongRequest>* reader, PostSongResponse* resp) {
    // We want to decompose the PostSongRequest into an internal song item,
    // which consists of an Artist, Genre, and Song. However, PostSongRequest
    // may not be an actual Song, maybe just an artist (or at least, all we
    // can extract is the artist).
    //
    // Note: If a client sends PostSong() after a VoteSong(), their vote will be reset.
    PostSongRequest request;
    skrillex::Status status = skrillex::Status::OK();

    while (reader->Read(&request)) {
        Song song;
        string firstArtist;
        if (request.artist_size() > 0) {
            firstArtist = request.artist(0);
        }

        cout << "[server] Received PostSong: [" << request.genre() << "] " << firstArtist << " - " << request.name() << endl;
        status = mapper_.map(song, request.name(), firstArtist, request.genre());
        if (status != skrillex::Status::OK()) {
            return Status(StatusCode::INTERNAL, status.message());
        }

        if (song.genre.id > 0) {
            status = db_->voteGenre(request.user_id(), song.genre, 0);
            if (status != skrillex::Status::OK()) {
                return Status(StatusCode::INTERNAL, status.message());
            }
        }
        if (song.artist.id > 0) {
            status = db_->voteArtist(request.user_id(), song.artist, 0);
            if (status != skrillex::Status::OK()) {
                return Status(StatusCode::INTERNAL, status.message());
            }
        }
        if (song.id > 0) {
            status = db_->voteSong(request.user_id(), song, 0);
            if (status != skrillex::Status::OK()) {
                return Status(StatusCode::INTERNAL, status.message());
            }
        }
    }

    server_->runAlgorithm();

    return Status::OK;
}

Status CrowdSoundImpl::VoteSong(ServerContext* context, const VoteSongRequest* request, VoteSongResponse* resp) {
    // The way the current API is designed, there is no feedback to the client
    // about what a PostSong results in, and therefore we have to recompute the
    // target ID each time VoteSong gets called. The algorithm should be
    // deterministic for a given input, so it should be semantically okay.
    //
    // We can alleviate the pressure by either:
    //     a) Internal caching (which, should actually be quick in the parser)
    //     b) Provide feedback to client, so they can vote using ID's instead of string values.
    //
    // The second approach is pretty invasive and touches a bunch of stuff (and probably
    // introduces a lot of work client side too). The first approach comes relatively
    // free with the parsing model, and fuck it, it's a prototype with strick deadlines.

    cout << "[server] Received VoteSong: [" << request->artist() << " - " << request->name() << "] - " << request->like() << endl;

    Song song;
    int amount = request->like() ? 1 : -1;
    skrillex::Status status = mapper_.lookup(song, request->name(), request->artist());

    if (status.notFound()) {
        return Status(StatusCode::NOT_FOUND, status.message());
    } else if (status != skrillex::Status::OK()) {
        return Status(StatusCode::INTERNAL, status.message());
    }

    status = db_->voteSong(request->user_id(), song, amount);
    if (status != skrillex::Status::OK()) {
        return Status(StatusCode::INTERNAL, status.message());
    }

    if (song.artist.id > 0) {
        status = db_->voteArtist(request->user_id(), song.artist, amount);
        if (status != skrillex::Status::OK()) {
            return Status(StatusCode::INTERNAL, status.message());
        }
    }

    if (song.genre.id > 0) {
        status = db_->voteGenre(request->user_id(), song.genre, amount);
        if (status != skrillex::Status::OK()) {
            return Status(StatusCode::INTERNAL, status.message());
        }
    }

    server_->updateActivity(request->user_id());
    server_->runAlgorithm();

    return Status::OK;
}

Status CrowdSoundImpl::VoteArtist(ServerContext* context, const VoteArtistRequest* request, VoteArtistResponse* resp) {
    cout << "[server Received VoteArtist: " << request->artist() << endl;

    skrillex::Artist artist;
    int amount = request->like() ? 1 : -1;
    skrillex::Status status = mapper_.lookup(artist, request->artist());

    if (status.notFound()) {
        return Status(StatusCode::NOT_FOUND, status.message());
    } else if (status != skrillex::Status::OK()) {
        return Status(StatusCode::INTERNAL, status.message());
    }

    status = db_->voteArtist(request->user_id(), artist, amount);
    if (status != skrillex::Status::OK()) {
        return Status(StatusCode::INTERNAL, status.message());
    }

    server_->updateActivity(request->user_id());
    server_->runAlgorithm();

    return Status::OK;
}

Status CrowdSoundImpl::VoteSkip(ServerContext* context, const VoteSkipRequest* request, VoteSkipResponse* resp) {
    server_->updateActivity(request->user_id());
    server_->voteSkip(request->user_id());

    return Status::OK;
}

