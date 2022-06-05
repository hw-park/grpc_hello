workspace(name = "grpc_hello")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

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
    branch = "v1.43.x",
    remote = "https://github.com/grpc/grpc.git",
)

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")

grpc_deps()

load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")

grpc_extra_deps()

git_repository(
    name = "com_google_absl",
    branch = "main",
    remote = "https://github.com/abseil/abseil-cpp.git",
)

git_repository(
    name = "com_google_googletest",
    branch = "main",
    remote = "https://github.com/google/googletest.git",
)

git_repository(
    name = "com_google_protobuf",
    branch = "main",
    remote = "https://github.com/protocolbuffers/protobuf.git",
)

git_repository(
    name = "io_abseil_py",
    branch = "main",
    remote = "https://github.com/abseil/abseil-py.git",
)
