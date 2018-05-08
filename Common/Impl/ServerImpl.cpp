//
// Created by bartek on 07.05.18.
//
#include "ServerImpl.hpp"

ServerImpl::~ServerImpl()
{
    ::~Server();
}

RoomPrx ServerImpl::CreateRoom(const ::std::string& name, const ::Ice::Current& current = ::Ice::emptyCurrent)
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

RoomList ServerImpl::getRooms(const ::Ice::Current& current = ::Ice::emptyCurrent)
{
    return this->roomList;
}

RoomPrx ServerImpl::FindRoom(const ::std::string& name, const ::Ice::Current& current = ::Ice::emptyCurrent)
{
    return nullptr;
}

void ServerImpl::RegisterUser(const ::std::string& name, const ::std::string& password, const ::Ice::Current& current = ::Ice::emptyCurrent)
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

void ServerImpl::ChangePassword(const UserPrx& user, const ::std::string& oldpassword, const ::std::string& newpassword, const ::Ice::Current& current = ::Ice::emptyCurrent)
{

}

void ServerImpl::getPassword(const ::std::string& user, const ::Ice::Current& current = ::Ice::emptyCurrent)
{

}

void ServerImpl::RegisterRoomFactory(const RoomFactoryPrx& factory, const ::Ice::Current& current = ::Ice::emptyCurrent)
{

}

void ServerImpl::UnregisterRoomFactory(const RoomFactoryPrx& factory, const ::Ice::Current& current = ::Ice::emptyCurrent)
{

}
