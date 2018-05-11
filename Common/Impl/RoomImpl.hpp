//
// Created by bartek on 07.05.18.
//

#ifndef ICECHAT_ROOMIMPL_HPP
#define ICECHAT_ROOMIMPL_HPP

#include <Ice/Ice.h>
#include "../chat.h"

class RoomImpl : public virtual Chat::Room
{
public:
    RoomImpl(std::string name);
    virtual std::string getName(const Ice::Current& current = Ice::emptyCurrent) override ;
    virtual Chat::UserList getUsers(const Ice::Current& current = Ice::emptyCurrent) override ;
    virtual void AddUser(const Chat::UserPrx& who, const std::string& password, const Ice::Current& current = Ice::emptyCurrent) override ;
    virtual void SendMessage(const Chat::UserPrx& who, const std::string& message, const std::string& passwd, const Ice::Current& current = Ice::emptyCurrent) override ;
    virtual void Destroy(const Ice::Current& current = Ice::emptyCurrent) override ;
    virtual void LeaveRoom(const Chat::UserPrx& who, const std::string& passwd, const Ice::Current& current = ::Ice::emptyCurrent) override ;
private:
    std::string name;
    Chat::UserList userList;
};

#endif //ICECHAT_ROOMIMPL_HPP
