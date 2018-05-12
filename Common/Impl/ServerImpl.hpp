//
// Created by bartek on 07.05.18.
//

#ifndef ICECHAT_SERVERIMPL_HPP
#define ICECHAT_SERVERIMPL_HPP

#include <Ice/Ice.h>
#include "../chat.h"
#include <map>

class ServerImpl : public virtual Chat::Server
{
public:
    virtual std::shared_ptr<Chat::RoomPrx> CreateRoom(std::string name, const Ice::Current& current) override;
    virtual Chat::RoomList getRooms(const Ice::Current& current) override;
    virtual std::shared_ptr<Chat::RoomPrx> FindRoom(std::string name, const Ice::Current& current) override;
    virtual void RegisterUser(std::string name, std::string password, const Ice::Current& current) override;
    virtual void ChangePassword(std::shared_ptr<Chat::UserPrx> user, std::string oldpassword, std::string newpassword, const Ice::Current& current) override;
    virtual void getPassword(std::string user, const Ice::Current& current) override;
    virtual void RegisterRoomFactory(std::shared_ptr<Chat::RoomFactoryPrx> factory, const Ice::Current& current) override;
    virtual void UnregisterRoomFactory(std::shared_ptr<Chat::RoomFactoryPrx> factory, const Ice::Current& current) override;

    bool authorize(std::string username, std::string password);

private:
    Chat::RoomList roomList;
    Chat::UserList userList;
    Chat::RoomFactoryList roomFactoryList;

    std::map<std::string, std::string> registeredUsers;

};

#endif //ICECHAT_SERVERIMPL_HPP
