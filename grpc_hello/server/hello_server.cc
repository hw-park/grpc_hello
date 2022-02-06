#include "hello_server.h"

#include <string>

namespace grpc_hello {
namespace server {

using ::grpc::ServerContext;
using ::grpc::Status;
using ::grpc_hello::HelloRequest;
using ::grpc_hello::HelloResponse;

::grpc::Status HelloServiceImpl::Hello(ServerContext *context,
                                       const HelloRequest *request,
                                       HelloResponse *response) {
  response->set_response("Hello, " + request->id());
  return Status::OK;
}

}  // namespace server
}  // namespace grpc_hello
