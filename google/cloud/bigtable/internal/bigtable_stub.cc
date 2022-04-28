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
// source: google/bigtable/v2/bigtable.proto

#include "google/cloud/bigtable/internal/bigtable_stub.h"
#include "google/cloud/grpc_error_delegate.h"
#include "google/cloud/status_or.h"
#include "absl/memory/memory.h"
#include <google/bigtable/v2/bigtable.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace bigtable_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

BigtableStub::~BigtableStub() = default;

std::unique_ptr<google::cloud::internal::StreamingReadRpc<
    google::bigtable::v2::ReadRowsResponse>>
DefaultBigtableStub::ReadRows(
    std::unique_ptr<grpc::ClientContext> client_context,
    google::bigtable::v2::ReadRowsRequest const& request) {
  auto stream = grpc_stub_->ReadRows(client_context.get(), request);
  return absl::make_unique<google::cloud::internal::StreamingReadRpcImpl<
      google::bigtable::v2::ReadRowsResponse>>(std::move(client_context),
                                               std::move(stream));
}

std::unique_ptr<google::cloud::internal::StreamingReadRpc<
    google::bigtable::v2::SampleRowKeysResponse>>
DefaultBigtableStub::SampleRowKeys(
    std::unique_ptr<grpc::ClientContext> client_context,
    google::bigtable::v2::SampleRowKeysRequest const& request) {
  auto stream = grpc_stub_->SampleRowKeys(client_context.get(), request);
  return absl::make_unique<google::cloud::internal::StreamingReadRpcImpl<
      google::bigtable::v2::SampleRowKeysResponse>>(std::move(client_context),
                                                    std::move(stream));
}

StatusOr<google::bigtable::v2::MutateRowResponse>
DefaultBigtableStub::MutateRow(
    grpc::ClientContext& client_context,
    google::bigtable::v2::MutateRowRequest const& request) {
  google::bigtable::v2::MutateRowResponse response;
  auto status = grpc_stub_->MutateRow(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

std::unique_ptr<google::cloud::internal::StreamingReadRpc<
    google::bigtable::v2::MutateRowsResponse>>
DefaultBigtableStub::MutateRows(
    std::unique_ptr<grpc::ClientContext> client_context,
    google::bigtable::v2::MutateRowsRequest const& request) {
  auto stream = grpc_stub_->MutateRows(client_context.get(), request);
  return absl::make_unique<google::cloud::internal::StreamingReadRpcImpl<
      google::bigtable::v2::MutateRowsResponse>>(std::move(client_context),
                                                 std::move(stream));
}

StatusOr<google::bigtable::v2::CheckAndMutateRowResponse>
DefaultBigtableStub::CheckAndMutateRow(
    grpc::ClientContext& client_context,
    google::bigtable::v2::CheckAndMutateRowRequest const& request) {
  google::bigtable::v2::CheckAndMutateRowResponse response;
  auto status =
      grpc_stub_->CheckAndMutateRow(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::bigtable::v2::PingAndWarmResponse>
DefaultBigtableStub::PingAndWarm(
    grpc::ClientContext& client_context,
    google::bigtable::v2::PingAndWarmRequest const& request) {
  google::bigtable::v2::PingAndWarmResponse response;
  auto status = grpc_stub_->PingAndWarm(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::bigtable::v2::ReadModifyWriteRowResponse>
DefaultBigtableStub::ReadModifyWriteRow(
    grpc::ClientContext& client_context,
    google::bigtable::v2::ReadModifyWriteRowRequest const& request) {
  google::bigtable::v2::ReadModifyWriteRowResponse response;
  auto status =
      grpc_stub_->ReadModifyWriteRow(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

future<StatusOr<google::bigtable::v2::MutateRowResponse>>
DefaultBigtableStub::AsyncMutateRow(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::bigtable::v2::MutateRowRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::bigtable::v2::MutateRowRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncMutateRow(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::bigtable::v2::CheckAndMutateRowResponse>>
DefaultBigtableStub::AsyncCheckAndMutateRow(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::bigtable::v2::CheckAndMutateRowRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::bigtable::v2::CheckAndMutateRowRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncCheckAndMutateRow(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::bigtable::v2::ReadModifyWriteRowResponse>>
DefaultBigtableStub::AsyncReadModifyWriteRow(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::bigtable::v2::ReadModifyWriteRowRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::bigtable::v2::ReadModifyWriteRowRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncReadModifyWriteRow(context, request, cq);
      },
      request, std::move(context));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigtable_internal
}  // namespace cloud
}  // namespace google
