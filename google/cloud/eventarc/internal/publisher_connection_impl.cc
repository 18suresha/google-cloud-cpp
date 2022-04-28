// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/cloud/eventarc/publishing/v1/publisher.proto

#include "google/cloud/eventarc/internal/publisher_connection_impl.h"
#include "google/cloud/eventarc/internal/publisher_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace eventarc_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

PublisherConnectionImpl::PublisherConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<eventarc_internal::PublisherStub> stub, Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(
          std::move(options), eventarc_internal::PublisherDefaultOptions(
                                  PublisherConnection::options()))) {}

StatusOr<google::cloud::eventarc::publishing::v1::
             PublishChannelConnectionEventsResponse>
PublisherConnectionImpl::PublishChannelConnectionEvents(
    google::cloud::eventarc::publishing::v1::
        PublishChannelConnectionEventsRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->PublishChannelConnectionEvents(request),
      [this](grpc::ClientContext& context,
             google::cloud::eventarc::publishing::v1::
                 PublishChannelConnectionEventsRequest const& request) {
        return stub_->PublishChannelConnectionEvents(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::eventarc::publishing::v1::PublishEventsResponse>
PublisherConnectionImpl::PublishEvents(
    google::cloud::eventarc::publishing::v1::PublishEventsRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->PublishEvents(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::eventarc::publishing::v1::PublishEventsRequest const&
              request) { return stub_->PublishEvents(context, request); },
      request, __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace eventarc_internal
}  // namespace cloud
}  // namespace google
