//
// Created by bartek on 07.05.18.
//
#include "ServerImpl.hpp"
#include "RoomFactoryImpl.hpp"
#include "UserImpl.hpp"
#include <iostream>

Chat::RoomPrx ServerImpl::CreateRoom(const std::string& name, const Ice::Current& current)
{
    for (Chat::RoomPrx room : this->roomList)
    {
        if (room->getName() == name){
            throw Chat::RoomAlreadyExists();
        }
    }

    if (this->roomList.empty())
    {
        throw Chat::NoRoomsAvailable();
    }

    Chat::RoomFactoryPrx roomFactoryPrx = this->roomFactoryList.back();

    std::cout << "Crating room: " << name << std::endl;

    Chat::RoomPrx roomPrx = roomFactoryPrx->createRoom(name);
    this->roomList.push_back(roomPrx);

    return roomPrx;
}

Chat::RoomList ServerImpl::getRooms(const Ice::Current& current)
{
    return this->roomList;
}

Chat::RoomPrx ServerImpl::FindRoom(const std::string& name, const Ice::Current& current)
{
    for ( Chat::RoomPrx & roomPrx : this->roomList)
    {
        if ( roomPrx->getName() == name )
        {
            return roomPrx;
        }
    }

    throw Chat::RoomNotExists();
}

void ServerImpl::RegisterUser(const std::string& name, const std::string& password, const Ice::Current& current)
{
    for (Chat::UserPrx user : this->userList)
    {
        if (user->getName() == name)
        {
            throw Chat::UserAlreadyExists();
        }
    }

    Ice::Identity id;
    id.name = name;

    Chat::UserPtr newUserPtr = new UserImpl(name);
    Chat::UserPrx userPrx = userPrx.uncheckedCast( current.adapter->add(newUserPtr, id) );

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
    this->roomFactoryList.push_back(factory);
}

void ServerImpl::UnregisterRoomFactory(const Chat::RoomFactoryPrx& factory, const Ice::Current& current)
{
    this->roomFactoryList.erase(factory);
}
