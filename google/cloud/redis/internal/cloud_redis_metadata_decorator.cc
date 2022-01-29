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
// source: google/cloud/redis/v1/cloud_redis.proto

#include "google/cloud/redis/internal/cloud_redis_metadata_decorator.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/status_or.h"
#include <google/cloud/redis/v1/cloud_redis.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace redis_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

CloudRedisMetadata::CloudRedisMetadata(std::shared_ptr<CloudRedisStub> child)
    : child_(std::move(child)),
      api_client_header_(
          google::cloud::internal::ApiClientHeader("generator")) {}

StatusOr<google::cloud::redis::v1::ListInstancesResponse>
CloudRedisMetadata::ListInstances(
    grpc::ClientContext& context,
    google::cloud::redis::v1::ListInstancesRequest const& request) {
  SetMetadata(context, "parent=" + request.parent());
  return child_->ListInstances(context, request);
}

StatusOr<google::cloud::redis::v1::Instance> CloudRedisMetadata::GetInstance(
    grpc::ClientContext& context,
    google::cloud::redis::v1::GetInstanceRequest const& request) {
  SetMetadata(context, "name=" + request.name());
  return child_->GetInstance(context, request);
}

future<StatusOr<google::longrunning::Operation>>
CloudRedisMetadata::AsyncCreateInstance(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::redis::v1::CreateInstanceRequest const& request) {
  SetMetadata(*context, "parent=" + request.parent());
  return child_->AsyncCreateInstance(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
CloudRedisMetadata::AsyncUpdateInstance(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::redis::v1::UpdateInstanceRequest const& request) {
  SetMetadata(*context, "instance.name=" + request.instance().name());
  return child_->AsyncUpdateInstance(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
CloudRedisMetadata::AsyncUpgradeInstance(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::redis::v1::UpgradeInstanceRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncUpgradeInstance(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
CloudRedisMetadata::AsyncImportInstance(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::redis::v1::ImportInstanceRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncImportInstance(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
CloudRedisMetadata::AsyncExportInstance(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::redis::v1::ExportInstanceRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncExportInstance(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
CloudRedisMetadata::AsyncFailoverInstance(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::redis::v1::FailoverInstanceRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncFailoverInstance(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
CloudRedisMetadata::AsyncDeleteInstance(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::redis::v1::DeleteInstanceRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncDeleteInstance(cq, std::move(context), request);
}

future<StatusOr<google::longrunning::Operation>>
CloudRedisMetadata::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncGetOperation(cq, std::move(context), request);
}

future<Status> CloudRedisMetadata::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  SetMetadata(*context, "name=" + request.name());
  return child_->AsyncCancelOperation(cq, std::move(context), request);
}

void CloudRedisMetadata::SetMetadata(grpc::ClientContext& context,
                                     std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context);
}

void CloudRedisMetadata::SetMetadata(grpc::ClientContext& context) {
  context.AddMetadata("x-goog-api-client", api_client_header_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace redis_internal
}  // namespace cloud
}  // namespace google
