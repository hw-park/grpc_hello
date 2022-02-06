#include "grpc_hello/client/hello_client.h"

#include <cstdlib>
#include <string>
#include <utility>

#include "gflags/gflags.h"
#include "glog/logging.h"
#include "grpcpp/grpcpp.h"

DEFINE_string(host, "0.0.0.0:8080", "Host ip and port.");
DEFINE_string(id, "darling", "Id.");

namespace grpc_hello {
namespace client {

using ::grpc::Server;
using ::grpc::ServerBuilder;
using ::grpc::ServerContext;
using ::grpc::Status;
using ::grpc_hello::client::HelloServiceClient;

void RunClient() {
  HelloServiceClient client(
      ::grpc::CreateChannel(FLAGS_host, ::grpc::InsecureChannelCredentials()));
  std::string response_string = client.Hello(FLAGS_id);

  LOG(INFO) << "Message received: " << response_string;
}

}  // namespace client
}  // namespace grpc_hello

int main(int argc, char **argv) {
  ::google::InitGoogleLogging(argv[0]);
  ::google::ParseCommandLineFlags(&argc, &argv, true);

  ::grpc_hello::client::RunClient();

  return EXIT_SUCCESS;
}
