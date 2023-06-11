#ifndef GRPC_REFLECTION_WITH_IMPORT_GREETERIMPORTREPLY_HPP
#define GRPC_REFLECTION_WITH_IMPORT_GREETERIMPORTREPLY_HPP

#include "service-import-reply.grpc.pb.h"
#include <grpcpp/grpcpp.h>

namespace helloworld::import_reply {
class GreeterImpl final : public Greeter::Service {
  ::grpc::Status SayHello(::grpc::ServerContext *context,
                          const HelloRequest *request,
                          HelloReply *reply) override {
    std::string prefix("Hello ");
    reply->set_message(prefix + request->name());
    return {};
  }
};
} // namespace helloworld
#endif // GRPC_REFLECTION_WITH_IMPORT_GREETERIMPORTREPLY_HPP
