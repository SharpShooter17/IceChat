//
// Created by bartek on 08.05.18.
//

#ifndef ICECHAT_USERIMPL_HPP
#define ICECHAT_USERIMPL_HPP

#include "../chat.h"

class UserImpl : virtual public Chat::User
{
public:
    virtual void SendMessage(const Chat::RoomPrx& where, const Chat::UserPrx& who, const std::string& message, const Ice::Current& current = Ice::emptyCurrent);
    virtual void SendPrivateMessage(const Chat::UserPrx& who, const std::string& message, const Ice::Current& current = Ice::emptyCurrent);
    virtual std::string getName(const Ice::Current& current = Ice::emptyCurrent);
private:
    std::string name;
};

#endif //ICECHAT_USERIMPL_HPP
