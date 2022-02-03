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
// source: google/cloud/osconfig/agentendpoint/v1/agentendpoint.proto

#include "google/cloud/osconfig/agent_endpoint_connection.h"
#include "google/cloud/osconfig/agent_endpoint_options.h"
#include "google/cloud/osconfig/internal/agent_endpoint_connection_impl.h"
#include "google/cloud/osconfig/internal/agent_endpoint_option_defaults.h"
#include "google/cloud/osconfig/internal/agent_endpoint_stub_factory.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/resumable_streaming_read_rpc.h"
#include <memory>

namespace google {
namespace cloud {
namespace osconfig {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

AgentEndpointServiceConnection::~AgentEndpointServiceConnection() = default;

StreamRange<
    google::cloud::osconfig::agentendpoint::v1::ReceiveTaskNotificationResponse>
AgentEndpointServiceConnection::ReceiveTaskNotification(
    google::cloud::osconfig::agentendpoint::v1::
        ReceiveTaskNotificationRequest const&) {
  return google::cloud::internal::MakeStreamRange<
      google::cloud::osconfig::agentendpoint::v1::
          ReceiveTaskNotificationResponse>(
      []() -> absl::variant<Status, google::cloud::osconfig::agentendpoint::v1::
                                        ReceiveTaskNotificationResponse> {
        return Status(StatusCode::kUnimplemented, "not implemented");
      });
}

StatusOr<google::cloud::osconfig::agentendpoint::v1::StartNextTaskResponse>
AgentEndpointServiceConnection::StartNextTask(
    google::cloud::osconfig::agentendpoint::v1::StartNextTaskRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::osconfig::agentendpoint::v1::ReportTaskProgressResponse>
AgentEndpointServiceConnection::ReportTaskProgress(
    google::cloud::osconfig::agentendpoint::v1::
        ReportTaskProgressRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::osconfig::agentendpoint::v1::ReportTaskCompleteResponse>
AgentEndpointServiceConnection::ReportTaskComplete(
    google::cloud::osconfig::agentendpoint::v1::
        ReportTaskCompleteRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::osconfig::agentendpoint::v1::RegisterAgentResponse>
AgentEndpointServiceConnection::RegisterAgent(
    google::cloud::osconfig::agentendpoint::v1::RegisterAgentRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::osconfig::agentendpoint::v1::ReportInventoryResponse>
AgentEndpointServiceConnection::ReportInventory(
    google::cloud::osconfig::agentendpoint::v1::ReportInventoryRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

std::shared_ptr<AgentEndpointServiceConnection>
MakeAgentEndpointServiceConnection(Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 AgentEndpointServicePolicyOptionList>(
      options, __func__);
  options =
      osconfig_internal::AgentEndpointServiceDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = osconfig_internal::CreateDefaultAgentEndpointServiceStub(
      background->cq(), options);
  return std::make_shared<
      osconfig_internal::AgentEndpointServiceConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace osconfig
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace osconfig_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<osconfig::AgentEndpointServiceConnection>
MakeAgentEndpointServiceConnection(
    std::shared_ptr<AgentEndpointServiceStub> stub, Options options) {
  options = AgentEndpointServiceDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  return std::make_shared<
      osconfig_internal::AgentEndpointServiceConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace osconfig_internal
}  // namespace cloud
}  // namespace google