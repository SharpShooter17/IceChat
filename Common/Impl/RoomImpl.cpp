//
// Created by bartek on 08.05.18.
//

#include "RoomImpl.hpp"
#include "Auth.hpp"

RoomImpl::RoomImpl(std::string name)
{
    this->name = name;
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
    if ( !Auth::auth(who->getName(), password) )
    {
        throw Chat::AuthenticationFailed();
    }

    this->userList.push_back(who);
    std::cout << "User: " << who->getName() << "was added to the room: " << this->name << std::endl;
}

void RoomImpl::SendMessage(std::shared_ptr<Chat::UserPrx> who, std::string message, std::string passwd, const Ice::Current& current)
{
    if ( !Auth::auth(who->getName(), passwd) )
    {
        throw Chat::AuthenticationFailed();
    }

    std::cout << "Sending message\n";
    for (auto userPrx : this->userList)
    {
      //  userPrx->SendMessage(this, who, message);
    }
}

void RoomImpl::Destroy(const Ice::Current& current)
{
    std::cout << "Destroying room: " << this->name << std::endl;
    this->userList.clear();
}

void RoomImpl::LeaveRoom(std::shared_ptr<Chat::UserPrx> who, std::string passwd, const Ice::Current& current)
{
    if ( !Auth::auth(who->getName(), passwd) )
    {
        throw Chat::AuthenticationFailed();
    }

    std::cout << "User: " << who->getName() << " leave room" << std::endl;
   // this->userList.erase(who);
}