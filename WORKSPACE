workspace(name = "grpc_hello")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "rules_pkg",
    branch = "main",
    remote = "https://github.com/bazelbuild/rules_pkg.git",
)

git_repository(
    name = "rules_proto",
    branch = "master",
    remote = "https://github.com/bazelbuild/rules_proto.git",
)

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")

rules_proto_dependencies()

rules_proto_toolchains()

git_repository(
    name = "com_github_gflags_gflags",
    branch = "master",
    remote = "https://github.com/gflags/gflags.git",
)

git_repository(
    name = "com_github_google_glog",
    branch = "master",
    remote = "https://github.com/google/glog.git",
)

git_repository(
    name = "com_github_grpc_grpc",
    branch = "master",
    remote = "https://github.com/grpc/grpc.git",
)

git_repository(
    name = "com_google_absl",
    branch = "master",
    remote = "https://github.com/abseil/abseil-cpp.git",
)

git_repository(
    name = "com_google_googletest",
    branch = "master",
    remote = "https://github.com/google/googletest.git",
)

git_repository(
    name = "com_google_protobuf",
    branch = "master",
    remote = "https://github.com/protocolbuffers/protobuf.git",
)
