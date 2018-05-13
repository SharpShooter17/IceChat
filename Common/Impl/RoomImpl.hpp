//
// Created by bartek on 07.05.18.
//

#ifndef ICECHAT_ROOMIMPL_HPP
#define ICECHAT_ROOMIMPL_HPP

#include <Ice/Ice.h>
#include "../chat.h"

class RoomImpl : public Chat::Room
{
public:
    RoomImpl(std::string name, std::shared_ptr<Chat::ServerPrx> serverPrx);
    virtual std::string getName(const Ice::Current& current) override;
    virtual Chat::UserList getUsers(const Ice::Current& current) override;
    virtual void AddUser(std::shared_ptr<Chat::UserPrx> who, std::string password, const Ice::Current& current) override;
    virtual void SendMessage(std::shared_ptr<Chat::UserPrx> who, std::string message, std::string passwd, const Ice::Current& current) override;
    virtual void Destroy(const Ice::Current& current) override;
    virtual void LeaveRoom(std::shared_ptr<Chat::UserPrx> who, std::string passwd, const Ice::Current& current) override;
private:
    std::string name;
    Chat::UserList userList;

    std::shared_ptr<Chat::ServerPrx> serverPrx;
};

#endif //ICECHAT_ROOMIMPL_HPP
