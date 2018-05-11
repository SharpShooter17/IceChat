//
// Created by bartek on 08.05.18.
//

#include "RoomImpl.hpp"

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
    this->userList.push_back(who);
}

/*TO DO - zabezpieczenie*/
void RoomImpl::SendMessage(std::shared_ptr<Chat::UserPrx> who, std::string message, std::string passwd, const Ice::Current& current)
{
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
    std::cout << "User leave room" << std::endl;
   // this->userList.erase(who);
}