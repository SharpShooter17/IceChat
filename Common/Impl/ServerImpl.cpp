//
// Created by bartek on 07.05.18.
//
#include "ServerImpl.hpp"

Chat::RoomPrx ServerImpl::CreateRoom(const std::string& name, const Ice::Current& current)
{
    for (Chat::RoomPrx room : this->roomList)
    {
        if (room->getName == name){
            throw Chat::RoomAlreadyExists;
        }
    }
    /**
     * TO DO - Wrzuć gupe do RoomFactory
     */

    return roomPrx;
}

Chat::RoomList ServerImpl::getRooms(const Ice::Current& current)
{
    return this->roomList;
}

Chat::RoomPrx ServerImpl::FindRoom(const std::string& name, const Ice::Current& current)
{
    return nullptr;
}

void ServerImpl::RegisterUser(const std::string& name, const std::string& password, const Ice::Current& current)
{
    for (Chat::User user : this->userList)
    {
        if (user.getName() == name)
        {
            throw Chat::UserAlreadyExists;
        }
    }

    Chat::UserPrx userPrx = new UserImpl(name);
    this->userList.push_back(userPrx);
}

void ServerImpl::ChangePassword(const Chat::UserPrx& user, const std::string& oldpassword, const std::string& newpassword, const Ice::Current& current)
{

}

void ServerImpl::getPassword(const std::string& user, const Ice::Current& current)
{

}

void ServerImpl::RegisterRoomFactory(const Chat::RoomFactoryPrx& factory, const Ice::Current& current)
{

}

void ServerImpl::UnregisterRoomFactory(const Chat::RoomFactoryPrx& factory, const Ice::Current& current)
{

}
