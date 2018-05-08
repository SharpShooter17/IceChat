//
// Created by bartek on 08.05.18.
//

#include "UserImpl.hpp"

void UserImpl::SendMessage(const RoomPrx& where, const UserPrx& who, const ::std::string& message, const ::Ice::Current& current = ::Ice::emptyCurrent)
{

}

void UserImpl::SendPrivateMessage(const UserPrx& who, const ::std::string& message, const ::Ice::Current& current = ::Ice::emptyCurrent)
{

}

std::string UserImpl::getName(const ::Ice::Current& current = ::Ice::emptyCurrent)
{
    return this->name;
}