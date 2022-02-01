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
// source: google/cloud/filestore/v1/cloud_filestore_service.proto

#include "google/cloud/filestore/internal/cloud_filestore_manager_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/filestore/v1/cloud_filestore_service.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace filestore_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

CloudFilestoreManagerLogging::CloudFilestoreManagerLogging(
    std::shared_ptr<CloudFilestoreManagerStub> child,
    TracingOptions tracing_options, std::set<std::string> components)
    : child_(std::move(child)),
      tracing_options_(std::move(tracing_options)),
      components_(std::move(components)) {}

StatusOr<google::cloud::filestore::v1::ListInstancesResponse>
CloudFilestoreManagerLogging::ListInstances(
    grpc::ClientContext& context,
    google::cloud::filestore::v1::ListInstancesRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::filestore::v1::ListInstancesRequest const& request) {
        return child_->ListInstances(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::filestore::v1::Instance>
CloudFilestoreManagerLogging::GetInstance(
    grpc::ClientContext& context,
    google::cloud::filestore::v1::GetInstanceRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::filestore::v1::GetInstanceRequest const& request) {
        return child_->GetInstance(context, request);
      },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
CloudFilestoreManagerLogging::AsyncCreateInstance(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::filestore::v1::CreateInstanceRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::unique_ptr<grpc::ClientContext> context,
          google::cloud::filestore::v1::CreateInstanceRequest const& request) {
        return child_->AsyncCreateInstance(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
CloudFilestoreManagerLogging::AsyncUpdateInstance(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::filestore::v1::UpdateInstanceRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::unique_ptr<grpc::ClientContext> context,
          google::cloud::filestore::v1::UpdateInstanceRequest const& request) {
        return child_->AsyncUpdateInstance(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
CloudFilestoreManagerLogging::AsyncRestoreInstance(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::filestore::v1::RestoreInstanceRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::unique_ptr<grpc::ClientContext> context,
          google::cloud::filestore::v1::RestoreInstanceRequest const& request) {
        return child_->AsyncRestoreInstance(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
CloudFilestoreManagerLogging::AsyncDeleteInstance(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::filestore::v1::DeleteInstanceRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          google::cloud::CompletionQueue& cq,
          std::unique_ptr<grpc::ClientContext> context,
          google::cloud::filestore::v1::DeleteInstanceRequest const& request) {
        return child_->AsyncDeleteInstance(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

StatusOr<google::cloud::filestore::v1::ListBackupsResponse>
CloudFilestoreManagerLogging::ListBackups(
    grpc::ClientContext& context,
    google::cloud::filestore::v1::ListBackupsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::filestore::v1::ListBackupsRequest const& request) {
        return child_->ListBackups(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::filestore::v1::Backup>
CloudFilestoreManagerLogging::GetBackup(
    grpc::ClientContext& context,
    google::cloud::filestore::v1::GetBackupRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::filestore::v1::GetBackupRequest const& request) {
        return child_->GetBackup(context, request);
      },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
CloudFilestoreManagerLogging::AsyncCreateBackup(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::filestore::v1::CreateBackupRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::filestore::v1::CreateBackupRequest const& request) {
        return child_->AsyncCreateBackup(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
CloudFilestoreManagerLogging::AsyncDeleteBackup(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::filestore::v1::DeleteBackupRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::filestore::v1::DeleteBackupRequest const& request) {
        return child_->AsyncDeleteBackup(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
CloudFilestoreManagerLogging::AsyncUpdateBackup(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::filestore::v1::UpdateBackupRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::filestore::v1::UpdateBackupRequest const& request) {
        return child_->AsyncUpdateBackup(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
CloudFilestoreManagerLogging::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return child_->AsyncGetOperation(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<Status> CloudFilestoreManagerLogging::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return child_->AsyncCancelOperation(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace filestore_internal
}  // namespace cloud
}  // namespace google
