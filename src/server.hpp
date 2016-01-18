#ifndef crowdsoundserver_hpp
#define crowdsoundserver_hpp

#include <memory>
#include <string>
#include <vector>

#include <grpc++/grpc++.h>
#include "proto/crowdsound_service.grpc.pb.h"

#include "skrillex/skrillex.hpp"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerWriter;
using grpc::ServerReader;
using grpc::Status;

using CrowdSound::ListSongsRequest;
using CrowdSound::ListSongsResponse;
using CrowdSound::ListTrendingArtistsRequest;
using CrowdSound::ListTrendingArtistsResponse;
using CrowdSound::PostSongRequest;
using CrowdSound::PostSongResponse;
using CrowdSound::VoteSongRequest;
using CrowdSound::VoteSongResponse;

struct Song {
    std::string name;
    std::string artist;
    std::string genre;

    int vote;
};

class CrowdSoundImpl final : public CrowdSound::CrowdSound::Service {
public:
    explicit CrowdSoundImpl(std::shared_ptr<skrillex::DB> db);

    Status ListSongs(ServerContext* context, const ListSongsRequest* request, ServerWriter<ListSongsResponse>* writer) override;
    Status ListTrendingArtists(ServerContext* context, const ListTrendingArtistsRequest* request, ServerWriter<ListTrendingArtistsResponse>* writer) override;
    Status PostSong(ServerContext* context, ServerReader<PostSongRequest>* request, PostSongResponse* resp) override;
    Status VoteSong(ServerContext* context, const VoteSongRequest* request, VoteSongResponse* resp) override;

private:
    std::shared_ptr<skrillex::DB> db_;
    std::vector<Song> songs_;
};

#endif