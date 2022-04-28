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
// source: google/cloud/functions/v1/functions.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_FUNCTIONS_CLOUD_FUNCTIONS_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_FUNCTIONS_CLOUD_FUNCTIONS_CLIENT_H

#include "google/cloud/functions/cloud_functions_connection.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <map>
#include <memory>

namespace google {
namespace cloud {
namespace functions {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

///
/// A service that application uses to manipulate triggers and functions.
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
class CloudFunctionsServiceClient {
 public:
  explicit CloudFunctionsServiceClient(
      std::shared_ptr<CloudFunctionsServiceConnection> connection,
      Options opts = {});
  ~CloudFunctionsServiceClient();

  //@{
  // @name Copy and move support
  CloudFunctionsServiceClient(CloudFunctionsServiceClient const&) = default;
  CloudFunctionsServiceClient& operator=(CloudFunctionsServiceClient const&) =
      default;
  CloudFunctionsServiceClient(CloudFunctionsServiceClient&&) = default;
  CloudFunctionsServiceClient& operator=(CloudFunctionsServiceClient&&) =
      default;
  //@}

  //@{
  // @name Equality
  friend bool operator==(CloudFunctionsServiceClient const& a,
                         CloudFunctionsServiceClient const& b) {
    return a.connection_ == b.connection_;
  }
  friend bool operator!=(CloudFunctionsServiceClient const& a,
                         CloudFunctionsServiceClient const& b) {
    return !(a == b);
  }
  //@}

  ///
  /// Returns a list of functions that belong to the requested project.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::functions::v1::ListFunctionsRequest,google/cloud/functions/v1/functions.proto#L703}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::functions::v1::CloudFunction,google/cloud/functions/v1/functions.proto#L195}
  ///
  /// [google.cloud.functions.v1.ListFunctionsRequest]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L703}
  /// [google.cloud.functions.v1.CloudFunction]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L195}
  ///
  StreamRange<google::cloud::functions::v1::CloudFunction> ListFunctions(
      google::cloud::functions::v1::ListFunctionsRequest request,
      Options opts = {});

  ///
  /// Returns a function with the given name from the requested project.
  ///
  /// @param name  Required. The name of the function which details should be
  /// obtained.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::functions::v1::CloudFunction,google/cloud/functions/v1/functions.proto#L195}
  ///
  /// [google.cloud.functions.v1.GetFunctionRequest]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L692}
  /// [google.cloud.functions.v1.CloudFunction]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L195}
  ///
  StatusOr<google::cloud::functions::v1::CloudFunction> GetFunction(
      std::string const& name, Options opts = {});

  ///
  /// Returns a function with the given name from the requested project.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::functions::v1::GetFunctionRequest,google/cloud/functions/v1/functions.proto#L692}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::functions::v1::CloudFunction,google/cloud/functions/v1/functions.proto#L195}
  ///
  /// [google.cloud.functions.v1.GetFunctionRequest]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L692}
  /// [google.cloud.functions.v1.CloudFunction]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L195}
  ///
  StatusOr<google::cloud::functions::v1::CloudFunction> GetFunction(
      google::cloud::functions::v1::GetFunctionRequest const& request,
      Options opts = {});

  ///
  /// Creates a new function. If a function with the given name already exists
  /// in the specified project, the long running operation will return
  /// `ALREADY_EXISTS` error.
  ///
  /// @param location  Required. The project and location in which the function
  /// should be created, specified
  ///  in the format `projects/*/locations/*`
  /// @param function  Required. Function to be created.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::functions::v1::CloudFunction,google/cloud/functions/v1/functions.proto#L195}
  ///
  /// [google.cloud.functions.v1.CreateFunctionRequest]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L646}
  /// [google.cloud.functions.v1.CloudFunction]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L195}
  ///
  future<StatusOr<google::cloud::functions::v1::CloudFunction>> CreateFunction(
      std::string const& location,
      google::cloud::functions::v1::CloudFunction const& function,
      Options opts = {});

  ///
  /// Creates a new function. If a function with the given name already exists
  /// in the specified project, the long running operation will return
  /// `ALREADY_EXISTS` error.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::functions::v1::CreateFunctionRequest,google/cloud/functions/v1/functions.proto#L646}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::functions::v1::CloudFunction,google/cloud/functions/v1/functions.proto#L195}
  ///
  /// [google.cloud.functions.v1.CreateFunctionRequest]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L646}
  /// [google.cloud.functions.v1.CloudFunction]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L195}
  ///
  future<StatusOr<google::cloud::functions::v1::CloudFunction>> CreateFunction(
      google::cloud::functions::v1::CreateFunctionRequest const& request,
      Options opts = {});

  ///
  /// Updates existing function.
  ///
  /// @param function  Required. New version of the function.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::functions::v1::CloudFunction,google/cloud/functions/v1/functions.proto#L195}
  ///
  /// [google.cloud.functions.v1.UpdateFunctionRequest]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L661}
  /// [google.cloud.functions.v1.CloudFunction]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L195}
  ///
  future<StatusOr<google::cloud::functions::v1::CloudFunction>> UpdateFunction(
      google::cloud::functions::v1::CloudFunction const& function,
      Options opts = {});

  ///
  /// Updates existing function.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::functions::v1::UpdateFunctionRequest,google/cloud/functions/v1/functions.proto#L661}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::functions::v1::CloudFunction,google/cloud/functions/v1/functions.proto#L195}
  ///
  /// [google.cloud.functions.v1.UpdateFunctionRequest]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L661}
  /// [google.cloud.functions.v1.CloudFunction]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L195}
  ///
  future<StatusOr<google::cloud::functions::v1::CloudFunction>> UpdateFunction(
      google::cloud::functions::v1::UpdateFunctionRequest const& request,
      Options opts = {});

  ///
  /// Deletes a function with the given name from the specified project. If the
  /// given function is used by some trigger, the trigger will be updated to
  /// remove this function.
  ///
  /// @param name  Required. The name of the function which should be deleted.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::functions::v1::OperationMetadataV1,google/cloud/functions/v1/operations.proto#L44}
  ///
  /// [google.cloud.functions.v1.DeleteFunctionRequest]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L741}
  /// [google.cloud.functions.v1.OperationMetadataV1]:
  /// @googleapis_reference_link{google/cloud/functions/v1/operations.proto#L44}
  ///
  future<StatusOr<google::cloud::functions::v1::OperationMetadataV1>>
  DeleteFunction(std::string const& name, Options opts = {});

  ///
  /// Deletes a function with the given name from the specified project. If the
  /// given function is used by some trigger, the trigger will be updated to
  /// remove this function.
  ///
  /// @param request
  /// @googleapis_link{google::cloud::functions::v1::DeleteFunctionRequest,google/cloud/functions/v1/functions.proto#L741}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::functions::v1::OperationMetadataV1,google/cloud/functions/v1/operations.proto#L44}
  ///
  /// [google.cloud.functions.v1.DeleteFunctionRequest]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L741}
  /// [google.cloud.functions.v1.OperationMetadataV1]:
  /// @googleapis_reference_link{google/cloud/functions/v1/operations.proto#L44}
  ///
  future<StatusOr<google::cloud::functions::v1::OperationMetadataV1>>
  DeleteFunction(
      google::cloud::functions::v1::DeleteFunctionRequest const& request,
      Options opts = {});

  ///
  /// Synchronously invokes a deployed Cloud Function. To be used for testing
  /// purposes as very limited traffic is allowed. For more information on
  /// the actual limits, refer to
  /// [Rate Limits](https://cloud.google.com/functions/quotas#rate_limits).
  ///
  /// @param name  Required. The name of the function to be called.
  /// @param data  Required. Input to be passed to the function.
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::functions::v1::CallFunctionResponse,google/cloud/functions/v1/functions.proto#L766}
  ///
  /// [google.cloud.functions.v1.CallFunctionRequest]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L752}
  /// [google.cloud.functions.v1.CallFunctionResponse]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L766}
  ///
  StatusOr<google::cloud::functions::v1::CallFunctionResponse> CallFunction(
      std::string const& name, std::string const& data, Options opts = {});

  ///
  /// Synchronously invokes a deployed Cloud Function. To be used for testing
  /// purposes as very limited traffic is allowed. For more information on
  /// the actual limits, refer to
  /// [Rate Limits](https://cloud.google.com/functions/quotas#rate_limits).
  ///
  /// @param request
  /// @googleapis_link{google::cloud::functions::v1::CallFunctionRequest,google/cloud/functions/v1/functions.proto#L752}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::functions::v1::CallFunctionResponse,google/cloud/functions/v1/functions.proto#L766}
  ///
  /// [google.cloud.functions.v1.CallFunctionRequest]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L752}
  /// [google.cloud.functions.v1.CallFunctionResponse]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L766}
  ///
  StatusOr<google::cloud::functions::v1::CallFunctionResponse> CallFunction(
      google::cloud::functions::v1::CallFunctionRequest const& request,
      Options opts = {});

  ///
  /// Returns a signed URL for uploading a function source code.
  /// For more information about the signed URL usage see:
  /// https://cloud.google.com/storage/docs/access-control/signed-urls.
  /// Once the function source code upload is complete, the used signed
  /// URL should be provided in CreateFunction or UpdateFunction request
  /// as a reference to the function source code.
  ///
  /// When uploading source code to the generated signed URL, please follow
  /// these restrictions:
  ///
  /// * Source file type should be a zip file.
  /// * Source file size should not exceed 100MB limit.
  /// * No credentials should be attached - the signed URLs provide access to
  /// the
  ///   target bucket using internal service identity; if credentials were
  ///   attached, the identity from the credentials would be used, but that
  ///   identity does not have permissions to upload files to the URL.
  ///
  /// When making a HTTP PUT request, these two headers need to be specified:
  ///
  /// * `content-type: application/zip`
  /// * `x-goog-content-length-range: 0,104857600`
  ///
  /// And this header SHOULD NOT be specified:
  ///
  /// * `Authorization: Bearer YOUR_TOKEN`
  ///
  /// @param request
  /// @googleapis_link{google::cloud::functions::v1::GenerateUploadUrlRequest,google/cloud/functions/v1/functions.proto#L780}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::functions::v1::GenerateUploadUrlResponse,google/cloud/functions/v1/functions.proto#L787}
  ///
  /// [google.cloud.functions.v1.GenerateUploadUrlRequest]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L780}
  /// [google.cloud.functions.v1.GenerateUploadUrlResponse]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L787}
  ///
  StatusOr<google::cloud::functions::v1::GenerateUploadUrlResponse>
  GenerateUploadUrl(
      google::cloud::functions::v1::GenerateUploadUrlRequest const& request,
      Options opts = {});

  ///
  /// Returns a signed URL for downloading deployed function source code.
  /// The URL is only valid for a limited period and should be used within
  /// minutes after generation.
  /// For more information about the signed URL usage see:
  /// https://cloud.google.com/storage/docs/access-control/signed-urls
  ///
  /// @param request
  /// @googleapis_link{google::cloud::functions::v1::GenerateDownloadUrlRequest,google/cloud/functions/v1/functions.proto#L795}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::cloud::functions::v1::GenerateDownloadUrlResponse,google/cloud/functions/v1/functions.proto#L806}
  ///
  /// [google.cloud.functions.v1.GenerateDownloadUrlRequest]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L795}
  /// [google.cloud.functions.v1.GenerateDownloadUrlResponse]:
  /// @googleapis_reference_link{google/cloud/functions/v1/functions.proto#L806}
  ///
  StatusOr<google::cloud::functions::v1::GenerateDownloadUrlResponse>
  GenerateDownloadUrl(
      google::cloud::functions::v1::GenerateDownloadUrlRequest const& request,
      Options opts = {});

  ///
  /// Sets the IAM access control policy on the specified function.
  /// Replaces any existing policy.
  ///
  /// @param request
  /// @googleapis_link{google::iam::v1::SetIamPolicyRequest,google/iam/v1/iam_policy.proto#L101}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::iam::v1::Policy,google/iam/v1/policy.proto#L96}
  ///
  /// [google.iam.v1.SetIamPolicyRequest]:
  /// @googleapis_reference_link{google/iam/v1/iam_policy.proto#L101}
  /// [google.iam.v1.Policy]:
  /// @googleapis_reference_link{google/iam/v1/policy.proto#L96}
  ///
  StatusOr<google::iam::v1::Policy> SetIamPolicy(
      google::iam::v1::SetIamPolicyRequest const& request, Options opts = {});

  ///
  /// Gets the IAM access control policy for a function.
  /// Returns an empty policy if the function exists and does not have a policy
  /// set.
  ///
  /// @param request
  /// @googleapis_link{google::iam::v1::GetIamPolicyRequest,google/iam/v1/iam_policy.proto#L123}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::iam::v1::Policy,google/iam/v1/policy.proto#L96}
  ///
  /// [google.iam.v1.GetIamPolicyRequest]:
  /// @googleapis_reference_link{google/iam/v1/iam_policy.proto#L123}
  /// [google.iam.v1.Policy]:
  /// @googleapis_reference_link{google/iam/v1/policy.proto#L96}
  ///
  StatusOr<google::iam::v1::Policy> GetIamPolicy(
      google::iam::v1::GetIamPolicyRequest const& request, Options opts = {});

  ///
  /// Tests the specified permissions against the IAM access control policy
  /// for a function.
  /// If the function does not exist, this will return an empty set of
  /// permissions, not a NOT_FOUND error.
  ///
  /// @param request
  /// @googleapis_link{google::iam::v1::TestIamPermissionsRequest,google/iam/v1/iam_policy.proto#L136}
  /// @param opts Optional. Override the class-level options, such as retry and
  ///     backoff policies.
  /// @return
  /// @googleapis_link{google::iam::v1::TestIamPermissionsResponse,google/iam/v1/iam_policy.proto#L151}
  ///
  /// [google.iam.v1.TestIamPermissionsRequest]:
  /// @googleapis_reference_link{google/iam/v1/iam_policy.proto#L136}
  /// [google.iam.v1.TestIamPermissionsResponse]:
  /// @googleapis_reference_link{google/iam/v1/iam_policy.proto#L151}
  ///
  StatusOr<google::iam::v1::TestIamPermissionsResponse> TestIamPermissions(
      google::iam::v1::TestIamPermissionsRequest const& request,
      Options opts = {});

 private:
  std::shared_ptr<CloudFunctionsServiceConnection> connection_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace functions
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_FUNCTIONS_CLOUD_FUNCTIONS_CLIENT_H
