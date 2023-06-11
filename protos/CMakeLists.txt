find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)


set(PROTO_FILES
        reply.proto
        request.proto
        service-import-both.proto
        service-import-none.proto
        service-import-reply.proto
        service-import-request.proto
        )

add_library(protos ${PROTO_FILES})
target_link_libraries(protos
        PUBLIC
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++
        )
target_include_directories(protos PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
protobuf_generate(TARGET protos
        DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        LANGUAGE cpp
        )
protobuf_generate(TARGET protos
        DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        LANGUAGE grpc
        GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc
        PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}"
        )