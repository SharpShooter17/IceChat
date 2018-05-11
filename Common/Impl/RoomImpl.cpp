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

void RoomImpl::AddUser(const Chat::UserPrx& who, const std::string& password, const Ice::Current& current)
{
    this->userList.push_back(who);
}

/*TO DO - zabezpieczenie*/
void RoomImpl::SendMessage(const Chat::UserPrx& who, const std::string& message, const std::string& passwd, const Ice::Current& current)
{
    std::cout << "Sending message\n";
    for (Chat::UserPrx userPrx : this->userList)
    {
        userPrx->SendMessage(this, who, message);
    }
}

void RoomImpl::Destroy(const Ice::Current& current)
{
    std::cout << "Destroying room: " << this->name << std::endl;
    this->userList.clear();
}

void RoomImpl::LeaveRoom(const Chat::UserPrx& who, const std::string& passwd, const Ice::Current& current)
{
    std::cout << "User leave room" << std::endl;
    this->userList.erase(who);
}