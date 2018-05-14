//
// Created by bartek on 08.05.18.
//

#include "UserImpl.hpp"
#include <iostream>


UserImpl::UserImpl(std::string name)
{
    this->name = name;
}

void UserImpl::SendMessage(std::string where, std::shared_ptr<Chat::UserPrx> who, std::string message, const Ice::Current& current)
{
    std::cout << where << " - " << who->getName() << std::endl << "\t" << message;
}

void UserImpl::SendPrivateMessage(std::shared_ptr<Chat::UserPrx> who, std::string message, const Ice::Current& current)
{
    std::cout << who->getName() << std::endl << "\t" << message;
}

std::string UserImpl::getName(const Ice::Current& current)
{
    return this->name;
}