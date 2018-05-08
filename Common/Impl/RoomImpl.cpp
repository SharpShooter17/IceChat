//
// Created by bartek on 08.05.18.
//

#include "RoomImpl.hpp"

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

}

void RoomImpl::SendMessage(const Chat::UserPrx& who, const std::string& message, const std::string& passwd, const Ice::Current& current)
{

}

void RoomImpl::Destroy(const Ice::Current& current)
{

}

void RoomImpl::LeaveRoom(const Chat::UserPrx& who, const std::string& passwd, const Ice::Current& current)
{

}