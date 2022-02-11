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
// source: google/cloud/bigquery/datatransfer/v1/datatransfer.proto

#include "google/cloud/bigquery/internal/data_transfer_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/bigquery/datatransfer/v1/datatransfer.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

DataTransferServiceLogging::DataTransferServiceLogging(
    std::shared_ptr<DataTransferServiceStub> child,
    TracingOptions tracing_options, std::set<std::string> components)
    : child_(std::move(child)),
      tracing_options_(std::move(tracing_options)),
      components_(std::move(components)) {}

StatusOr<google::cloud::bigquery::datatransfer::v1::DataSource>
DataTransferServiceLogging::GetDataSource(
    grpc::ClientContext& context,
    google::cloud::bigquery::datatransfer::v1::GetDataSourceRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::bigquery::datatransfer::v1::GetDataSourceRequest const&
              request) { return child_->GetDataSource(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::datatransfer::v1::ListDataSourcesResponse>
DataTransferServiceLogging::ListDataSources(
    grpc::ClientContext& context,
    google::cloud::bigquery::datatransfer::v1::ListDataSourcesRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::datatransfer::v1::
                 ListDataSourcesRequest const& request) {
        return child_->ListDataSources(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::datatransfer::v1::TransferConfig>
DataTransferServiceLogging::CreateTransferConfig(
    grpc::ClientContext& context,
    google::cloud::bigquery::datatransfer::v1::
        CreateTransferConfigRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::datatransfer::v1::
                 CreateTransferConfigRequest const& request) {
        return child_->CreateTransferConfig(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::datatransfer::v1::TransferConfig>
DataTransferServiceLogging::UpdateTransferConfig(
    grpc::ClientContext& context,
    google::cloud::bigquery::datatransfer::v1::
        UpdateTransferConfigRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::datatransfer::v1::
                 UpdateTransferConfigRequest const& request) {
        return child_->UpdateTransferConfig(context, request);
      },
      context, request, __func__, tracing_options_);
}

Status DataTransferServiceLogging::DeleteTransferConfig(
    grpc::ClientContext& context,
    google::cloud::bigquery::datatransfer::v1::
        DeleteTransferConfigRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::datatransfer::v1::
                 DeleteTransferConfigRequest const& request) {
        return child_->DeleteTransferConfig(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::datatransfer::v1::TransferConfig>
DataTransferServiceLogging::GetTransferConfig(
    grpc::ClientContext& context,
    google::cloud::bigquery::datatransfer::v1::GetTransferConfigRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::datatransfer::v1::
                 GetTransferConfigRequest const& request) {
        return child_->GetTransferConfig(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::datatransfer::v1::ListTransferConfigsResponse>
DataTransferServiceLogging::ListTransferConfigs(
    grpc::ClientContext& context,
    google::cloud::bigquery::datatransfer::v1::ListTransferConfigsRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::datatransfer::v1::
                 ListTransferConfigsRequest const& request) {
        return child_->ListTransferConfigs(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<
    google::cloud::bigquery::datatransfer::v1::ScheduleTransferRunsResponse>
DataTransferServiceLogging::ScheduleTransferRuns(
    grpc::ClientContext& context,
    google::cloud::bigquery::datatransfer::v1::
        ScheduleTransferRunsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::datatransfer::v1::
                 ScheduleTransferRunsRequest const& request) {
        return child_->ScheduleTransferRuns(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<
    google::cloud::bigquery::datatransfer::v1::StartManualTransferRunsResponse>
DataTransferServiceLogging::StartManualTransferRuns(
    grpc::ClientContext& context,
    google::cloud::bigquery::datatransfer::v1::
        StartManualTransferRunsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::datatransfer::v1::
                 StartManualTransferRunsRequest const& request) {
        return child_->StartManualTransferRuns(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::datatransfer::v1::TransferRun>
DataTransferServiceLogging::GetTransferRun(
    grpc::ClientContext& context,
    google::cloud::bigquery::datatransfer::v1::GetTransferRunRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::datatransfer::v1::
                 GetTransferRunRequest const& request) {
        return child_->GetTransferRun(context, request);
      },
      context, request, __func__, tracing_options_);
}

Status DataTransferServiceLogging::DeleteTransferRun(
    grpc::ClientContext& context,
    google::cloud::bigquery::datatransfer::v1::DeleteTransferRunRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::datatransfer::v1::
                 DeleteTransferRunRequest const& request) {
        return child_->DeleteTransferRun(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::datatransfer::v1::ListTransferRunsResponse>
DataTransferServiceLogging::ListTransferRuns(
    grpc::ClientContext& context,
    google::cloud::bigquery::datatransfer::v1::ListTransferRunsRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::datatransfer::v1::
                 ListTransferRunsRequest const& request) {
        return child_->ListTransferRuns(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::datatransfer::v1::ListTransferLogsResponse>
DataTransferServiceLogging::ListTransferLogs(
    grpc::ClientContext& context,
    google::cloud::bigquery::datatransfer::v1::ListTransferLogsRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::datatransfer::v1::
                 ListTransferLogsRequest const& request) {
        return child_->ListTransferLogs(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::datatransfer::v1::CheckValidCredsResponse>
DataTransferServiceLogging::CheckValidCreds(
    grpc::ClientContext& context,
    google::cloud::bigquery::datatransfer::v1::CheckValidCredsRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::datatransfer::v1::
                 CheckValidCredsRequest const& request) {
        return child_->CheckValidCreds(context, request);
      },
      context, request, __func__, tracing_options_);
}

Status DataTransferServiceLogging::EnrollDataSources(
    grpc::ClientContext& context,
    google::cloud::bigquery::datatransfer::v1::EnrollDataSourcesRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::datatransfer::v1::
                 EnrollDataSourcesRequest const& request) {
        return child_->EnrollDataSources(context, request);
      },
      context, request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_internal
}  // namespace cloud
}  // namespace google