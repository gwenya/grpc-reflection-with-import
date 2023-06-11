# build

```
mkdir build
cd build
cmake ..
cmake --build .
```

# run

```
$ build/cpp/grpc-reflection-with-import
Server listening on 127.0.0.1:9090
```

# expexted

```
$ grpc_cli ls 127.0.0.1:9090
helloworld.import_none.Greeter
helloworld.import_reply.Greeter
helloworld.import_request.Greeter
helloworld.import_both.Greeter
grpc.reflection.v1alpha.ServerReflection
grpc.health.v1.Health

$ grpc_cli ls 127.0.0.1:9090 helloworld.import_none.Greeter
SayHello

$ grpc_cli ls 127.0.0.1:9090 helloworld.import_reply.Greeter
SayHello

$ grpc_cli ls 127.0.0.1:9090 helloworld.import_request.Greeter
SayHello

$ grpc_cli ls 127.0.0.1:9090 helloworld.import_both.Greeter
SayHello
```

# actual

```
$ grpc_cli ls 127.0.0.1:9090
helloworld.import_none.Greeter
helloworld.import_reply.Greeter
helloworld.import_request.Greeter
helloworld.import_both.Greeter
grpc.reflection.v1alpha.ServerReflection
grpc.health.v1.Health

$ grpc_cli ls 127.0.0.1:9090 helloworld.import_none.Greeter
SayHello

$ grpc_cli ls 127.0.0.1:9090 helloworld.import_reply.Greeter
SayHello

$ grpc_cli ls 127.0.0.1:9090 helloworld.import_request.Greeter
SayHello

$ grpc_cli ls 127.0.0.1:9090 helloworld.import_both.Greeter
Service or method helloworld.import_both.Greeter not found.
```