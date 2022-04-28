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
// source: google/cloud/bigquery/reservation/v1/reservation.proto

#include "google/cloud/bigquery/internal/reservation_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/bigquery/reservation/v1/reservation.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace bigquery_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ReservationServiceLogging::ReservationServiceLogging(
    std::shared_ptr<ReservationServiceStub> child,
    TracingOptions tracing_options, std::set<std::string> components)
    : child_(std::move(child)),
      tracing_options_(std::move(tracing_options)),
      components_(std::move(components)) {}

StatusOr<google::cloud::bigquery::reservation::v1::Reservation>
ReservationServiceLogging::CreateReservation(
    grpc::ClientContext& context,
    google::cloud::bigquery::reservation::v1::CreateReservationRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::reservation::v1::
                 CreateReservationRequest const& request) {
        return child_->CreateReservation(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::reservation::v1::ListReservationsResponse>
ReservationServiceLogging::ListReservations(
    grpc::ClientContext& context,
    google::cloud::bigquery::reservation::v1::ListReservationsRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::reservation::v1::
                 ListReservationsRequest const& request) {
        return child_->ListReservations(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::reservation::v1::Reservation>
ReservationServiceLogging::GetReservation(
    grpc::ClientContext& context,
    google::cloud::bigquery::reservation::v1::GetReservationRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::bigquery::reservation::v1::GetReservationRequest const&
              request) { return child_->GetReservation(context, request); },
      context, request, __func__, tracing_options_);
}

Status ReservationServiceLogging::DeleteReservation(
    grpc::ClientContext& context,
    google::cloud::bigquery::reservation::v1::DeleteReservationRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::reservation::v1::
                 DeleteReservationRequest const& request) {
        return child_->DeleteReservation(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::reservation::v1::Reservation>
ReservationServiceLogging::UpdateReservation(
    grpc::ClientContext& context,
    google::cloud::bigquery::reservation::v1::UpdateReservationRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::reservation::v1::
                 UpdateReservationRequest const& request) {
        return child_->UpdateReservation(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::reservation::v1::CapacityCommitment>
ReservationServiceLogging::CreateCapacityCommitment(
    grpc::ClientContext& context,
    google::cloud::bigquery::reservation::v1::
        CreateCapacityCommitmentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::reservation::v1::
                 CreateCapacityCommitmentRequest const& request) {
        return child_->CreateCapacityCommitment(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<
    google::cloud::bigquery::reservation::v1::ListCapacityCommitmentsResponse>
ReservationServiceLogging::ListCapacityCommitments(
    grpc::ClientContext& context,
    google::cloud::bigquery::reservation::v1::
        ListCapacityCommitmentsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::reservation::v1::
                 ListCapacityCommitmentsRequest const& request) {
        return child_->ListCapacityCommitments(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::reservation::v1::CapacityCommitment>
ReservationServiceLogging::GetCapacityCommitment(
    grpc::ClientContext& context,
    google::cloud::bigquery::reservation::v1::
        GetCapacityCommitmentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::reservation::v1::
                 GetCapacityCommitmentRequest const& request) {
        return child_->GetCapacityCommitment(context, request);
      },
      context, request, __func__, tracing_options_);
}

Status ReservationServiceLogging::DeleteCapacityCommitment(
    grpc::ClientContext& context,
    google::cloud::bigquery::reservation::v1::
        DeleteCapacityCommitmentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::reservation::v1::
                 DeleteCapacityCommitmentRequest const& request) {
        return child_->DeleteCapacityCommitment(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::reservation::v1::CapacityCommitment>
ReservationServiceLogging::UpdateCapacityCommitment(
    grpc::ClientContext& context,
    google::cloud::bigquery::reservation::v1::
        UpdateCapacityCommitmentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::reservation::v1::
                 UpdateCapacityCommitmentRequest const& request) {
        return child_->UpdateCapacityCommitment(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<
    google::cloud::bigquery::reservation::v1::SplitCapacityCommitmentResponse>
ReservationServiceLogging::SplitCapacityCommitment(
    grpc::ClientContext& context,
    google::cloud::bigquery::reservation::v1::
        SplitCapacityCommitmentRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::reservation::v1::
                 SplitCapacityCommitmentRequest const& request) {
        return child_->SplitCapacityCommitment(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::reservation::v1::CapacityCommitment>
ReservationServiceLogging::MergeCapacityCommitments(
    grpc::ClientContext& context,
    google::cloud::bigquery::reservation::v1::
        MergeCapacityCommitmentsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::reservation::v1::
                 MergeCapacityCommitmentsRequest const& request) {
        return child_->MergeCapacityCommitments(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::reservation::v1::Assignment>
ReservationServiceLogging::CreateAssignment(
    grpc::ClientContext& context,
    google::cloud::bigquery::reservation::v1::CreateAssignmentRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::reservation::v1::
                 CreateAssignmentRequest const& request) {
        return child_->CreateAssignment(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::reservation::v1::ListAssignmentsResponse>
ReservationServiceLogging::ListAssignments(
    grpc::ClientContext& context,
    google::cloud::bigquery::reservation::v1::ListAssignmentsRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::reservation::v1::
                 ListAssignmentsRequest const& request) {
        return child_->ListAssignments(context, request);
      },
      context, request, __func__, tracing_options_);
}

Status ReservationServiceLogging::DeleteAssignment(
    grpc::ClientContext& context,
    google::cloud::bigquery::reservation::v1::DeleteAssignmentRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::reservation::v1::
                 DeleteAssignmentRequest const& request) {
        return child_->DeleteAssignment(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::reservation::v1::SearchAssignmentsResponse>
ReservationServiceLogging::SearchAssignments(
    grpc::ClientContext& context,
    google::cloud::bigquery::reservation::v1::SearchAssignmentsRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::reservation::v1::
                 SearchAssignmentsRequest const& request) {
        return child_->SearchAssignments(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::reservation::v1::SearchAllAssignmentsResponse>
ReservationServiceLogging::SearchAllAssignments(
    grpc::ClientContext& context,
    google::cloud::bigquery::reservation::v1::SearchAllAssignmentsRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::reservation::v1::
                 SearchAllAssignmentsRequest const& request) {
        return child_->SearchAllAssignments(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::reservation::v1::Assignment>
ReservationServiceLogging::MoveAssignment(
    grpc::ClientContext& context,
    google::cloud::bigquery::reservation::v1::MoveAssignmentRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::bigquery::reservation::v1::MoveAssignmentRequest const&
              request) { return child_->MoveAssignment(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::reservation::v1::Assignment>
ReservationServiceLogging::UpdateAssignment(
    grpc::ClientContext& context,
    google::cloud::bigquery::reservation::v1::UpdateAssignmentRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::reservation::v1::
                 UpdateAssignmentRequest const& request) {
        return child_->UpdateAssignment(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::reservation::v1::BiReservation>
ReservationServiceLogging::GetBiReservation(
    grpc::ClientContext& context,
    google::cloud::bigquery::reservation::v1::GetBiReservationRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::reservation::v1::
                 GetBiReservationRequest const& request) {
        return child_->GetBiReservation(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::bigquery::reservation::v1::BiReservation>
ReservationServiceLogging::UpdateBiReservation(
    grpc::ClientContext& context,
    google::cloud::bigquery::reservation::v1::UpdateBiReservationRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::bigquery::reservation::v1::
                 UpdateBiReservationRequest const& request) {
        return child_->UpdateBiReservation(context, request);
      },
      context, request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigquery_internal
}  // namespace cloud
}  // namespace google
