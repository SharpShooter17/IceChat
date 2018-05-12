//
// Created by bartek on 11.05.18.
//
#include "Client.hpp"
#include "../Common/Utils.hpp"
#include <iostream>
#include "../Common/Impl/UserImpl.hpp"

Client::Client(std::string username)
{
    std::cout << "Client initialization" << std::endl;

    this->username = username;

    std::shared_ptr<Ice::ObjectPrx> object = communicator()->stringToProxy("Server:default -p " + std::to_string(Utils::getServerPort()));
    this->serverPrx = Ice::checkedCast<Chat::ServerPrx>(object);

    this->adapter = communicator()->createObjectAdapterWithEndpoints("User" +  username, "default -p " + std::to_string(Utils::getRandomPort()));

    Chat::UserPtr userPtr = std::shared_ptr<Chat::User>(new UserImpl(username));
    this->userPrx = Ice::uncheckedCast<Chat::UserPrx>( adapter->addWithUUID(userPtr));
    this->adapter->activate();
}

void Client::changePassword(std::string password)
{
    //this->roomPrx->ChangePassword(this->username, this->password, password);
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
    if ( this->userPrx.get() == nullptr )
    {
        return;
    }

    this->roomPrx->LeaveRoom(this->userPrx, this->password);
    this->userPrx.reset();
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
    return 0;
}

Client::~Client()
{
    this->leaveRoom();
    communicator()->destroy();
}