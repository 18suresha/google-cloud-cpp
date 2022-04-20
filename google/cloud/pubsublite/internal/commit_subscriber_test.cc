// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "google/cloud/pubsublite/internal/commit_subscriber_impl.h"
#include "google/cloud/pubsublite/testing/mock_async_reader_writer.h"
#include "google/cloud/pubsublite/testing/mock_resumable_async_reader_writer_stream.h"
#include "google/cloud/future.h"
#include "google/cloud/internal/absl_str_cat_quiet.h"
#include "google/cloud/status_or.h"
#include "google/cloud/testing_util/is_proto_equal.h"
#include "absl/memory/memory.h"
#include <gmock/gmock.h>
#include <chrono>
#include <memory>
#include <utility>
#include <vector>

namespace google {
namespace cloud {
namespace pubsublite_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ::google::cloud::testing_util::IsProtoEqual;
using ::testing::_;
using ::testing::ByMove;
using ::testing::ElementsAre;
using ::testing::InSequence;
using ::testing::Return;
using ::testing::StrictMock;
using ::testing::WithArg;

using google::cloud::pubsublite::v1::Cursor;
using google::cloud::pubsublite::v1::InitialCommitCursorRequest;
using google::cloud::pubsublite::v1::InitialCommitCursorResponse;
using google::cloud::pubsublite::v1::StreamingCommitCursorRequest;
using google::cloud::pubsublite::v1::StreamingCommitCursorResponse;

using ::google::cloud::pubsublite_testing::MockAsyncReaderWriter;
using ::google::cloud::pubsublite_testing::MockResumableAsyncReaderWriter;

using AsyncReaderWriter = MockAsyncReaderWriter<StreamingCommitCursorRequest,
                                                StreamingCommitCursorResponse>;

using AsyncReadWriteStreamReturnType =
    std::unique_ptr<AsyncStreamingReadWriteRpc<StreamingCommitCursorRequest,
                                               StreamingCommitCursorResponse>>;

using ResumableAsyncReadWriteStream =
    std::unique_ptr<ResumableAsyncStreamingReadWriteRpc<
        StreamingCommitCursorRequest, StreamingCommitCursorResponse>>;

StreamingCommitCursorRequest GetInitializerCommitRequest() {
  StreamingCommitCursorRequest request;
  *request.mutable_initial() = InitialCommitCursorRequest::default_instance();
  return request;
}

StreamingCommitCursorResponse GetInitializerCommitResponse() {
  StreamingCommitCursorResponse response;
  *response.mutable_initial() = InitialCommitCursorResponse::default_instance();
  return response;
}

Cursor GetCursor(std::int64_t offset) {
  Cursor c;
  c.set_offset(offset);
  return c;
}

StreamingCommitCursorRequest GetCommitRequestFromCursor(Cursor& c) {
  StreamingCommitCursorRequest request;
  *request.mutable_commit()->mutable_cursor() = c;
  return request;
}

StreamingCommitCursorResponse GetCommitResponse(std::int64_t num_acks) {
  StreamingCommitCursorResponse response;
  response.mutable_commit()->set_acknowledged_commits(num_acks);
  return response;
}

class CommitSubscriberTest : public ::testing::Test {
 protected:
  CommitSubscriberTest()
      : resumable_stream_ref_{*(
            new StrictMock<MockResumableAsyncReaderWriter<
                StreamingCommitCursorRequest, StreamingCommitCursorResponse>>)},
        subscriber_{[&](StreamInitializer<StreamingCommitCursorRequest,
                                          StreamingCommitCursorResponse>
                            initializer) {
                      // as this is a unit test, we mock the resumable stream
                      // behavior this enables the test suite to control when
                      // underlying streams are initialized
                      initializer_ = std::move(initializer);
                      return absl::WrapUnique(&resumable_stream_ref_);
                    },
                    InitialCommitCursorRequest::default_instance()} {}

  StreamInitializer<StreamingCommitCursorRequest, StreamingCommitCursorResponse>
      initializer_;
  // the reference remains valid because the resumable stream object is
  // never destroyed before the publisher goes out of scope at the end of
  // the test case
  StrictMock<MockResumableAsyncReaderWriter<StreamingCommitCursorRequest,
                                            StreamingCommitCursorResponse>>&
      resumable_stream_ref_;
  CommitSubscriberImpl subscriber_;
};

TEST_F(CommitSubscriberTest, StartNotCalled) {}

TEST_F(CommitSubscriberTest, BasicInitialization) {
  InSequence seq;

  promise<Status> start_promise;
  EXPECT_CALL(resumable_stream_ref_, Start)
      .WillOnce(Return(ByMove(start_promise.get_future())));

  promise<absl::optional<StreamingCommitCursorResponse>> read_promise_0;
  // first `Read` response is nullopt because resumable stream in retry loop
  EXPECT_CALL(resumable_stream_ref_, Read)
      .WillOnce(Return(ByMove(read_promise_0.get_future())));

  future<Status> subscriber_start_future = subscriber_.Start();

  auto underlying_stream = absl::make_unique<StrictMock<AsyncReaderWriter>>();
  EXPECT_CALL(*underlying_stream,
              Write(IsProtoEqual(GetInitializerCommitRequest()), _))
      .WillOnce(Return(ByMove(make_ready_future(true))));
  EXPECT_CALL(*underlying_stream, Read)
      .WillOnce(Return(ByMove(make_ready_future(
          absl::make_optional(GetInitializerCommitResponse())))));
  initializer_(std::move(underlying_stream));

  promise<absl::optional<StreamingCommitCursorResponse>> read_promise_1;
  EXPECT_CALL(resumable_stream_ref_, Read)
      .WillOnce(Return(ByMove(read_promise_1.get_future())));
  read_promise_0.set_value(absl::nullopt);

  promise<void> shutdown;
  EXPECT_CALL(resumable_stream_ref_, Shutdown)
      .WillOnce(Return(ByMove(shutdown.get_future())));
  auto shutdown_res = subscriber_.Shutdown();
  read_promise_1.set_value(GetInitializerCommitResponse());
  shutdown.set_value();
  start_promise.set_value(Status());

  shutdown_res.get();
  EXPECT_EQ(subscriber_start_future.get(), Status());
}

class InitializedCommitSubscriberTest : public CommitSubscriberTest {
 protected:
  InitializedCommitSubscriberTest() {
    InSequence seq;

    EXPECT_CALL(resumable_stream_ref_, Start)
        .WillOnce(Return(ByMove(start_promise_.get_future())));

    promise<absl::optional<StreamingCommitCursorResponse>> read_promise_0;
    // first `Read` response is nullopt because resumable stream in retry loop
    EXPECT_CALL(resumable_stream_ref_, Read)
        .WillOnce(Return(ByMove(read_promise_0.get_future())));

    subscriber_start_future_ = subscriber_.Start();

    EXPECT_CALL(resumable_stream_ref_,
                Write(IsProtoEqual(GetCommitRequestFromCursor(c0_))))
        .WillOnce(Return(ByMove(write_0_.get_future())));
    subscriber_.Commit(c0_);

    auto underlying_stream = absl::make_unique<StrictMock<AsyncReaderWriter>>();
    EXPECT_CALL(*underlying_stream,
                Write(IsProtoEqual(GetInitializerCommitRequest()), _))
        .WillOnce(Return(ByMove(make_ready_future(true))));
    EXPECT_CALL(*underlying_stream, Read)
        .WillOnce(Return(ByMove(make_ready_future(
            absl::make_optional(GetInitializerCommitResponse())))));
    EXPECT_CALL(*underlying_stream,
                Write(IsProtoEqual(GetCommitRequestFromCursor(c0_)), _))
        .WillOnce(Return(ByMove(make_ready_future(true))));
    initializer_(std::move(underlying_stream));

    EXPECT_CALL(resumable_stream_ref_, Read)
        .WillOnce(Return(ByMove(read_promise_1_.get_future())));
    read_promise_0.set_value(absl::nullopt);
  }

  promise<Status> start_promise_;
  future<Status> subscriber_start_future_;
  promise<absl::optional<StreamingCommitCursorResponse>> read_promise_1_;
  Cursor c0_ = GetCursor(42);
  promise<bool> write_0_;
};

TEST_F(InitializedCommitSubscriberTest, BasicInitializationAfterCommit) {
  InSequence seq;

  promise<void> shutdown;
  EXPECT_CALL(resumable_stream_ref_, Shutdown)
      .WillOnce(Return(ByMove(shutdown.get_future())));
  write_0_.set_value(false);
  auto shutdown_res = subscriber_.Shutdown();
  read_promise_1_.set_value(GetCommitResponse(1));
  shutdown.set_value();
  start_promise_.set_value(Status());

  shutdown_res.get();
  EXPECT_EQ(subscriber_start_future_.get(), Status());
}

TEST_F(InitializedCommitSubscriberTest,
       CommitThenBasicInitializationThenCommit) {
  InSequence seq;

  promise<bool> write_1;
  Cursor c1 = GetCursor(43);
  subscriber_.Commit(c1);
  EXPECT_CALL(resumable_stream_ref_,
              Write(IsProtoEqual(GetCommitRequestFromCursor(c1))))
      .WillOnce(Return(ByMove(write_1.get_future())));
  write_0_.set_value(false);
  write_1.set_value(true);

  promise<void> shutdown;
  EXPECT_CALL(resumable_stream_ref_, Shutdown)
      .WillOnce(Return(ByMove(shutdown.get_future())));

  auto shutdown_res = subscriber_.Shutdown();
  read_promise_1_.set_value(GetCommitResponse(2));
  shutdown.set_value();
  start_promise_.set_value(Status());

  shutdown_res.get();
  EXPECT_EQ(subscriber_start_future_.get(), Status());
}

TEST_F(InitializedCommitSubscriberTest,
       CommitThenBasicInitializationThenOverriddenCommit) {
  InSequence seq;

  promise<bool> write_1;
  subscriber_.Commit(GetCursor(43));
  Cursor c1 = GetCursor(100);
  subscriber_.Commit(c1);
  EXPECT_CALL(resumable_stream_ref_,
              Write(IsProtoEqual(GetCommitRequestFromCursor(c1))))
      .WillOnce(Return(ByMove(write_1.get_future())));
  write_0_.set_value(false);
  write_1.set_value(true);

  promise<void> shutdown;
  EXPECT_CALL(resumable_stream_ref_, Shutdown)
      .WillOnce(Return(ByMove(shutdown.get_future())));

  auto shutdown_res = subscriber_.Shutdown();
  read_promise_1_.set_value(GetCommitResponse(2));
  shutdown.set_value();
  start_promise_.set_value(Status());

  shutdown_res.get();
  EXPECT_EQ(subscriber_start_future_.get(), Status());
}

TEST_F(InitializedCommitSubscriberTest, MultipleReads) {
  InSequence seq;

  promise<bool> write_1;
  Cursor c1 = GetCursor(100);
  subscriber_.Commit(c1);
  EXPECT_CALL(resumable_stream_ref_,
              Write(IsProtoEqual(GetCommitRequestFromCursor(c1))))
      .WillOnce(Return(ByMove(write_1.get_future())));
  write_0_.set_value(false);
  write_1.set_value(true);

  promise<absl::optional<StreamingCommitCursorResponse>> read_promise_2;
  EXPECT_CALL(resumable_stream_ref_, Read)
      .WillOnce(Return(ByMove(read_promise_2.get_future())));
  read_promise_1_.set_value(GetCommitResponse(1));

  promise<absl::optional<StreamingCommitCursorResponse>> read_promise_3;
  EXPECT_CALL(resumable_stream_ref_, Read)
      .WillOnce(Return(ByMove(read_promise_3.get_future())));
  read_promise_2.set_value(GetCommitResponse(1));

  promise<void> shutdown;
  EXPECT_CALL(resumable_stream_ref_, Shutdown)
      .WillOnce(Return(ByMove(shutdown.get_future())));
  auto shutdown_res = subscriber_.Shutdown();
  read_promise_3.set_value(absl::nullopt);
  shutdown.set_value();
  start_promise_.set_value(Status());

  shutdown_res.get();
  EXPECT_EQ(subscriber_start_future_.get(), Status());
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsublite_internal
}  // namespace cloud
}  // namespace google
