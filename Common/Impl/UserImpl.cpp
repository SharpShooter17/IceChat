//
// Created by bartek on 08.05.18.
//

#include "UserImpl.hpp"

void UserImpl::SendMessage(const Chat::RoomPrx& where, const Chat::UserPrx& who, const std::string& message, const Ice::Current& current)
{

}

void UserImpl::SendPrivateMessage(const Chat::UserPrx& who, const std::string& message, const Ice::Current& current)
{

}

std::string UserImpl::getName(const Ice::Current& current)
{
    return this->name;
}