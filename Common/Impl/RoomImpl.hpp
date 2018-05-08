//
// Created by bartek on 07.05.18.
//

#ifndef ICECHAT_ROOMIMPL_HPP
#define ICECHAT_ROOMIMPL_HPP

#include "../chat.h"

class RoomImpl : public virtual Chat::Room
{
public:
    virtual std::string getName(const ::Ice::Current& current = ::Ice::emptyCurrent);
    virtual UserList getUsers(const ::Ice::Current& current = ::Ice::emptyCurrent);
    virtual void AddUser(const UserPrx& who, const ::std::string& password, const ::Ice::Current& current = ::Ice::emptyCurrent);
    virtual void SendMessage(const UserPrx& who, const ::std::string& message, const ::std::string& passwd, const ::Ice::Current& current = ::Ice::emptyCurrent);
    virtual void Destroy(const ::Ice::Current& current = ::Ice::emptyCurrent);
    virtual void LeaveRoom(const UserPrx& who, const ::std::string& passwd, const ::Ice::Current& current = ::Ice::emptyCurrent);
private:
    std::string name;
    Chat::UserList userList;
};

#endif //ICECHAT_ROOMIMPL_HPP
