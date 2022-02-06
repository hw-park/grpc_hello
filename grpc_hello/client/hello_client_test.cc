#include "grpc_hello/client/hello_client.h"

#include <memory>

#include "grpc_hello/protos/grpc_hello.grpc.pb.h"
#include "grpc_hello/protos/grpc_hello_mock.grpc.pb.h"
#include "grpcpp/grpcpp.h"
#include "gtest/gtest.h"

namespace grpc_hello {
namespace client {
namespace {

using ::grpc::Status;
using ::grpc_hello::HelloResponse;
using ::grpc_hello::MockHelloServiceStub;
using ::testing::_;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::SetArgPointee;

TEST(HelloServiceClient, Works) {
  HelloResponse response;

  response.set_response("Hello, darling");
  auto stub_ = std::unique_ptr<MockHelloServiceStub>(new MockHelloServiceStub);
  EXPECT_CALL(*stub_, Hello(_, _, _)).Times(1).WillOnce(DoAll(SetArgPointee<2>(response), Return(Status::OK)));

  HelloServiceClient client(std::move(stub_));
  std::string response_string = client.Hello("darling");
  EXPECT_EQ(response_string, "Hello, darling");
}

}  // namespace
}  // namespace client
}  // namespace grpc_hello
