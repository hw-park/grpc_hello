#include "hello_server.h"

#include <cstdlib>
#include <string>

#include "gflags/gflags.h"
#include "glog/logging.h"
#include "grpcpp/ext/proto_server_reflection_plugin.h"
#include "grpcpp/grpcpp.h"
#include "grpcpp/health_check_service_interface.h"

namespace grpc_hello {
namespace server {

using ::grpc::Server;
using ::grpc::ServerBuilder;
using ::grpc::ServerContext;
using ::grpc::Status;

void RunServer() {
  static const std::string kServerAddress("0.0.0.0:8080");

  HelloServiceImpl service;

  ::grpc::EnableDefaultHealthCheckService(true);
  ::grpc::reflection::InitProtoReflectionServerBuilderPlugin();

  ServerBuilder builder;
  builder.AddListeningPort(kServerAddress, ::grpc::InsecureServerCredentials());
  builder.RegisterService(&service);

  std::unique_ptr<Server> server(builder.BuildAndStart());

  LOG(INFO) << "Server listening on " << kServerAddress;

  server->Wait();
}

}  // namespace server
}  // namespace grpc_hello

int main(int argc, char **argv) {
  ::google::InitGoogleLogging(argv[0]);
  ::google::ParseCommandLineFlags(&argc, &argv, true);

  ::grpc_hello::server::RunServer();

  return EXIT_SUCCESS;
}
