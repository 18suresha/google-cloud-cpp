// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUBLITE_INTERNAL_SERVICE_COMPOSITE_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUBLITE_INTERNAL_SERVICE_COMPOSITE_H

#include "google/cloud/pubsublite/internal/futures.h"
#include "google/cloud/pubsublite/internal/service.h"
#include <mutex>
#include <vector>

namespace google {
namespace cloud {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace pubsublite_internal {

/**
 * `ServiceComposite` wraps the lifetimes of one or more `Service`s into a
 * single object. This enables a user to manage the lifetimes of several
 * dependencies through a single object.
 */
class ServiceComposite : public Service {
 public:
  template <class... ServiceT>
  explicit ServiceComposite(ServiceT&... dependencies)
      : dependencies_{{std::ref(static_cast<Service&>(dependencies))...}} {}

  future<Status> Start() override {
    for (Service& dependency : dependencies_) {
      dependency.Start().then([this](future<Status> status_future) {
        Status s = status_future.get();
        if (!s.ok()) Abort(std::move(s));
      });
    }
    std::lock_guard<std::mutex> g{mu_};
    return status_promise_->get_future();
  }

  /**
   * @note Can be safely called more than once.
   */
  void Abort(Status s) {
    assert(!s.ok());
    promise<Status> start_promise{null_promise_t{}};
    {
      std::lock_guard<std::mutex> g{mu_};
      if (!status_promise_) return;
      start_promise = std::move(*status_promise_);
      status_promise_.reset();
      final_status_ = s;
    }
    start_promise.set_value(std::move(s));
  }

  /**
   *
   * @return a `Status` of `kOk` if and only if the current lifecycle is in the
   * running phase
   */
  Status status() {
    std::lock_guard<std::mutex> g{mu_};
    return final_status_;
  }

  future<void> Shutdown() override {
    {
      std::lock_guard<std::mutex> g{mu_};
      if (shutdown_) return make_ready_future();
      shutdown_ = true;
    }
    Abort(Status{StatusCode::kAborted, "`Shutdown` called"});
    future<void> root_future = make_ready_future();
    for (auto const& dependency : dependencies_) {
      root_future = root_future.then(ChainFuture(dependency.get().Shutdown()));
    }
    return root_future;
  }

 private:
  std::vector<std::reference_wrapper<Service>> const dependencies_;
  std::mutex mu_;

  bool shutdown_ = false;  // ABSL_GUARDED_BY(mu_)
  absl::optional<promise<Status>> status_promise_{
      promise<Status>{}};  // ABSL_GUARDED_BY(mu_)
  Status final_status_;    // ABSL_GUARDED_BY(mu_)
};

}  // namespace pubsublite_internal
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUBLITE_INTERNAL_SERVICE_COMPOSITE_H
