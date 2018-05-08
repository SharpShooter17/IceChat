//
// Created by bartek on 07.05.18.
//

#ifndef ICECHAT_SERVERIMPL_HPP
#define ICECHAT_SERVERIMPL_HPP

#include <Ice/Ice.h>
#include "../chat.h"

class ServerImpl : public virtual Chat::Server
{
public:
    virtual Chat::RoomPrx CreateRoom(const std::string& name, const Ice::Current& current = Ice::emptyCurrent);
    virtual Chat::RoomList getRooms(const Ice::Current& current = Ice::emptyCurrent);
    virtual Chat::RoomPrx FindRoom(const std::string& name, const Ice::Current& current = Ice::emptyCurrent);
    virtual void RegisterUser(const std::string& name, const std::string& password, const Ice::Current& current = Ice::emptyCurrent);
    virtual void ChangePassword(const Chat::UserPrx& user, const std::string& oldpassword, const std::string& newpassword, const Ice::Current& current = Ice::emptyCurrent);
    virtual void getPassword(const std::string& user, const Ice::Current& current = Ice::emptyCurrent);
    virtual void RegisterRoomFactory(const Chat::RoomFactoryPrx& factory, const Ice::Current& current = Ice::emptyCurrent);
    virtual void UnregisterRoomFactory(const Chat::RoomFactoryPrx& factory, const Ice::Current& current = Ice::emptyCurrent);

private:
    Chat::RoomList roomList;
    Chat::UserList userList;
    std::vector<Chat::RoomFactoryPrx> roomFactoryList;
};

#endif //ICECHAT_SERVERIMPL_HPP
