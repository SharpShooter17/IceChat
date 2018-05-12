//
// Created by bartek on 11.05.18.
//
#include "Client.hpp"

void test(Client & client)
{
    std::cout << "Start test" << std::endl;

    client

    client.createRoom("FirstRoom");
    client.createRoom("SecondRoom");

    std::cout << "Available rooms: " << std::endl;
    for (auto & roomPrx : client.getRoomList())
    {
        std::cout << roomPrx->getName() << std::endl;
    }

    client.joinToRoom("FirstRoom");

    client.sendMessageToRoom("Hello, how are you?");

    client.leaveRoom();

    std::cout << "End test" << std::endl;
}

int main(int argc, char* argv[])
{
    Client client;
    client.setFunction(test);

    return client.main(argc, argv);
}