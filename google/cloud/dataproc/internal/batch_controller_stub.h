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
// source: google/cloud/dataproc/v1/batches.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAPROC_INTERNAL_BATCH_CONTROLLER_STUB_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAPROC_INTERNAL_BATCH_CONTROLLER_STUB_H

#include "google/cloud/completion_queue.h"
#include "google/cloud/future.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/cloud/dataproc/v1/batches.grpc.pb.h>
#include <google/cloud/dataproc/v1/operations.pb.h>
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dataproc_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class BatchControllerStub {
 public:
  virtual ~BatchControllerStub() = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncCreateBatch(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::dataproc::v1::CreateBatchRequest const& request) = 0;

  virtual StatusOr<google::cloud::dataproc::v1::Batch> GetBatch(
      grpc::ClientContext& context,
      google::cloud::dataproc::v1::GetBatchRequest const& request) = 0;

  virtual StatusOr<google::cloud::dataproc::v1::ListBatchesResponse>
  ListBatches(
      grpc::ClientContext& context,
      google::cloud::dataproc::v1::ListBatchesRequest const& request) = 0;

  virtual Status DeleteBatch(
      grpc::ClientContext& context,
      google::cloud::dataproc::v1::DeleteBatchRequest const& request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::longrunning::GetOperationRequest const& request) = 0;

  virtual future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::longrunning::CancelOperationRequest const& request) = 0;
};

class DefaultBatchControllerStub : public BatchControllerStub {
 public:
  DefaultBatchControllerStub(
      std::unique_ptr<
          google::cloud::dataproc::v1::BatchController::StubInterface>
          grpc_stub,
      std::unique_ptr<google::longrunning::Operations::StubInterface>
          operations)
      : grpc_stub_(std::move(grpc_stub)), operations_(std::move(operations)) {}

  future<StatusOr<google::longrunning::Operation>> AsyncCreateBatch(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::dataproc::v1::CreateBatchRequest const& request) override;

  StatusOr<google::cloud::dataproc::v1::Batch> GetBatch(
      grpc::ClientContext& client_context,
      google::cloud::dataproc::v1::GetBatchRequest const& request) override;

  StatusOr<google::cloud::dataproc::v1::ListBatchesResponse> ListBatches(
      grpc::ClientContext& client_context,
      google::cloud::dataproc::v1::ListBatchesRequest const& request) override;

  Status DeleteBatch(
      grpc::ClientContext& client_context,
      google::cloud::dataproc::v1::DeleteBatchRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  std::unique_ptr<google::cloud::dataproc::v1::BatchController::StubInterface>
      grpc_stub_;
  std::unique_ptr<google::longrunning::Operations::StubInterface> operations_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dataproc_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAPROC_INTERNAL_BATCH_CONTROLLER_STUB_H