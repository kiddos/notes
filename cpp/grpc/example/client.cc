#include <grpcpp/grpcpp.h>

#include "example.grpc.pb.h"

using grpc::ClientContext;
using grpc::Status;

int main(void) {
  auto channel =
      grpc::CreateChannel("localhost:50050", grpc::InsecureChannelCredentials());
  std::unique_ptr<Greeter::Stub> stub = Greeter::NewStub(channel);

  HelloRequest request;
  request.set_name("world");

  HelloReply reply;
  ClientContext context;
  Status status = stub->SayHello(&context, request, &reply);

  if (status.ok()) {
    std::cout << reply.message() << std::endl;
  } else {
    std::cout << status.error_code() << ": " << status.error_message()
              << std::endl;
  }

  return 0;
}
