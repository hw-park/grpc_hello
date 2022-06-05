from absl import logging
from grpc_hello.protos import grpc_hello_pb2_grpc
from grpc_hello.protos import grpc_hello_pb2


class HelloServiceClient:

    def __init__(self, channel) -> None:
        self._stub = grpc_hello_pb2_grpc.HelloServiceStub(channel)

    def hello(self, client_id: str) -> str:
        request = grpc_hello_pb2.HelloRequest(id=client_id)
        response = self._stub.Hello(request)
        if response is None:
            logging.warning('HelloService RPC failed.')
            return 'RPC failed'
        return response.response
