//
// Created by bartek on 11.05.18.
//
#include "Client.hpp"
#include "../Common/Utils.hpp"
#include <iostream>
#include "../Common/Impl/UserImpl.hpp"
#include "NoPasswordException.hpp"

void Client::initialize(std::string username, std::string password)
{
    std::cout << "Client initialization" << std::endl;

    this->username = username;
    this->setPassword(password);

    std::shared_ptr<Ice::ObjectPrx> object = communicator()->stringToProxy("MainServer:default -p " + std::to_string(Utils::getServerPort()));
    this->serverPrx = Ice::checkedCast<Chat::ServerPrx>(object);

    this->adapter = communicator()->createObjectAdapterWithEndpoints("User_" + this->username, "default -p " + std::to_string(Utils::getRandomPort()));

    Chat::UserPtr userPtr = std::shared_ptr<Chat::User>(new UserImpl(this->username));
    this->userPrx = Ice::uncheckedCast<Chat::UserPrx>( adapter->addWithUUID(userPtr));
    this->adapter->activate();

    try
    {
        this->serverPrx->RegisterUser(this->username, this->password);
    }
    catch (Chat::UserNotExists & ex)
    {
        std::cerr << "User already exists exception" << std::endl;
    }

    std::cout << "Hello, " << this->username << std::endl;
}

void Client::changePassword(std::string password)
{
    this->serverPrx->ChangePassword(this->userPrx, this->password, password);
    this->setPassword(password);
}

void Client::createRoom(std::string name)
{
    this->serverPrx->CreateRoom(name);
}

Chat::RoomList Client::getRoomList()
{
    return this->serverPrx->getRooms();
}

void Client::joinToRoom(std::string name)
{
}

void Client::leaveRoom()
{
    std::cout << "Leave room" << std::endl;
    if ( this->userPrx == nullptr )
    {
        return;
    }

    this->roomPrx->LeaveRoom(this->userPrx, this->password);
    //this->userPrx = std::shared_ptr<Chat::RoomPrx>(nullptr);
}

void Client::sendMessageToRoom(std::string message)
{
    this->roomPrx->SendMessage(this->userPrx, message, this->password);
}

void Client::sendPrivateMessageToUser(std::string name, std::string message)
{

}

void Client::setPassword(std::string password)
{
    std::cout << "Password has been changed" << std::endl;
    this->password = password;
}

int Client::run(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Client [username] [password]" << std::endl;
        return -1;
    }

    this->initialize(argv[1], argv[2]);

    this->fun(*this);

    return 0;
}

Client::~Client()
{
    //this->leaveRoom();
    std::cout << "Client destroy" << std::endl;
}

void Client::setFunction(void (*fun)(Client &))
{
    this->fun = fun;
}