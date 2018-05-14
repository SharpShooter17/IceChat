//
// Created by bartek on 08.05.18.
//

#include "RoomImpl.hpp"

RoomImpl::RoomImpl(std::string name, std::shared_ptr<Chat::ServerPrx> serverPrx) :
    name(name),
    serverPrx(serverPrx)
{
}


std::string RoomImpl::getName(const Ice::Current& current)
{
    return this->name;
}

Chat::UserList RoomImpl::getUsers(const Ice::Current& current)
{
    return this->userList;
}

void RoomImpl::AddUser(std::shared_ptr<Chat::UserPrx> who, std::string password, const Ice::Current& current)
{
    if ( !this->serverPrx->auth(who->getName(), password) )
    {
        throw Chat::AuthenticationFailed();
    }

    this->userList.push_back(who);
    std::cout << "User: " << who->getName() << " was added to the room: " << this->name << std::endl;
}

void RoomImpl::SendMessage(std::shared_ptr<Chat::UserPrx> who, std::string message, std::string passwd, const Ice::Current& current)
{
    if ( !this->serverPrx->auth(who->getName(), passwd) )
    {
        throw Chat::AuthenticationFailed();
    }

    std::cout << "Sending message: " << message << std::endl;
    for (auto userPrx : this->userList)
    {
        userPrx->SendMessage(this->name, who, message);
    }
}

void RoomImpl::Destroy(const Ice::Current& current)
{
    std::cout << "Destroying room: " << this->name << std::endl;
    this->userList.clear();
}

void RoomImpl::LeaveRoom(std::shared_ptr<Chat::UserPrx> who, std::string passwd, const Ice::Current& current)
{
    if ( !this->serverPrx->auth(who->getName(), passwd) )
    {
        throw Chat::AuthenticationFailed();
    }

    std::cout << "User: " << who->getName() << " leave room" << std::endl;

    for ( Chat::UserList::iterator it = this->userList.begin(); it != this->userList.end(); it++ )
    {
        if ( *it == who )
        {
            this->userList.erase(it);
            std::cout << "User erased" << std::endl;
            return;
        }
    }
}