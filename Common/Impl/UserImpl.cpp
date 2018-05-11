//
// Created by bartek on 08.05.18.
//

#include "UserImpl.hpp"
#include <iostream>


UserImpl::UserImpl(std::string name)
{
    this->name = name;
}

void UserImpl::SendMessage(const Chat::RoomPrx& where, const Chat::UserPrx& who, const std::string& message, const Ice::Current& current)
{
    std::cout << where->getName() << " - " << who->getName() << std::endl << "\t" << message;
}

void UserImpl::SendPrivateMessage(const Chat::UserPrx& who, const std::string& message, const Ice::Current& current)
{
    std::cout << who->getName() << std::endl << "\t" << message;
}

std::string UserImpl::getName(const Ice::Current& current)
{
    return this->name;
}