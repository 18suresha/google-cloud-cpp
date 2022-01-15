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
// source: google/cloud/orchestration/airflow/service/v1/environments.proto

#include "google/cloud/composer/internal/environments_stub.h"
#include "google/cloud/grpc_error_delegate.h"
#include "google/cloud/status_or.h"
#include <google/cloud/orchestration/airflow/service/v1/environments.grpc.pb.h>
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace composer_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

EnvironmentsStub::~EnvironmentsStub() = default;

future<StatusOr<google::longrunning::Operation>>
DefaultEnvironmentsStub::AsyncCreateEnvironment(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::orchestration::airflow::service::v1::
        CreateEnvironmentRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::cloud::orchestration::airflow::service::v1::
                 CreateEnvironmentRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncCreateEnvironment(context, request, cq);
      },
      request, std::move(context));
}

StatusOr<google::cloud::orchestration::airflow::service::v1::Environment>
DefaultEnvironmentsStub::GetEnvironment(
    grpc::ClientContext& client_context,
    google::cloud::orchestration::airflow::service::v1::
        GetEnvironmentRequest const& request) {
  google::cloud::orchestration::airflow::service::v1::Environment response;
  auto status = grpc_stub_->GetEnvironment(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::cloud::orchestration::airflow::service::v1::
             ListEnvironmentsResponse>
DefaultEnvironmentsStub::ListEnvironments(
    grpc::ClientContext& client_context,
    google::cloud::orchestration::airflow::service::v1::
        ListEnvironmentsRequest const& request) {
  google::cloud::orchestration::airflow::service::v1::ListEnvironmentsResponse
      response;
  auto status =
      grpc_stub_->ListEnvironments(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

future<StatusOr<google::longrunning::Operation>>
DefaultEnvironmentsStub::AsyncUpdateEnvironment(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::orchestration::airflow::service::v1::
        UpdateEnvironmentRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::cloud::orchestration::airflow::service::v1::
                 UpdateEnvironmentRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncUpdateEnvironment(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultEnvironmentsStub::AsyncDeleteEnvironment(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::orchestration::airflow::service::v1::
        DeleteEnvironmentRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::cloud::orchestration::airflow::service::v1::
                 DeleteEnvironmentRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncDeleteEnvironment(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultEnvironmentsStub::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::longrunning::GetOperationRequest const& request,
             grpc::CompletionQueue* cq) {
        return operations_->AsyncGetOperation(context, request, cq);
      },
      request, std::move(context));
}

future<Status> DefaultEnvironmentsStub::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  return cq
      .MakeUnaryRpc(
          [this](grpc::ClientContext* context,
                 google::longrunning::CancelOperationRequest const& request,
                 grpc::CompletionQueue* cq) {
            return operations_->AsyncCancelOperation(context, request, cq);
          },
          request, std::move(context))
      .then([](future<StatusOr<google::protobuf::Empty>> f) {
        return f.get().status();
      });
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace composer_internal
}  // namespace cloud
}  // namespace google