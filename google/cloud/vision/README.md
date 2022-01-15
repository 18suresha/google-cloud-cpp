# Cloud Vision API C++ Client Library

:construction:

This directory contains an idiomatic C++ client library for the
[Cloud Vision API][cloud-service-docs]. Integrate Google Vision
features, including image labeling, face, logo, and landmark detection, optical
character recognition (OCR), and detection of explicit content, into
applications.

This library is **experimental**. Its APIs are subject to change without notice.

Please note that the Google Cloud C++ client libraries do **not** follow
[Semantic Versioning](https://semver.org/).

## Supported Platforms

* Windows, macOS, Linux
* C++11 (and higher) compilers (we test with GCC >= 5.4, Clang >= 6.0, and
  MSVC >= 2017)
* Environments with or without exceptions
* Bazel and CMake builds

## Documentation

* Official documentation about the [Cloud Vision API][cloud-service-docs] service
* [Reference doxygen documentation][doxygen-link] for each release of this
  client library
* Detailed header comments in our [public `.h`][source-link] files

[cloud-service-docs]: https://cloud.google.com/vision
[doxygen-link]: https://googleapis.dev/cpp/google-cloud-vision/latest/
[source-link]: https://github.com/googleapis/google-cloud-cpp/tree/main/google/cloud/vision

## Quickstart

The [quickstart/](quickstart/README.md) directory contains a minimal environment
to get started using this client library in a larger project. The following
"Hello World" program is used in this quickstart, and should give you a taste of
this library.

<!-- inject-quickstart-start -->
```cc
#include "google/cloud/vision/image_annotator_client.h"
#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[]) try {
  auto constexpr kDefaultUri =
      "gs://cloud-samples-data/vision/label/wakeupcat.jpg";
  if (argc > 2) {
    std::cerr << "Usage: " << argv[0] << " [gcs-uri]\n"
              << "  The gcs-uri must be in gs://... format. It defaults to "
              << kDefaultUri << "\n";
    return 1;
  }
  auto uri = std::string{argc == 2 ? argv[1] : kDefaultUri};

  namespace vision = ::google::cloud::vision;
  auto client =
      vision::ImageAnnotatorClient(vision::MakeImageAnnotatorConnection());

  // Define the image we want to annotate
  google::cloud::vision::v1::Image image;
  image.mutable_source()->set_image_uri(uri);
  // Create a request to annotate this image with Request text annotations for a
  // file stored in GCS.
  google::cloud::vision::v1::AnnotateImageRequest request;
  *request.mutable_image() = std::move(image);
  request.add_features()->set_type(
      google::cloud::vision::v1::Feature::TEXT_DETECTION);

  google::cloud::vision::v1::BatchAnnotateImagesRequest batch_request;
  *batch_request.add_requests() = std::move(request);
  auto batch = client.BatchAnnotateImages(batch_request);
  if (!batch) throw std::runtime_error(batch.status().message());

  // Find the longest annotation and print it
  auto result = std::string{};
  for (auto const& response : batch->responses()) {
    for (auto const& annotation : response.text_annotations()) {
      if (result.size() < annotation.description().size()) {
        result = annotation.description();
      }
    }
  }
  std::cout << "The image contains this text: " << result << "\n";

  return 0;
} catch (std::exception const& ex) {
  std::cerr << "Standard exception raised: " << ex.what() << "\n";
  return 1;
}
```
<!-- inject-quickstart-end -->

* Packaging maintainers or developers who prefer to install the library in a
  fixed directory (such as `/usr/local` or `/opt`) should consult the
  [packaging guide](/doc/packaging.md).
* Developers wanting to use the libraries as part of a larger CMake or Bazel
  project should consult the [quickstart guides](#quickstart) for the library
  or libraries they want to use.
* Developers wanting to compile the library just to run some of the examples or
  tests should read the current document.
* Contributors and developers to `google-cloud-cpp` should consult the guide to
  [setup a development workstation][howto-setup-dev-workstation].

[howto-setup-dev-workstation]: /doc/contributor/howto-guide-setup-development-workstation.md

## Contributing changes

See [`CONTRIBUTING.md`](../../../CONTRIBUTING.md) for details on how to
contribute to this project, including how to build and test your changes
as well as how to properly format your code.

## Licensing

Apache 2.0; see [`LICENSE`](../../../LICENSE) for details.