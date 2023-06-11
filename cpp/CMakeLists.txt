set(CMAKE_CXX_STANDARD 23)

add_executable(grpc-reflection-with-import
        src/main.cpp
        )

target_include_directories(grpc-reflection-with-import PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")


target_link_libraries(grpc-reflection-with-import PRIVATE protos grpc++ grpc++_reflection grpc++)
