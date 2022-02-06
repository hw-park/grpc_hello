#include "grpc_hello/server/hello_server.h"

#include "grpc_hello/protos/grpc_hello.grpc.pb.h"
#include "grpcpp/grpcpp.h"
#include "gtest/gtest.h"

namespace grpc_hello {
namespace server {
namespace {

using ::grpc::ServerContext;
using ::grpc::Status;
using ::grpc_hello::HelloRequest;
using ::grpc_hello::HelloResponse;

TEST(HelloServiceServer, Works) {
  HelloServiceImpl service;
  ServerContext context;
  HelloRequest request;
  HelloResponse response;

  request.set_id("darling");
  Status status = service.Hello(&context, &request, &response);

  ASSERT_TRUE(status.ok());
  EXPECT_EQ(response.response(), "Hello, darling");
}

}  // namespace
}  // namespace server
}  // namespace grpc_hello
