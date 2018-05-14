//
// Created by bartek on 11.05.18.
//
#include <unistd.h>
#include "Client.hpp"
#include <cstring>


void test(Client & client)
{
    std::cout << "Start test" << std::endl;

    client.changePassword(std::string("password"));

    client.createRoom("FirstRoom");
    client.createRoom("SecondRoom");

    std::cout << "Available rooms: " << std::endl;
    for (auto & roomPrx : client.getRoomList())
    {
        std::cout << '\t' << roomPrx->getName() << std::endl;
    }

    client.joinToRoom("FirstRoom");
    sleep(2);
    client.sendMessageToRoom("Hello, how are you?");
    sleep(3);
    client.leaveRoom();

    std::cout << "End test" << std::endl;
}

void test2(Client & client)
{
    std::cout << "Start test2" << std::endl;

    sleep(2);

    client.joinToRoom("FirstRoom");

    sleep(2);

    client.sendMessageToRoom("Hello, I am fine and you?");

    Chat::RoomList rooms = client.getRoomList();

    for (auto room : rooms)
    {
        for (auto user : room->getUsers())
        {
            client.sendPrivateMessageToUser(user, "SPAM MESSAGE!!!!");
        }
    }


    client.leaveRoom();

    std::cout << "End test 2" << std::endl;
}

int main(int argc, char* argv[])
{
    Client client;

    if (strcmp(argv[3], "1") == 0)
    {
        client.setFunction(test);
    }
    else
    {
        client.setFunction(test2);
    }
    return client.main(argc, argv);
}