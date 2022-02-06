#ifndef GRPC_HELLO_SERVER_HELLO_SERVER_H_
#define GRPC_HELLO_SERVER_HELLO_SERVER_H_

#include "grpc_hello/protos/grpc_hello.grpc.pb.h"
#include "grpcpp/grpcpp.h"

namespace grpc_hello {
namespace server {

class HelloServiceImpl final : public ::grpc_hello::HelloService::Service {
 public:
  ::grpc::Status Hello(::grpc::ServerContext *context,
                       const ::grpc_hello::HelloRequest *request,
                       ::grpc_hello::HelloResponse *response);
};

}  // namespace server
}  // namespace grpc_hello

#endif  // GRPC_HELLO_SERVER_HELLO_SERVER_H_
