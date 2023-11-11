#include <grpcpp/grpcpp.h>
#include "todo.grpc.pb.h"
#include <string>

void addItemToTodo(std::string text)
{
    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel("localhost:0077", grpc::InsecureChannelCredentials());
    std::unique_ptr<Todo::Stub> stub = Todo::NewStub(channel);
    grpc::ClientContext context;
    grpc::Status status;
    TodoItem todoItem;
    TodoItem newTodoItem;
    TodoItems newTodoItems;

    todoItem.set_id(newTodoItems.items_size() + 1);
    todoItem.set_text(text);

    // Use stub to call RPC methods
    status = stub->createTodo(&context, todoItem, &newTodoItem);

    if (status.ok())
    {
        std::cout << "successful" << std::endl;
        // std::cout << "Add new id: " << newTodoItem.id() << " with " << newTodoItem.text() << std::endl;
    }
    else
    {
        std::cerr << "Error code: " << status.error_code() << std::endl;
        std::cerr << "Error details: " << status.error_details() << std::endl;
        if (!status.error_message().empty())
        {
            std::cerr << "Error message: " << status.error_message() << std::endl;
        }
        else
        {
            std::cerr << "No Error message" << std::endl;
        }
    }
}

void getAllTodo()
{
    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel("localhost:0077", grpc::InsecureChannelCredentials());
    std::unique_ptr<Todo::Stub> stub = Todo::NewStub(channel);
    grpc::Status status;
    grpc::ClientContext context;
    TodoItems newTodoItems;
    NoParams request;

    status = stub->readTodoStream(&context, request, &newTodoItems);

    if (status.ok())
    {
        if (newTodoItems.items_size() > 0)
        {
            for (int i = 0; i < newTodoItems.items_size(); ++i)
            {
                const TodoItem &item = newTodoItems.items(i);
                std::cout << "Item ID: " << item.id() << ", Title: " << item.text() << std::endl;
            }
        }
        else
        {
            std::cout << "No to-do items received." << std::endl;
        }
    }
    else
    {
        std::cerr << "Error code: " << status.error_code() << std::endl;
        std::cerr << "Error details: " << status.error_details() << std::endl;
        if (!status.error_message().empty())
        {
            std::cerr << "Error message: " << status.error_message() << std::endl;
        }
        else
        {
            std::cerr << "No Error message" << std::endl;
        }
    }
}

int main(int argc, char **argv)
{
    std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel("localhost:0077", grpc::InsecureChannelCredentials());
    // std::unique_ptr<Todo::Stub> stub = Todo::NewStub(channel);

    addItemToTodo("Hello world");
    addItemToTodo("Hello Bro");
    getAllTodo();

    return 0;
}
