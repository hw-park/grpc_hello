from absl import app
from absl import flags
from absl import logging
import grpc
import hello_client_py

FLAGS = flags.FLAGS

flags.DEFINE_string('host', '0.0.0.0:8080', 'Host ip and port.')
flags.DEFINE_string('id', 'darling', 'Id.')


def main(argv):
    client = hello_client_py.HelloServiceClient(
        grpc.insecure_channel(FLAGS.host))
    response_string = client.hello(FLAGS.id)

    logging.info('Message received: ' + response_string)


if __name__ == '__main__':
    app.run(main)
