from absl import logging
from grpc_hello.protos import grpc_hello_pb2_grpc
from grpc_hello.protos import grpc_hello_pb2


class HelloServiceImpl(grpc_hello_pb2_grpc.HelloServiceServicer):

    def Hello(self, request, context):
        response_string = 'Hello, ' + request.id

        logging.info('Message set: ' + response_string)

        return grpc_hello_pb2.HelloResponse(response=response_string)
