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

#include "google/cloud/filestore/internal/cloud_filestore_manager_auth_decorator.h"
#include <google/cloud/filestore/v1/cloud_filestore_service.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace filestore_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

CloudFilestoreManagerAuth::CloudFilestoreManagerAuth(
    std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
    std::shared_ptr<CloudFilestoreManagerStub> child)
    : auth_(std::move(auth)), child_(std::move(child)) {}

StatusOr<google::cloud::filestore::v1::ListInstancesResponse>
CloudFilestoreManagerAuth::ListInstances(
    grpc::ClientContext& context,
    google::cloud::filestore::v1::ListInstancesRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListInstances(context, request);
}

StatusOr<google::cloud::filestore::v1::Instance>
CloudFilestoreManagerAuth::GetInstance(
    grpc::ClientContext& context,
    google::cloud::filestore::v1::GetInstanceRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetInstance(context, request);
}

future<StatusOr<google::longrunning::Operation>>
CloudFilestoreManagerAuth::AsyncCreateInstance(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::filestore::v1::CreateInstanceRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncCreateInstance(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
CloudFilestoreManagerAuth::AsyncUpdateInstance(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::filestore::v1::UpdateInstanceRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncUpdateInstance(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
CloudFilestoreManagerAuth::AsyncRestoreInstance(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::filestore::v1::RestoreInstanceRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncRestoreInstance(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
CloudFilestoreManagerAuth::AsyncDeleteInstance(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::filestore::v1::DeleteInstanceRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncDeleteInstance(cq, *std::move(context), request);
      });
}

StatusOr<google::cloud::filestore::v1::ListBackupsResponse>
CloudFilestoreManagerAuth::ListBackups(
    grpc::ClientContext& context,
    google::cloud::filestore::v1::ListBackupsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListBackups(context, request);
}

StatusOr<google::cloud::filestore::v1::Backup>
CloudFilestoreManagerAuth::GetBackup(
    grpc::ClientContext& context,
    google::cloud::filestore::v1::GetBackupRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetBackup(context, request);
}

future<StatusOr<google::longrunning::Operation>>
CloudFilestoreManagerAuth::AsyncCreateBackup(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::filestore::v1::CreateBackupRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncCreateBackup(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
CloudFilestoreManagerAuth::AsyncDeleteBackup(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::filestore::v1::DeleteBackupRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncDeleteBackup(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
CloudFilestoreManagerAuth::AsyncUpdateBackup(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::filestore::v1::UpdateBackupRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncUpdateBackup(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
CloudFilestoreManagerAuth::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncGetOperation(cq, *std::move(context), request);
      });
}

future<Status> CloudFilestoreManagerAuth::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  auto child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) return make_ready_future(std::move(context).status());
        return child->AsyncCancelOperation(cq, *std::move(context), request);
      });
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace filestore_internal
}  // namespace cloud
}  // namespace google
