[gRPC and Protocol Buffers][get started] <br>
[set up][build and locally install gRPC from source]

<h3>Todo App</h3>
to generate your grpc.pb.cc, grpc.pb.hh pb.cc, pb.h run the blow command <br>
$ protoc -I=. --cpp_out=. todo.proto <br>
$ protoc -I=. --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` todo.proto <br>

<h3> To run the your grpc cline and server</h3>
[set up][build and locally install gRPC from source]
1. Follow the Quick start instructions to build and locally install gRPC from source. <br>
2. Run cmake <br>
$ mkdir -p cmake/build <br>
$ cd cmake/build <br>
$ cmake ../.. <br>

[get started]: https://grpc.io/docs/languages/cpp/basics/ 
[build and locally install gRPC from source]: https://grpc.io/docs/languages/cpp/quickstart/#install-grpc
