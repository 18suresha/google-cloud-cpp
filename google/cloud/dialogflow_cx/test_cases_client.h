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
// source: google/cloud/dialogflow/cx/v3/test_case.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_TEST_CASES_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_TEST_CASES_CLIENT_H

#include "google/cloud/dialogflow_cx/test_cases_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_cx {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// Service for managing [Test Cases][google.cloud.dialogflow.cx.v3.TestCase]
/// and [Test Case Results][google.cloud.dialogflow.cx.v3.TestCaseResult].
///
/// @par Equality
///
/// Instances of this class created via copy-construction or copy-assignment
/// always compare equal. Instances created with equal
/// `std::shared_ptr<*Connection>` objects compare equal. Objects that compare
/// equal share the same underlying resources.
///
/// @par Performance
///
/// Creating a new instance of this class is a relatively expensive operation,
/// new objects establish new connections to the service. In contrast,
/// copy-construction, move-construction, and the corresponding assignment
/// operations are relatively efficient as the copies share all underlying
/// resources.
///
/// @par Thread Safety
///
/// Concurrent access to different instances of this class, even if they compare
/// equal, is guaranteed to work. Two or more threads operating on the same
/// instance of this class is not guaranteed to work. Since copy-construction
/// and move-construction is a relatively efficient operation, consider using
/// such a copy when using this class from multiple threads.
///
class TestCasesClient {
 public:
  explicit TestCasesClient(std::shared_ptr<TestCasesConnection> connection,
                           Options opts = {});
  ~TestCasesClient();

  //@{
  // @name Copy and move support
  TestCasesClient(TestCasesClient const&) = default;
  TestCasesClient& operator=(TestCasesClient const&) = default;
  TestCasesClient(TestCasesClient&&) = default;
  TestCasesClient& operator=(TestCasesClient&&) = default;
  //@}

  //@{
  // @name Equality
  friend bool operator==(TestCasesClient const& a, TestCasesClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(TestCasesClient const& a, TestCasesClient const& b) {
    return !(a == b);
  }
  //@}

  ///
  /// Fetches a list of test cases for a given agent.
  ///
  /// @param parent  Required. The agent to list all pages for.
  ///  Format: `projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>`.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::TestCase,google/cloud/dialogflow/cx/v3/test_case.proto#L200}
  ///
  /// [google.cloud.dialogflow.cx.v3.ListTestCasesRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L547}
  /// [google.cloud.dialogflow.cx.v3.TestCase]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L200}
  ///
  StreamRange<google::cloud::dialogflow::cx::v3::TestCase> ListTestCases(
      std::string const& parent, Options opts = {});

  ///
  /// Fetches a list of test cases for a given agent.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::ListTestCasesRequest,google/cloud/dialogflow/cx/v3/test_case.proto#L547}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::TestCase,google/cloud/dialogflow/cx/v3/test_case.proto#L200}
  ///
  /// [google.cloud.dialogflow.cx.v3.ListTestCasesRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L547}
  /// [google.cloud.dialogflow.cx.v3.TestCase]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L200}
  ///
  StreamRange<google::cloud::dialogflow::cx::v3::TestCase> ListTestCases(
      google::cloud::dialogflow::cx::v3::ListTestCasesRequest request,
      Options opts = {});

  ///
  /// Batch deletes test cases.
  ///
  /// @param parent  Required. The agent to delete test cases from.
  ///  Format: `projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>`.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  ///
  /// [google.cloud.dialogflow.cx.v3.BatchDeleteTestCasesRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L595}
  ///
  Status BatchDeleteTestCases(std::string const& parent, Options opts = {});

  ///
  /// Batch deletes test cases.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::BatchDeleteTestCasesRequest,google/cloud/dialogflow/cx/v3/test_case.proto#L595}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  ///
  /// [google.cloud.dialogflow.cx.v3.BatchDeleteTestCasesRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L595}
  ///
  Status BatchDeleteTestCases(
      google::cloud::dialogflow::cx::v3::BatchDeleteTestCasesRequest const&
          request,
      Options opts = {});

  ///
  /// Gets a test case.
  ///
  /// @param name  Required. The name of the testcase.
  ///  Format: `projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>/testCases/<TestCase ID>`.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::TestCase,google/cloud/dialogflow/cx/v3/test_case.proto#L200}
  ///
  /// [google.cloud.dialogflow.cx.v3.GetTestCaseRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L642}
  /// [google.cloud.dialogflow.cx.v3.TestCase]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L200}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::TestCase> GetTestCase(
      std::string const& name, Options opts = {});

  ///
  /// Gets a test case.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::GetTestCaseRequest,google/cloud/dialogflow/cx/v3/test_case.proto#L642}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::TestCase,google/cloud/dialogflow/cx/v3/test_case.proto#L200}
  ///
  /// [google.cloud.dialogflow.cx.v3.GetTestCaseRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L642}
  /// [google.cloud.dialogflow.cx.v3.TestCase]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L200}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::TestCase> GetTestCase(
      google::cloud::dialogflow::cx::v3::GetTestCaseRequest const& request,
      Options opts = {});

  ///
  /// Creates a test case for the given agent.
  ///
  /// @param parent  Required. The agent to create the test case for.
  ///  Format: `projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>`.
  /// @param test_case  Required. The test case to create.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::TestCase,google/cloud/dialogflow/cx/v3/test_case.proto#L200}
  ///
  /// [google.cloud.dialogflow.cx.v3.CreateTestCaseRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L616}
  /// [google.cloud.dialogflow.cx.v3.TestCase]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L200}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::TestCase> CreateTestCase(
      std::string const& parent,
      google::cloud::dialogflow::cx::v3::TestCase const& test_case,
      Options opts = {});

  ///
  /// Creates a test case for the given agent.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::CreateTestCaseRequest,google/cloud/dialogflow/cx/v3/test_case.proto#L616}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::TestCase,google/cloud/dialogflow/cx/v3/test_case.proto#L200}
  ///
  /// [google.cloud.dialogflow.cx.v3.CreateTestCaseRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L616}
  /// [google.cloud.dialogflow.cx.v3.TestCase]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L200}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::TestCase> CreateTestCase(
      google::cloud::dialogflow::cx::v3::CreateTestCaseRequest const& request,
      Options opts = {});

  ///
  /// Updates the specified test case.
  ///
  /// @param test_case  Required. The test case to update.
  /// @param update_mask  Required. The mask to specify which fields should be
  /// updated. The
  ///  [`creationTime`][google.cloud.dialogflow.cx.v3.TestCase.creation_time]
  ///  and
  ///  [`lastTestResult`][google.cloud.dialogflow.cx.v3.TestCase.last_test_result]
  ///  cannot be updated.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::TestCase,google/cloud/dialogflow/cx/v3/test_case.proto#L200}
  ///
  /// [google.cloud.dialogflow.cx.v3.UpdateTestCaseRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L631}
  /// [google.cloud.dialogflow.cx.v3.TestCase]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L200}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::TestCase> UpdateTestCase(
      google::cloud::dialogflow::cx::v3::TestCase const& test_case,
      google::protobuf::FieldMask const& update_mask, Options opts = {});

  ///
  /// Updates the specified test case.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::UpdateTestCaseRequest,google/cloud/dialogflow/cx/v3/test_case.proto#L631}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::TestCase,google/cloud/dialogflow/cx/v3/test_case.proto#L200}
  ///
  /// [google.cloud.dialogflow.cx.v3.UpdateTestCaseRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L631}
  /// [google.cloud.dialogflow.cx.v3.TestCase]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L200}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::TestCase> UpdateTestCase(
      google::cloud::dialogflow::cx::v3::UpdateTestCaseRequest const& request,
      Options opts = {});

  ///
  /// Kicks off a test case run.
  ///
  /// This method is a [long-running
  /// operation](https://cloud.google.com/dialogflow/cx/docs/how/long-running-operation).
  /// The returned `Operation` type has the following method-specific fields:
  ///
  /// - `metadata`:
  /// [RunTestCaseMetadata][google.cloud.dialogflow.cx.v3.RunTestCaseMetadata]
  /// - `response`:
  /// [RunTestCaseResponse][google.cloud.dialogflow.cx.v3.RunTestCaseResponse]
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::RunTestCaseRequest,google/cloud/dialogflow/cx/v3/test_case.proto#L655}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::RunTestCaseResponse,google/cloud/dialogflow/cx/v3/test_case.proto#L677}
  ///
  /// [google.cloud.dialogflow.cx.v3.RunTestCaseRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L655}
  /// [google.cloud.dialogflow.cx.v3.RunTestCaseResponse]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L677}
  ///
  future<StatusOr<google::cloud::dialogflow::cx::v3::RunTestCaseResponse>>
  RunTestCase(
      google::cloud::dialogflow::cx::v3::RunTestCaseRequest const& request,
      Options opts = {});

  ///
  /// Kicks off a batch run of test cases.
  ///
  /// This method is a [long-running
  /// operation](https://cloud.google.com/dialogflow/cx/docs/how/long-running-operation).
  /// The returned `Operation` type has the following method-specific fields:
  ///
  /// - `metadata`:
  /// [BatchRunTestCasesMetadata][google.cloud.dialogflow.cx.v3.BatchRunTestCasesMetadata]
  /// - `response`:
  /// [BatchRunTestCasesResponse][google.cloud.dialogflow.cx.v3.BatchRunTestCasesResponse]
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::BatchRunTestCasesRequest,google/cloud/dialogflow/cx/v3/test_case.proto#L689}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::BatchRunTestCasesResponse,google/cloud/dialogflow/cx/v3/test_case.proto#L720}
  ///
  /// [google.cloud.dialogflow.cx.v3.BatchRunTestCasesRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L689}
  /// [google.cloud.dialogflow.cx.v3.BatchRunTestCasesResponse]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L720}
  ///
  future<StatusOr<google::cloud::dialogflow::cx::v3::BatchRunTestCasesResponse>>
  BatchRunTestCases(
      google::cloud::dialogflow::cx::v3::BatchRunTestCasesRequest const&
          request,
      Options opts = {});

  ///
  /// Calculates the test coverage for an agent.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::CalculateCoverageRequest,google/cloud/dialogflow/cx/v3/test_case.proto#L496}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::CalculateCoverageResponse,google/cloud/dialogflow/cx/v3/test_case.proto#L526}
  ///
  /// [google.cloud.dialogflow.cx.v3.CalculateCoverageRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L496}
  /// [google.cloud.dialogflow.cx.v3.CalculateCoverageResponse]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L526}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::CalculateCoverageResponse>
  CalculateCoverage(
      google::cloud::dialogflow::cx::v3::CalculateCoverageRequest const&
          request,
      Options opts = {});

  ///
  /// Imports the test cases from a Cloud Storage bucket or a local file. It
  /// always creates new test cases and won't overwite any existing ones. The
  /// provided ID in the imported test case is neglected.
  ///
  /// This method is a [long-running
  /// operation](https://cloud.google.com/dialogflow/cx/docs/how/long-running-operation).
  /// The returned `Operation` type has the following method-specific fields:
  ///
  /// - `metadata`:
  /// [ImportTestCasesMetadata][google.cloud.dialogflow.cx.v3.ImportTestCasesMetadata]
  /// - `response`:
  /// [ImportTestCasesResponse][google.cloud.dialogflow.cx.v3.ImportTestCasesResponse]
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::ImportTestCasesRequest,google/cloud/dialogflow/cx/v3/test_case.proto#L749}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::ImportTestCasesResponse,google/cloud/dialogflow/cx/v3/test_case.proto#L778}
  ///
  /// [google.cloud.dialogflow.cx.v3.ImportTestCasesRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L749}
  /// [google.cloud.dialogflow.cx.v3.ImportTestCasesResponse]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L778}
  ///
  future<StatusOr<google::cloud::dialogflow::cx::v3::ImportTestCasesResponse>>
  ImportTestCases(
      google::cloud::dialogflow::cx::v3::ImportTestCasesRequest const& request,
      Options opts = {});

  ///
  /// Exports the test cases under the agent to a Cloud Storage bucket or a
  /// local file. Filter can be applied to export a subset of test cases.
  ///
  /// This method is a [long-running
  /// operation](https://cloud.google.com/dialogflow/cx/docs/how/long-running-operation).
  /// The returned `Operation` type has the following method-specific fields:
  ///
  /// - `metadata`:
  /// [ExportTestCasesMetadata][google.cloud.dialogflow.cx.v3.ExportTestCasesMetadata]
  /// - `response`:
  /// [ExportTestCasesResponse][google.cloud.dialogflow.cx.v3.ExportTestCasesResponse]
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::ExportTestCasesRequest,google/cloud/dialogflow/cx/v3/test_case.proto#L804}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::ExportTestCasesResponse,google/cloud/dialogflow/cx/v3/test_case.proto#L859}
  ///
  /// [google.cloud.dialogflow.cx.v3.ExportTestCasesRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L804}
  /// [google.cloud.dialogflow.cx.v3.ExportTestCasesResponse]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L859}
  ///
  future<StatusOr<google::cloud::dialogflow::cx::v3::ExportTestCasesResponse>>
  ExportTestCases(
      google::cloud::dialogflow::cx::v3::ExportTestCasesRequest const& request,
      Options opts = {});

  ///
  /// Fetches a list of results for a given test case.
  ///
  /// @param parent  Required. The test case to list results for.
  ///  Format: `projects/<Project ID>/locations/<Location ID>/agents/<Agent ID>/
  ///  testCases/<TestCase ID>`. Specify a `-` as a wildcard for TestCase ID to
  ///  list results across multiple test cases.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::TestCaseResult,google/cloud/dialogflow/cx/v3/test_case.proto#L240}
  ///
  /// [google.cloud.dialogflow.cx.v3.ListTestCaseResultsRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L880}
  /// [google.cloud.dialogflow.cx.v3.TestCaseResult]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L240}
  ///
  StreamRange<google::cloud::dialogflow::cx::v3::TestCaseResult>
  ListTestCaseResults(std::string const& parent, Options opts = {});

  ///
  /// Fetches a list of results for a given test case.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::ListTestCaseResultsRequest,google/cloud/dialogflow/cx/v3/test_case.proto#L880}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::TestCaseResult,google/cloud/dialogflow/cx/v3/test_case.proto#L240}
  ///
  /// [google.cloud.dialogflow.cx.v3.ListTestCaseResultsRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L880}
  /// [google.cloud.dialogflow.cx.v3.TestCaseResult]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L240}
  ///
  StreamRange<google::cloud::dialogflow::cx::v3::TestCaseResult>
  ListTestCaseResults(
      google::cloud::dialogflow::cx::v3::ListTestCaseResultsRequest request,
      Options opts = {});

  ///
  /// Gets a test case result.
  ///
  /// @param name  Required. The name of the testcase.
  ///  Format: `projects/<Project ID>/locations/<Location ID>/agents/<Agent
  ///  ID>/testCases/<TestCase ID>/results/<TestCaseResult ID>`.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::TestCaseResult,google/cloud/dialogflow/cx/v3/test_case.proto#L240}
  ///
  /// [google.cloud.dialogflow.cx.v3.GetTestCaseResultRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L937}
  /// [google.cloud.dialogflow.cx.v3.TestCaseResult]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L240}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::TestCaseResult> GetTestCaseResult(
      std::string const& name, Options opts = {});

  ///
  /// Gets a test case result.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::GetTestCaseResultRequest,google/cloud/dialogflow/cx/v3/test_case.proto#L937}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::dialogflow::cx::v3::TestCaseResult,google/cloud/dialogflow/cx/v3/test_case.proto#L240}
  ///
  /// [google.cloud.dialogflow.cx.v3.GetTestCaseResultRequest]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L937}
  /// [google.cloud.dialogflow.cx.v3.TestCaseResult]:
  /// @googleapis_reference_link{google/cloud/dialogflow/cx/v3/test_case.proto#L240}
  ///
  StatusOr<google::cloud::dialogflow::cx::v3::TestCaseResult> GetTestCaseResult(
      google::cloud::dialogflow::cx::v3::GetTestCaseResultRequest const&
          request,
      Options opts = {});

 private:
  std::shared_ptr<TestCasesConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_TEST_CASES_CLIENT_H