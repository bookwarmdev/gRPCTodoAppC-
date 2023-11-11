#include <grpcpp/grpcpp.h>
#include <string>
#include "todo.grpc.pb.h"
#include <string>

using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

class TodoService final : public Todo::Service
{
    static std::vector<TodoItem> todoList;

public:
    Status createTodo(ServerContext *context, const TodoItem *request, TodoItem *response)
    {

        response->set_id(request->id());
        response->set_text(request->text());
        todoList.push_back(*response);
        return Status::OK;
    }

public:
    Status readTodoStream(ServerContext *context, const NoParams *request, TodoItems *response)
    {
        return Status::OK;
    }
};

void RunService()
{
    std::string server_address("0.0.0.0:0077");
    TodoService service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
}

int main(int argc, char **argv)
{
    RunService();
    return 0;
}