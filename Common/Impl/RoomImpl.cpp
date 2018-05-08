//
// Created by bartek on 08.05.18.
//

#include "RoomImpl.hpp"

std::string RoomImpl::getName(const ::Ice::Current& current = ::Ice::emptyCurrent)
{
    return this->name;
}

UserList RoomImpl::getUsers(const ::Ice::Current& current = ::Ice::emptyCurrent)
{
    return this->userList;
}

void RoomImpl::AddUser(const UserPrx& who, const ::std::string& password, const ::Ice::Current& current = ::Ice::emptyCurrent)
{

}

void RoomImpl::SendMessage(const UserPrx& who, const ::std::string& message, const ::std::string& passwd, const ::Ice::Current& current = ::Ice::emptyCurrent)
{

}

void RoomImpl::Destroy(const ::Ice::Current& current = ::Ice::emptyCurrent)
{

}

void RoomImpl::LeaveRoom(const UserPrx& who, const ::std::string& passwd, const ::Ice::Current& current = ::Ice::emptyCurrent)
{
    
}