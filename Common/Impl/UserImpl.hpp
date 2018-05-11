//
// Created by bartek on 08.05.18.
//

#ifndef ICECHAT_USERIMPL_HPP
#define ICECHAT_USERIMPL_HPP

#include "../chat.h"

class UserImpl : virtual public Chat::User
{
public:
    UserImpl(std::string name);
    virtual void SendMessage(const Chat::RoomPrx& where, const Chat::UserPrx& who, const std::string& message, const Ice::Current& current = Ice::emptyCurrent) override;
    virtual void SendPrivateMessage(const Chat::UserPrx& who, const std::string& message, const Ice::Current& current = Ice::emptyCurrent) override;
    virtual std::string getName(const Ice::Current& current = Ice::emptyCurrent)override;
private:
    std::string name;
};

#endif //ICECHAT_USERIMPL_HPP
