#include "grpc_hello/server/hello_server.h"

#include <string>

#include "glog/logging.h"

namespace grpc_hello {
namespace server {

using ::grpc::ServerContext;
using ::grpc::Status;
using ::grpc_hello::HelloRequest;
using ::grpc_hello::HelloResponse;

::grpc::Status HelloServiceImpl::Hello(ServerContext *context,
                                       const HelloRequest *request,
                                       HelloResponse *response) {
  std::string response_string = "Hello, " + request->id();

  LOG(INFO) << "Message set: " << response_string;

  response->set_response(response_string);

  return Status::OK;
}

}  // namespace server
}  // namespace grpc_hello
