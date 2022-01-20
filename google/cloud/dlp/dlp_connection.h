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
// source: google/privacy/dlp/v2/dlp.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DLP_DLP_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DLP_DLP_CONNECTION_H

#include "google/cloud/dlp/dlp_connection_idempotency_policy.h"
#include "google/cloud/dlp/internal/dlp_retry_traits.h"
#include "google/cloud/dlp/internal/dlp_stub.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace dlp {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using DlpServiceRetryPolicy = ::google::cloud::internal::TraitBasedRetryPolicy<
    dlp_internal::DlpServiceRetryTraits>;

using DlpServiceLimitedTimeRetryPolicy =
    ::google::cloud::internal::LimitedTimeRetryPolicy<
        dlp_internal::DlpServiceRetryTraits>;

using DlpServiceLimitedErrorCountRetryPolicy =
    ::google::cloud::internal::LimitedErrorCountRetryPolicy<
        dlp_internal::DlpServiceRetryTraits>;

class DlpServiceConnection {
 public:
  virtual ~DlpServiceConnection() = 0;

  virtual StatusOr<google::privacy::dlp::v2::InspectContentResponse>
  InspectContent(
      google::privacy::dlp::v2::InspectContentRequest const& request);

  virtual StatusOr<google::privacy::dlp::v2::RedactImageResponse> RedactImage(
      google::privacy::dlp::v2::RedactImageRequest const& request);

  virtual StatusOr<google::privacy::dlp::v2::DeidentifyContentResponse>
  DeidentifyContent(
      google::privacy::dlp::v2::DeidentifyContentRequest const& request);

  virtual StatusOr<google::privacy::dlp::v2::ReidentifyContentResponse>
  ReidentifyContent(
      google::privacy::dlp::v2::ReidentifyContentRequest const& request);

  virtual StatusOr<google::privacy::dlp::v2::ListInfoTypesResponse>
  ListInfoTypes(google::privacy::dlp::v2::ListInfoTypesRequest const& request);

  virtual StatusOr<google::privacy::dlp::v2::InspectTemplate>
  CreateInspectTemplate(
      google::privacy::dlp::v2::CreateInspectTemplateRequest const& request);

  virtual StatusOr<google::privacy::dlp::v2::InspectTemplate>
  UpdateInspectTemplate(
      google::privacy::dlp::v2::UpdateInspectTemplateRequest const& request);

  virtual StatusOr<google::privacy::dlp::v2::InspectTemplate>
  GetInspectTemplate(
      google::privacy::dlp::v2::GetInspectTemplateRequest const& request);

  virtual StreamRange<google::privacy::dlp::v2::InspectTemplate>
  ListInspectTemplates(
      google::privacy::dlp::v2::ListInspectTemplatesRequest request);

  virtual Status DeleteInspectTemplate(
      google::privacy::dlp::v2::DeleteInspectTemplateRequest const& request);

  virtual StatusOr<google::privacy::dlp::v2::DeidentifyTemplate>
  CreateDeidentifyTemplate(
      google::privacy::dlp::v2::CreateDeidentifyTemplateRequest const& request);

  virtual StatusOr<google::privacy::dlp::v2::DeidentifyTemplate>
  UpdateDeidentifyTemplate(
      google::privacy::dlp::v2::UpdateDeidentifyTemplateRequest const& request);

  virtual StatusOr<google::privacy::dlp::v2::DeidentifyTemplate>
  GetDeidentifyTemplate(
      google::privacy::dlp::v2::GetDeidentifyTemplateRequest const& request);

  virtual StreamRange<google::privacy::dlp::v2::DeidentifyTemplate>
  ListDeidentifyTemplates(
      google::privacy::dlp::v2::ListDeidentifyTemplatesRequest request);

  virtual Status DeleteDeidentifyTemplate(
      google::privacy::dlp::v2::DeleteDeidentifyTemplateRequest const& request);

  virtual StatusOr<google::privacy::dlp::v2::JobTrigger> CreateJobTrigger(
      google::privacy::dlp::v2::CreateJobTriggerRequest const& request);

  virtual StatusOr<google::privacy::dlp::v2::JobTrigger> UpdateJobTrigger(
      google::privacy::dlp::v2::UpdateJobTriggerRequest const& request);

  virtual StatusOr<google::privacy::dlp::v2::HybridInspectResponse>
  HybridInspectJobTrigger(
      google::privacy::dlp::v2::HybridInspectJobTriggerRequest const& request);

  virtual StatusOr<google::privacy::dlp::v2::JobTrigger> GetJobTrigger(
      google::privacy::dlp::v2::GetJobTriggerRequest const& request);

  virtual StreamRange<google::privacy::dlp::v2::JobTrigger> ListJobTriggers(
      google::privacy::dlp::v2::ListJobTriggersRequest request);

  virtual Status DeleteJobTrigger(
      google::privacy::dlp::v2::DeleteJobTriggerRequest const& request);

  virtual StatusOr<google::privacy::dlp::v2::DlpJob> ActivateJobTrigger(
      google::privacy::dlp::v2::ActivateJobTriggerRequest const& request);

  virtual StatusOr<google::privacy::dlp::v2::DlpJob> CreateDlpJob(
      google::privacy::dlp::v2::CreateDlpJobRequest const& request);

  virtual StreamRange<google::privacy::dlp::v2::DlpJob> ListDlpJobs(
      google::privacy::dlp::v2::ListDlpJobsRequest request);

  virtual StatusOr<google::privacy::dlp::v2::DlpJob> GetDlpJob(
      google::privacy::dlp::v2::GetDlpJobRequest const& request);

  virtual Status DeleteDlpJob(
      google::privacy::dlp::v2::DeleteDlpJobRequest const& request);

  virtual Status CancelDlpJob(
      google::privacy::dlp::v2::CancelDlpJobRequest const& request);

  virtual StatusOr<google::privacy::dlp::v2::StoredInfoType>
  CreateStoredInfoType(
      google::privacy::dlp::v2::CreateStoredInfoTypeRequest const& request);

  virtual StatusOr<google::privacy::dlp::v2::StoredInfoType>
  UpdateStoredInfoType(
      google::privacy::dlp::v2::UpdateStoredInfoTypeRequest const& request);

  virtual StatusOr<google::privacy::dlp::v2::StoredInfoType> GetStoredInfoType(
      google::privacy::dlp::v2::GetStoredInfoTypeRequest const& request);

  virtual StreamRange<google::privacy::dlp::v2::StoredInfoType>
  ListStoredInfoTypes(
      google::privacy::dlp::v2::ListStoredInfoTypesRequest request);

  virtual Status DeleteStoredInfoType(
      google::privacy::dlp::v2::DeleteStoredInfoTypeRequest const& request);

  virtual StatusOr<google::privacy::dlp::v2::HybridInspectResponse>
  HybridInspectDlpJob(
      google::privacy::dlp::v2::HybridInspectDlpJobRequest const& request);

  virtual Status FinishDlpJob(
      google::privacy::dlp::v2::FinishDlpJobRequest const& request);
};

std::shared_ptr<DlpServiceConnection> MakeDlpServiceConnection(
    Options options = {});

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dlp
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace dlp_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<dlp::DlpServiceConnection> MakeDlpServiceConnection(
    std::shared_ptr<DlpServiceStub> stub, Options options);

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dlp_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DLP_DLP_CONNECTION_H