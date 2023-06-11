#ifndef GRPC_REFLECTION_WITH_IMPORT_GREETERIMPORTNONE_HPP
#define GRPC_REFLECTION_WITH_IMPORT_GREETERIMPORTNONE_HPP

#include "service-import-none.grpc.pb.h"
#include <grpcpp/grpcpp.h>

namespace helloworld::import_none {
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
#endif // GRPC_REFLECTION_WITH_IMPORT_GREETERIMPORTNONE_HPP
