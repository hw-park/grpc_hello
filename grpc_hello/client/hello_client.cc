#include "grpc_hello/client/hello_client.h"

#include "glog/logging.h"

namespace grpc_hello {
namespace client {

using ::grpc::ClientContext;
using ::grpc::Status;
using ::grpc_hello::HelloRequest;
using ::grpc_hello::HelloResponse;

std::string HelloServiceClient::Hello(const std::string &id) {
  ClientContext context;
  HelloRequest request;
  HelloResponse response;

  request.set_id(id);
  Status status = stub_->Hello(&context, request, &response);

  if (status.ok()) {
    return response.response();
  }

  LOG(WARNING) << "HelloService RPC failed.";
  return "RPC failed";
}

}  // namespace client
}  // namespace grpc_hello
