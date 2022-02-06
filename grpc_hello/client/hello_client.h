#ifndef GRPC_HELLO_CLIENT_HELLO_CLIENT_H_
#define GRPC_HELLO_CLIENT_HELLO_CLIENT_H_

#include <memory>
#include <string>

#include "grpc_hello/protos/grpc_hello.grpc.pb.h"
#include "grpcpp/grpcpp.h"

namespace grpc_hello {
namespace client {

class HelloServiceClient {
 public:
  explicit HelloServiceClient(std::shared_ptr<::grpc::Channel> channel) :
      HelloServiceClient(HelloService::NewStub(channel)) {}
  explicit HelloServiceClient(std::unique_ptr<HelloService::StubInterface> stub) :
      stub_(std::move(stub)) {}
  std::string Hello(const std::string &id);

 private:
  std::unique_ptr<HelloService::StubInterface> stub_;
};

}  // namespace client
}  // namespace grpc_hello

#endif  // GRPC_HELLO_CLIENT_HELLO_CLIENT_H_
