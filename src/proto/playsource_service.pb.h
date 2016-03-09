// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/playsource_service.proto

#ifndef PROTOBUF_proto_2fplaysource_5fservice_2eproto__INCLUDED
#define PROTOBUF_proto_2fplaysource_5fservice_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace Playsource {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_proto_2fplaysource_5fservice_2eproto();
void protobuf_AssignDesc_proto_2fplaysource_5fservice_2eproto();
void protobuf_ShutdownFile_proto_2fplaysource_5fservice_2eproto();

class GetPlayHistoryRequest;
class GetPlayHistoryResponse;
class GetPlayingRequest;
class GetPlayingResponse;
class QueueSongRequest;
class QueueSongResponse;
class SkipSongRequest;
class SkipSongResponse;
class Song;

// ===================================================================

class Song : public ::google::protobuf::Message {
 public:
  Song();
  virtual ~Song();

  Song(const Song& from);

  inline Song& operator=(const Song& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Song& default_instance();

  void Swap(Song* other);

  // implements Message ----------------------------------------------

  inline Song* New() const { return New(NULL); }

  Song* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Song& from);
  void MergeFrom(const Song& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Song* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 song_id = 1;
  void clear_song_id();
  static const int kSongIdFieldNumber = 1;
  ::google::protobuf::int32 song_id() const;
  void set_song_id(::google::protobuf::int32 value);

  // optional string name = 2;
  void clear_name();
  static const int kNameFieldNumber = 2;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // repeated string artists = 3;
  int artists_size() const;
  void clear_artists();
  static const int kArtistsFieldNumber = 3;
  const ::std::string& artists(int index) const;
  ::std::string* mutable_artists(int index);
  void set_artists(int index, const ::std::string& value);
  void set_artists(int index, const char* value);
  void set_artists(int index, const char* value, size_t size);
  ::std::string* add_artists();
  void add_artists(const ::std::string& value);
  void add_artists(const char* value);
  void add_artists(const char* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& artists() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_artists();

  // @@protoc_insertion_point(class_scope:Playsource.Song)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::RepeatedPtrField< ::std::string> artists_;
  ::google::protobuf::int32 song_id_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_proto_2fplaysource_5fservice_2eproto();
  friend void protobuf_AssignDesc_proto_2fplaysource_5fservice_2eproto();
  friend void protobuf_ShutdownFile_proto_2fplaysource_5fservice_2eproto();

  void InitAsDefaultInstance();
  static Song* default_instance_;
};
// -------------------------------------------------------------------

class QueueSongRequest : public ::google::protobuf::Message {
 public:
  QueueSongRequest();
  virtual ~QueueSongRequest();

  QueueSongRequest(const QueueSongRequest& from);

  inline QueueSongRequest& operator=(const QueueSongRequest& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const QueueSongRequest& default_instance();

  void Swap(QueueSongRequest* other);

  // implements Message ----------------------------------------------

  inline QueueSongRequest* New() const { return New(NULL); }

  QueueSongRequest* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const QueueSongRequest& from);
  void MergeFrom(const QueueSongRequest& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(QueueSongRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .Playsource.Song song = 1;
  bool has_song() const;
  void clear_song();
  static const int kSongFieldNumber = 1;
  const ::Playsource::Song& song() const;
  ::Playsource::Song* mutable_song();
  ::Playsource::Song* release_song();
  void set_allocated_song(::Playsource::Song* song);

  // @@protoc_insertion_point(class_scope:Playsource.QueueSongRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::Playsource::Song* song_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_proto_2fplaysource_5fservice_2eproto();
  friend void protobuf_AssignDesc_proto_2fplaysource_5fservice_2eproto();
  friend void protobuf_ShutdownFile_proto_2fplaysource_5fservice_2eproto();

  void InitAsDefaultInstance();
  static QueueSongRequest* default_instance_;
};
// -------------------------------------------------------------------

class QueueSongResponse : public ::google::protobuf::Message {
 public:
  QueueSongResponse();
  virtual ~QueueSongResponse();

  QueueSongResponse(const QueueSongResponse& from);

  inline QueueSongResponse& operator=(const QueueSongResponse& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const QueueSongResponse& default_instance();

  void Swap(QueueSongResponse* other);

  // implements Message ----------------------------------------------

  inline QueueSongResponse* New() const { return New(NULL); }

  QueueSongResponse* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const QueueSongResponse& from);
  void MergeFrom(const QueueSongResponse& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(QueueSongResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 song_id = 1;
  void clear_song_id();
  static const int kSongIdFieldNumber = 1;
  ::google::protobuf::int32 song_id() const;
  void set_song_id(::google::protobuf::int32 value);

  // optional bool queued = 2;
  void clear_queued();
  static const int kQueuedFieldNumber = 2;
  bool queued() const;
  void set_queued(bool value);

  // optional bool found = 3;
  void clear_found();
  static const int kFoundFieldNumber = 3;
  bool found() const;
  void set_found(bool value);

  // optional bool finished = 4;
  void clear_finished();
  static const int kFinishedFieldNumber = 4;
  bool finished() const;
  void set_finished(bool value);

  // @@protoc_insertion_point(class_scope:Playsource.QueueSongResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::int32 song_id_;
  bool queued_;
  bool found_;
  bool finished_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_proto_2fplaysource_5fservice_2eproto();
  friend void protobuf_AssignDesc_proto_2fplaysource_5fservice_2eproto();
  friend void protobuf_ShutdownFile_proto_2fplaysource_5fservice_2eproto();

  void InitAsDefaultInstance();
  static QueueSongResponse* default_instance_;
};
// -------------------------------------------------------------------

class SkipSongRequest : public ::google::protobuf::Message {
 public:
  SkipSongRequest();
  virtual ~SkipSongRequest();

  SkipSongRequest(const SkipSongRequest& from);

  inline SkipSongRequest& operator=(const SkipSongRequest& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SkipSongRequest& default_instance();

  void Swap(SkipSongRequest* other);

  // implements Message ----------------------------------------------

  inline SkipSongRequest* New() const { return New(NULL); }

  SkipSongRequest* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SkipSongRequest& from);
  void MergeFrom(const SkipSongRequest& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(SkipSongRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:Playsource.SkipSongRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_proto_2fplaysource_5fservice_2eproto();
  friend void protobuf_AssignDesc_proto_2fplaysource_5fservice_2eproto();
  friend void protobuf_ShutdownFile_proto_2fplaysource_5fservice_2eproto();

  void InitAsDefaultInstance();
  static SkipSongRequest* default_instance_;
};
// -------------------------------------------------------------------

class SkipSongResponse : public ::google::protobuf::Message {
 public:
  SkipSongResponse();
  virtual ~SkipSongResponse();

  SkipSongResponse(const SkipSongResponse& from);

  inline SkipSongResponse& operator=(const SkipSongResponse& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SkipSongResponse& default_instance();

  void Swap(SkipSongResponse* other);

  // implements Message ----------------------------------------------

  inline SkipSongResponse* New() const { return New(NULL); }

  SkipSongResponse* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SkipSongResponse& from);
  void MergeFrom(const SkipSongResponse& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(SkipSongResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:Playsource.SkipSongResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_proto_2fplaysource_5fservice_2eproto();
  friend void protobuf_AssignDesc_proto_2fplaysource_5fservice_2eproto();
  friend void protobuf_ShutdownFile_proto_2fplaysource_5fservice_2eproto();

  void InitAsDefaultInstance();
  static SkipSongResponse* default_instance_;
};
// -------------------------------------------------------------------

class GetPlayingRequest : public ::google::protobuf::Message {
 public:
  GetPlayingRequest();
  virtual ~GetPlayingRequest();

  GetPlayingRequest(const GetPlayingRequest& from);

  inline GetPlayingRequest& operator=(const GetPlayingRequest& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GetPlayingRequest& default_instance();

  void Swap(GetPlayingRequest* other);

  // implements Message ----------------------------------------------

  inline GetPlayingRequest* New() const { return New(NULL); }

  GetPlayingRequest* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GetPlayingRequest& from);
  void MergeFrom(const GetPlayingRequest& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(GetPlayingRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:Playsource.GetPlayingRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_proto_2fplaysource_5fservice_2eproto();
  friend void protobuf_AssignDesc_proto_2fplaysource_5fservice_2eproto();
  friend void protobuf_ShutdownFile_proto_2fplaysource_5fservice_2eproto();

  void InitAsDefaultInstance();
  static GetPlayingRequest* default_instance_;
};
// -------------------------------------------------------------------

class GetPlayingResponse : public ::google::protobuf::Message {
 public:
  GetPlayingResponse();
  virtual ~GetPlayingResponse();

  GetPlayingResponse(const GetPlayingResponse& from);

  inline GetPlayingResponse& operator=(const GetPlayingResponse& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GetPlayingResponse& default_instance();

  void Swap(GetPlayingResponse* other);

  // implements Message ----------------------------------------------

  inline GetPlayingResponse* New() const { return New(NULL); }

  GetPlayingResponse* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GetPlayingResponse& from);
  void MergeFrom(const GetPlayingResponse& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(GetPlayingResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .Playsource.Song song = 1;
  bool has_song() const;
  void clear_song();
  static const int kSongFieldNumber = 1;
  const ::Playsource::Song& song() const;
  ::Playsource::Song* mutable_song();
  ::Playsource::Song* release_song();
  void set_allocated_song(::Playsource::Song* song);

  // @@protoc_insertion_point(class_scope:Playsource.GetPlayingResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::Playsource::Song* song_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_proto_2fplaysource_5fservice_2eproto();
  friend void protobuf_AssignDesc_proto_2fplaysource_5fservice_2eproto();
  friend void protobuf_ShutdownFile_proto_2fplaysource_5fservice_2eproto();

  void InitAsDefaultInstance();
  static GetPlayingResponse* default_instance_;
};
// -------------------------------------------------------------------

class GetPlayHistoryRequest : public ::google::protobuf::Message {
 public:
  GetPlayHistoryRequest();
  virtual ~GetPlayHistoryRequest();

  GetPlayHistoryRequest(const GetPlayHistoryRequest& from);

  inline GetPlayHistoryRequest& operator=(const GetPlayHistoryRequest& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GetPlayHistoryRequest& default_instance();

  void Swap(GetPlayHistoryRequest* other);

  // implements Message ----------------------------------------------

  inline GetPlayHistoryRequest* New() const { return New(NULL); }

  GetPlayHistoryRequest* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GetPlayHistoryRequest& from);
  void MergeFrom(const GetPlayHistoryRequest& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(GetPlayHistoryRequest* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:Playsource.GetPlayHistoryRequest)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_proto_2fplaysource_5fservice_2eproto();
  friend void protobuf_AssignDesc_proto_2fplaysource_5fservice_2eproto();
  friend void protobuf_ShutdownFile_proto_2fplaysource_5fservice_2eproto();

  void InitAsDefaultInstance();
  static GetPlayHistoryRequest* default_instance_;
};
// -------------------------------------------------------------------

class GetPlayHistoryResponse : public ::google::protobuf::Message {
 public:
  GetPlayHistoryResponse();
  virtual ~GetPlayHistoryResponse();

  GetPlayHistoryResponse(const GetPlayHistoryResponse& from);

  inline GetPlayHistoryResponse& operator=(const GetPlayHistoryResponse& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GetPlayHistoryResponse& default_instance();

  void Swap(GetPlayHistoryResponse* other);

  // implements Message ----------------------------------------------

  inline GetPlayHistoryResponse* New() const { return New(NULL); }

  GetPlayHistoryResponse* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GetPlayHistoryResponse& from);
  void MergeFrom(const GetPlayHistoryResponse& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(GetPlayHistoryResponse* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .Playsource.Song song = 1;
  bool has_song() const;
  void clear_song();
  static const int kSongFieldNumber = 1;
  const ::Playsource::Song& song() const;
  ::Playsource::Song* mutable_song();
  ::Playsource::Song* release_song();
  void set_allocated_song(::Playsource::Song* song);

  // @@protoc_insertion_point(class_scope:Playsource.GetPlayHistoryResponse)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::Playsource::Song* song_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_proto_2fplaysource_5fservice_2eproto();
  friend void protobuf_AssignDesc_proto_2fplaysource_5fservice_2eproto();
  friend void protobuf_ShutdownFile_proto_2fplaysource_5fservice_2eproto();

  void InitAsDefaultInstance();
  static GetPlayHistoryResponse* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Song

// optional int32 song_id = 1;
inline void Song::clear_song_id() {
  song_id_ = 0;
}
inline ::google::protobuf::int32 Song::song_id() const {
  // @@protoc_insertion_point(field_get:Playsource.Song.song_id)
  return song_id_;
}
inline void Song::set_song_id(::google::protobuf::int32 value) {
  
  song_id_ = value;
  // @@protoc_insertion_point(field_set:Playsource.Song.song_id)
}

// optional string name = 2;
inline void Song::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Song::name() const {
  // @@protoc_insertion_point(field_get:Playsource.Song.name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Song::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Playsource.Song.name)
}
inline void Song::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Playsource.Song.name)
}
inline void Song::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Playsource.Song.name)
}
inline ::std::string* Song::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:Playsource.Song.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Song::release_name() {
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Song::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:Playsource.Song.name)
}

// repeated string artists = 3;
inline int Song::artists_size() const {
  return artists_.size();
}
inline void Song::clear_artists() {
  artists_.Clear();
}
inline const ::std::string& Song::artists(int index) const {
  // @@protoc_insertion_point(field_get:Playsource.Song.artists)
  return artists_.Get(index);
}
inline ::std::string* Song::mutable_artists(int index) {
  // @@protoc_insertion_point(field_mutable:Playsource.Song.artists)
  return artists_.Mutable(index);
}
inline void Song::set_artists(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:Playsource.Song.artists)
  artists_.Mutable(index)->assign(value);
}
inline void Song::set_artists(int index, const char* value) {
  artists_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:Playsource.Song.artists)
}
inline void Song::set_artists(int index, const char* value, size_t size) {
  artists_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:Playsource.Song.artists)
}
inline ::std::string* Song::add_artists() {
  return artists_.Add();
}
inline void Song::add_artists(const ::std::string& value) {
  artists_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:Playsource.Song.artists)
}
inline void Song::add_artists(const char* value) {
  artists_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:Playsource.Song.artists)
}
inline void Song::add_artists(const char* value, size_t size) {
  artists_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:Playsource.Song.artists)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
Song::artists() const {
  // @@protoc_insertion_point(field_list:Playsource.Song.artists)
  return artists_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
Song::mutable_artists() {
  // @@protoc_insertion_point(field_mutable_list:Playsource.Song.artists)
  return &artists_;
}

// -------------------------------------------------------------------

// QueueSongRequest

// optional .Playsource.Song song = 1;
inline bool QueueSongRequest::has_song() const {
  return !_is_default_instance_ && song_ != NULL;
}
inline void QueueSongRequest::clear_song() {
  if (GetArenaNoVirtual() == NULL && song_ != NULL) delete song_;
  song_ = NULL;
}
inline const ::Playsource::Song& QueueSongRequest::song() const {
  // @@protoc_insertion_point(field_get:Playsource.QueueSongRequest.song)
  return song_ != NULL ? *song_ : *default_instance_->song_;
}
inline ::Playsource::Song* QueueSongRequest::mutable_song() {
  
  if (song_ == NULL) {
    song_ = new ::Playsource::Song;
  }
  // @@protoc_insertion_point(field_mutable:Playsource.QueueSongRequest.song)
  return song_;
}
inline ::Playsource::Song* QueueSongRequest::release_song() {
  
  ::Playsource::Song* temp = song_;
  song_ = NULL;
  return temp;
}
inline void QueueSongRequest::set_allocated_song(::Playsource::Song* song) {
  delete song_;
  song_ = song;
  if (song) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:Playsource.QueueSongRequest.song)
}

// -------------------------------------------------------------------

// QueueSongResponse

// optional int32 song_id = 1;
inline void QueueSongResponse::clear_song_id() {
  song_id_ = 0;
}
inline ::google::protobuf::int32 QueueSongResponse::song_id() const {
  // @@protoc_insertion_point(field_get:Playsource.QueueSongResponse.song_id)
  return song_id_;
}
inline void QueueSongResponse::set_song_id(::google::protobuf::int32 value) {
  
  song_id_ = value;
  // @@protoc_insertion_point(field_set:Playsource.QueueSongResponse.song_id)
}

// optional bool queued = 2;
inline void QueueSongResponse::clear_queued() {
  queued_ = false;
}
inline bool QueueSongResponse::queued() const {
  // @@protoc_insertion_point(field_get:Playsource.QueueSongResponse.queued)
  return queued_;
}
inline void QueueSongResponse::set_queued(bool value) {
  
  queued_ = value;
  // @@protoc_insertion_point(field_set:Playsource.QueueSongResponse.queued)
}

// optional bool found = 3;
inline void QueueSongResponse::clear_found() {
  found_ = false;
}
inline bool QueueSongResponse::found() const {
  // @@protoc_insertion_point(field_get:Playsource.QueueSongResponse.found)
  return found_;
}
inline void QueueSongResponse::set_found(bool value) {
  
  found_ = value;
  // @@protoc_insertion_point(field_set:Playsource.QueueSongResponse.found)
}

// optional bool finished = 4;
inline void QueueSongResponse::clear_finished() {
  finished_ = false;
}
inline bool QueueSongResponse::finished() const {
  // @@protoc_insertion_point(field_get:Playsource.QueueSongResponse.finished)
  return finished_;
}
inline void QueueSongResponse::set_finished(bool value) {
  
  finished_ = value;
  // @@protoc_insertion_point(field_set:Playsource.QueueSongResponse.finished)
}

// -------------------------------------------------------------------

// SkipSongRequest

// -------------------------------------------------------------------

// SkipSongResponse

// -------------------------------------------------------------------

// GetPlayingRequest

// -------------------------------------------------------------------

// GetPlayingResponse

// optional .Playsource.Song song = 1;
inline bool GetPlayingResponse::has_song() const {
  return !_is_default_instance_ && song_ != NULL;
}
inline void GetPlayingResponse::clear_song() {
  if (GetArenaNoVirtual() == NULL && song_ != NULL) delete song_;
  song_ = NULL;
}
inline const ::Playsource::Song& GetPlayingResponse::song() const {
  // @@protoc_insertion_point(field_get:Playsource.GetPlayingResponse.song)
  return song_ != NULL ? *song_ : *default_instance_->song_;
}
inline ::Playsource::Song* GetPlayingResponse::mutable_song() {
  
  if (song_ == NULL) {
    song_ = new ::Playsource::Song;
  }
  // @@protoc_insertion_point(field_mutable:Playsource.GetPlayingResponse.song)
  return song_;
}
inline ::Playsource::Song* GetPlayingResponse::release_song() {
  
  ::Playsource::Song* temp = song_;
  song_ = NULL;
  return temp;
}
inline void GetPlayingResponse::set_allocated_song(::Playsource::Song* song) {
  delete song_;
  song_ = song;
  if (song) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:Playsource.GetPlayingResponse.song)
}

// -------------------------------------------------------------------

// GetPlayHistoryRequest

// -------------------------------------------------------------------

// GetPlayHistoryResponse

// optional .Playsource.Song song = 1;
inline bool GetPlayHistoryResponse::has_song() const {
  return !_is_default_instance_ && song_ != NULL;
}
inline void GetPlayHistoryResponse::clear_song() {
  if (GetArenaNoVirtual() == NULL && song_ != NULL) delete song_;
  song_ = NULL;
}
inline const ::Playsource::Song& GetPlayHistoryResponse::song() const {
  // @@protoc_insertion_point(field_get:Playsource.GetPlayHistoryResponse.song)
  return song_ != NULL ? *song_ : *default_instance_->song_;
}
inline ::Playsource::Song* GetPlayHistoryResponse::mutable_song() {
  
  if (song_ == NULL) {
    song_ = new ::Playsource::Song;
  }
  // @@protoc_insertion_point(field_mutable:Playsource.GetPlayHistoryResponse.song)
  return song_;
}
inline ::Playsource::Song* GetPlayHistoryResponse::release_song() {
  
  ::Playsource::Song* temp = song_;
  song_ = NULL;
  return temp;
}
inline void GetPlayHistoryResponse::set_allocated_song(::Playsource::Song* song) {
  delete song_;
  song_ = song;
  if (song) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:Playsource.GetPlayHistoryResponse.song)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace Playsource

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_proto_2fplaysource_5fservice_2eproto__INCLUDED
