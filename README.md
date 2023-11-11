[gRPC and Protocol Buffers][get started]

<h3>Todo App</h3>
to generate your grpc.pb.cc, grpc.pb.hh pb.cc, pb.h run the blow command
// protoc -I=. --cpp_out=. todo.proto
// protoc -I=. --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` todo.proto

<h3> To run the your grpc cline and server</h3>
1. Follow the Quick start instructions to build and locally install gRPC from source [build and locally install gRPC from source].
2. Run cmake
$ mkdir -p cmake/build
$ cd cmake/build
$ cmake ../..

[get started]: https://grpc.io/docs/languages/cpp/basics/
[build and locally install gRPC from source]: https://grpc.io/docs/languages/cpp/quickstart/#install-grpc
