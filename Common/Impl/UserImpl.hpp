//
// Created by bartek on 08.05.18.
//

#ifndef ICECHAT_USERIMPL_HPP
#define ICECHAT_USERIMPL_HPP

#include <memory>
#include "../chat.h"

class UserImpl : virtual public Chat::User
{
public:
    UserImpl(std::string name);
    virtual void SendMessage(std::shared_ptr<Chat::RoomPrx> where, std::shared_ptr<Chat::UserPrx> who, std::string message, const Ice::Current& current) override;
    virtual void SendPrivateMessage(std::shared_ptr<Chat::UserPrx> who, std::string message, const Ice::Current& current) override;
    virtual std::string getName(const Ice::Current& current) override;
private:
    std::string name;
    std::string password;
};

#endif //ICECHAT_USERIMPL_HPP
