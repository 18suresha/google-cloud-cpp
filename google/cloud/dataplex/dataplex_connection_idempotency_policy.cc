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
// source: google/cloud/dataplex/v1/service.proto

#include "google/cloud/dataplex/dataplex_connection_idempotency_policy.h"
#include "absl/memory/memory.h"
#include <memory>

namespace google {
namespace cloud {
namespace dataplex {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ::google::cloud::Idempotency;

DataplexServiceConnectionIdempotencyPolicy::
    ~DataplexServiceConnectionIdempotencyPolicy() = default;

namespace {
class DefaultDataplexServiceConnectionIdempotencyPolicy
    : public DataplexServiceConnectionIdempotencyPolicy {
 public:
  ~DefaultDataplexServiceConnectionIdempotencyPolicy() override = default;

  /// Create a new copy of this object.
  std::unique_ptr<DataplexServiceConnectionIdempotencyPolicy> clone()
      const override {
    return absl::make_unique<DefaultDataplexServiceConnectionIdempotencyPolicy>(
        *this);
  }

  Idempotency CreateLake(
      google::cloud::dataplex::v1::CreateLakeRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency UpdateLake(
      google::cloud::dataplex::v1::UpdateLakeRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency DeleteLake(
      google::cloud::dataplex::v1::DeleteLakeRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency ListLakes(
      google::cloud::dataplex::v1::ListLakesRequest) override {
    return Idempotency::kIdempotent;
  }

  Idempotency GetLake(
      google::cloud::dataplex::v1::GetLakeRequest const&) override {
    return Idempotency::kIdempotent;
  }

  Idempotency ListLakeActions(
      google::cloud::dataplex::v1::ListLakeActionsRequest) override {
    return Idempotency::kIdempotent;
  }

  Idempotency CreateZone(
      google::cloud::dataplex::v1::CreateZoneRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency UpdateZone(
      google::cloud::dataplex::v1::UpdateZoneRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency DeleteZone(
      google::cloud::dataplex::v1::DeleteZoneRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency ListZones(
      google::cloud::dataplex::v1::ListZonesRequest) override {
    return Idempotency::kIdempotent;
  }

  Idempotency GetZone(
      google::cloud::dataplex::v1::GetZoneRequest const&) override {
    return Idempotency::kIdempotent;
  }

  Idempotency ListZoneActions(
      google::cloud::dataplex::v1::ListZoneActionsRequest) override {
    return Idempotency::kIdempotent;
  }

  Idempotency CreateAsset(
      google::cloud::dataplex::v1::CreateAssetRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency UpdateAsset(
      google::cloud::dataplex::v1::UpdateAssetRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency DeleteAsset(
      google::cloud::dataplex::v1::DeleteAssetRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency ListAssets(
      google::cloud::dataplex::v1::ListAssetsRequest) override {
    return Idempotency::kIdempotent;
  }

  Idempotency GetAsset(
      google::cloud::dataplex::v1::GetAssetRequest const&) override {
    return Idempotency::kIdempotent;
  }

  Idempotency ListAssetActions(
      google::cloud::dataplex::v1::ListAssetActionsRequest) override {
    return Idempotency::kIdempotent;
  }

  Idempotency CreateTask(
      google::cloud::dataplex::v1::CreateTaskRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency UpdateTask(
      google::cloud::dataplex::v1::UpdateTaskRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency DeleteTask(
      google::cloud::dataplex::v1::DeleteTaskRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency ListTasks(
      google::cloud::dataplex::v1::ListTasksRequest) override {
    return Idempotency::kIdempotent;
  }

  Idempotency GetTask(
      google::cloud::dataplex::v1::GetTaskRequest const&) override {
    return Idempotency::kIdempotent;
  }

  Idempotency ListJobs(google::cloud::dataplex::v1::ListJobsRequest) override {
    return Idempotency::kIdempotent;
  }

  Idempotency GetJob(
      google::cloud::dataplex::v1::GetJobRequest const&) override {
    return Idempotency::kIdempotent;
  }

  Idempotency CancelJob(
      google::cloud::dataplex::v1::CancelJobRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency CreateEnvironment(
      google::cloud::dataplex::v1::CreateEnvironmentRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency UpdateEnvironment(
      google::cloud::dataplex::v1::UpdateEnvironmentRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency DeleteEnvironment(
      google::cloud::dataplex::v1::DeleteEnvironmentRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency ListEnvironments(
      google::cloud::dataplex::v1::ListEnvironmentsRequest) override {
    return Idempotency::kIdempotent;
  }

  Idempotency GetEnvironment(
      google::cloud::dataplex::v1::GetEnvironmentRequest const&) override {
    return Idempotency::kIdempotent;
  }

  Idempotency ListSessions(
      google::cloud::dataplex::v1::ListSessionsRequest) override {
    return Idempotency::kIdempotent;
  }
};
}  // namespace

std::unique_ptr<DataplexServiceConnectionIdempotencyPolicy>
MakeDefaultDataplexServiceConnectionIdempotencyPolicy() {
  return absl::make_unique<DefaultDataplexServiceConnectionIdempotencyPolicy>();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dataplex
}  // namespace cloud
}  // namespace google