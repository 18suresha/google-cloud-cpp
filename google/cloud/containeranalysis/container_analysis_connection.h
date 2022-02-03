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
// source: google/devtools/containeranalysis/v1/containeranalysis.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CONTAINERANALYSIS_CONTAINER_ANALYSIS_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CONTAINERANALYSIS_CONTAINER_ANALYSIS_CONNECTION_H

#include "google/cloud/containeranalysis/container_analysis_connection_idempotency_policy.h"
#include "google/cloud/containeranalysis/internal/container_analysis_retry_traits.h"
#include "google/cloud/containeranalysis/internal/container_analysis_stub.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace containeranalysis {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ContainerAnalysisRetryPolicy =
    ::google::cloud::internal::TraitBasedRetryPolicy<
        containeranalysis_internal::ContainerAnalysisRetryTraits>;

using ContainerAnalysisLimitedTimeRetryPolicy =
    ::google::cloud::internal::LimitedTimeRetryPolicy<
        containeranalysis_internal::ContainerAnalysisRetryTraits>;

using ContainerAnalysisLimitedErrorCountRetryPolicy =
    ::google::cloud::internal::LimitedErrorCountRetryPolicy<
        containeranalysis_internal::ContainerAnalysisRetryTraits>;

class ContainerAnalysisConnection {
 public:
  virtual ~ContainerAnalysisConnection() = 0;

  virtual Options options() { return Options{}; }

  virtual StatusOr<google::iam::v1::Policy> SetIamPolicy(
      google::iam::v1::SetIamPolicyRequest const& request);

  virtual StatusOr<google::iam::v1::Policy> GetIamPolicy(
      google::iam::v1::GetIamPolicyRequest const& request);

  virtual StatusOr<google::iam::v1::TestIamPermissionsResponse>
  TestIamPermissions(google::iam::v1::TestIamPermissionsRequest const& request);

  virtual StatusOr<
      google::devtools::containeranalysis::v1::VulnerabilityOccurrencesSummary>
  GetVulnerabilityOccurrencesSummary(
      google::devtools::containeranalysis::v1::
          GetVulnerabilityOccurrencesSummaryRequest const& request);
};

std::shared_ptr<ContainerAnalysisConnection> MakeContainerAnalysisConnection(
    Options options = {});

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace containeranalysis
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace containeranalysis_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<containeranalysis::ContainerAnalysisConnection>
MakeContainerAnalysisConnection(std::shared_ptr<ContainerAnalysisStub> stub,
                                Options options);

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace containeranalysis_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CONTAINERANALYSIS_CONTAINER_ANALYSIS_CONNECTION_H