#include "GreeterImportBoth.hpp"
#include "GreeterImportNone.hpp"
#include "GreeterImportReply.hpp"
#include "GreeterImportRequest.hpp"
#include <grpcpp/grpcpp.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>


int main() {
  std::string server_address("127.0.0.1:9090");
  helloworld::import_none::GreeterImpl greeter_import_none{};
  helloworld::import_reply::GreeterImpl greeter_import_reply{};
  helloworld::import_request::GreeterImpl greeter_import_request{};
  helloworld::import_both::GreeterImpl greeter_import_both{};
  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  ::grpc::ServerBuilder builder;
  builder.AddListeningPort(server_address, ::grpc::InsecureServerCredentials());
  builder.RegisterService(&greeter_import_none);
  builder.RegisterService(&greeter_import_reply);
  builder.RegisterService(&greeter_import_request);
  builder.RegisterService(&greeter_import_both);
  std::unique_ptr<::grpc::Server> server{builder.BuildAndStart()};
  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();
}