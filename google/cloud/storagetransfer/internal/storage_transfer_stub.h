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
// source: google/storagetransfer/v1/transfer.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_STORAGETRANSFER_INTERNAL_STORAGE_TRANSFER_STUB_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_STORAGETRANSFER_INTERNAL_STORAGE_TRANSFER_STUB_H

#include "google/cloud/completion_queue.h"
#include "google/cloud/future.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <google/storagetransfer/v1/transfer.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace storagetransfer_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class StorageTransferServiceStub {
 public:
  virtual ~StorageTransferServiceStub() = 0;

  virtual StatusOr<google::storagetransfer::v1::GoogleServiceAccount>
  GetGoogleServiceAccount(
      grpc::ClientContext& context,
      google::storagetransfer::v1::GetGoogleServiceAccountRequest const&
          request) = 0;

  virtual StatusOr<google::storagetransfer::v1::TransferJob> CreateTransferJob(
      grpc::ClientContext& context,
      google::storagetransfer::v1::CreateTransferJobRequest const& request) = 0;

  virtual StatusOr<google::storagetransfer::v1::TransferJob> UpdateTransferJob(
      grpc::ClientContext& context,
      google::storagetransfer::v1::UpdateTransferJobRequest const& request) = 0;

  virtual StatusOr<google::storagetransfer::v1::TransferJob> GetTransferJob(
      grpc::ClientContext& context,
      google::storagetransfer::v1::GetTransferJobRequest const& request) = 0;

  virtual StatusOr<google::storagetransfer::v1::ListTransferJobsResponse>
  ListTransferJobs(
      grpc::ClientContext& context,
      google::storagetransfer::v1::ListTransferJobsRequest const& request) = 0;

  virtual Status PauseTransferOperation(
      grpc::ClientContext& context,
      google::storagetransfer::v1::PauseTransferOperationRequest const&
          request) = 0;

  virtual Status ResumeTransferOperation(
      grpc::ClientContext& context,
      google::storagetransfer::v1::ResumeTransferOperationRequest const&
          request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncRunTransferJob(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::storagetransfer::v1::RunTransferJobRequest const& request) = 0;

  virtual StatusOr<google::storagetransfer::v1::AgentPool> CreateAgentPool(
      grpc::ClientContext& context,
      google::storagetransfer::v1::CreateAgentPoolRequest const& request) = 0;

  virtual StatusOr<google::storagetransfer::v1::AgentPool> UpdateAgentPool(
      grpc::ClientContext& context,
      google::storagetransfer::v1::UpdateAgentPoolRequest const& request) = 0;

  virtual StatusOr<google::storagetransfer::v1::AgentPool> GetAgentPool(
      grpc::ClientContext& context,
      google::storagetransfer::v1::GetAgentPoolRequest const& request) = 0;

  virtual StatusOr<google::storagetransfer::v1::ListAgentPoolsResponse>
  ListAgentPools(
      grpc::ClientContext& context,
      google::storagetransfer::v1::ListAgentPoolsRequest const& request) = 0;

  virtual Status DeleteAgentPool(
      grpc::ClientContext& context,
      google::storagetransfer::v1::DeleteAgentPoolRequest const& request) = 0;

  virtual future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::longrunning::GetOperationRequest const& request) = 0;

  virtual future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::longrunning::CancelOperationRequest const& request) = 0;
};

class DefaultStorageTransferServiceStub : public StorageTransferServiceStub {
 public:
  DefaultStorageTransferServiceStub(
      std::unique_ptr<
          google::storagetransfer::v1::StorageTransferService::StubInterface>
          grpc_stub,
      std::unique_ptr<google::longrunning::Operations::StubInterface>
          operations)
      : grpc_stub_(std::move(grpc_stub)), operations_(std::move(operations)) {}

  StatusOr<google::storagetransfer::v1::GoogleServiceAccount>
  GetGoogleServiceAccount(
      grpc::ClientContext& client_context,
      google::storagetransfer::v1::GetGoogleServiceAccountRequest const&
          request) override;

  StatusOr<google::storagetransfer::v1::TransferJob> CreateTransferJob(
      grpc::ClientContext& client_context,
      google::storagetransfer::v1::CreateTransferJobRequest const& request)
      override;

  StatusOr<google::storagetransfer::v1::TransferJob> UpdateTransferJob(
      grpc::ClientContext& client_context,
      google::storagetransfer::v1::UpdateTransferJobRequest const& request)
      override;

  StatusOr<google::storagetransfer::v1::TransferJob> GetTransferJob(
      grpc::ClientContext& client_context,
      google::storagetransfer::v1::GetTransferJobRequest const& request)
      override;

  StatusOr<google::storagetransfer::v1::ListTransferJobsResponse>
  ListTransferJobs(grpc::ClientContext& client_context,
                   google::storagetransfer::v1::ListTransferJobsRequest const&
                       request) override;

  Status PauseTransferOperation(
      grpc::ClientContext& client_context,
      google::storagetransfer::v1::PauseTransferOperationRequest const& request)
      override;

  Status ResumeTransferOperation(
      grpc::ClientContext& client_context,
      google::storagetransfer::v1::ResumeTransferOperationRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncRunTransferJob(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::storagetransfer::v1::RunTransferJobRequest const& request)
      override;

  StatusOr<google::storagetransfer::v1::AgentPool> CreateAgentPool(
      grpc::ClientContext& client_context,
      google::storagetransfer::v1::CreateAgentPoolRequest const& request)
      override;

  StatusOr<google::storagetransfer::v1::AgentPool> UpdateAgentPool(
      grpc::ClientContext& client_context,
      google::storagetransfer::v1::UpdateAgentPoolRequest const& request)
      override;

  StatusOr<google::storagetransfer::v1::AgentPool> GetAgentPool(
      grpc::ClientContext& client_context,
      google::storagetransfer::v1::GetAgentPoolRequest const& request) override;

  StatusOr<google::storagetransfer::v1::ListAgentPoolsResponse> ListAgentPools(
      grpc::ClientContext& client_context,
      google::storagetransfer::v1::ListAgentPoolsRequest const& request)
      override;

  Status DeleteAgentPool(
      grpc::ClientContext& client_context,
      google::storagetransfer::v1::DeleteAgentPoolRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  std::unique_ptr<
      google::storagetransfer::v1::StorageTransferService::StubInterface>
      grpc_stub_;
  std::unique_ptr<google::longrunning::Operations::StubInterface> operations_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace storagetransfer_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_STORAGETRANSFER_INTERNAL_STORAGE_TRANSFER_STUB_H
