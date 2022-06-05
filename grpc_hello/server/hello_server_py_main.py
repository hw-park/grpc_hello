from absl import app, flags, logging
from concurrent import futures
from grpc_hello.protos import grpc_hello_pb2_grpc
import grpc
import hello_server_py

FLAGS = flags.FLAGS

flags.DEFINE_string('host', '0.0.0.0:8080', 'Host ip and port.')


def main(argv):
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=5))
    grpc_hello_pb2_grpc.add_HelloServiceServicer_to_server(
        hello_server_py.HelloServiceImpl(), server)
    server.add_insecure_port(FLAGS.host)
    server.start()

    logging.info('Server listening on ' + FLAGS.host)

    server.wait_for_termination()


if __name__ == '__main__':
    app.run(main)
