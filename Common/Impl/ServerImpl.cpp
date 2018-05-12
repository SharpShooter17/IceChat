//
// Created by bartek on 07.05.18.
//
#include "ServerImpl.hpp"
#include "RoomFactoryImpl.hpp"
#include "UserImpl.hpp"
#include <iostream>

std::shared_ptr<Chat::RoomPrx> ServerImpl::CreateRoom(std::string name, const Ice::Current& current)
{
    for (auto room : this->roomList)
    {
        if (room->getName() == name){
            throw Chat::RoomAlreadyExists();
        }
    }

    if (this->roomList.empty())
    {
        throw Chat::NoRoomsAvailable();
    }

    auto roomFactory = this->roomFactoryList.back();

    std::cout << "Crating room: " << name << std::endl;

    std::shared_ptr<Chat::RoomPrx> roomPrx = roomFactory->createRoom(name);
    this->roomList.push_back(roomPrx);

    return roomPrx;
}

Chat::RoomList ServerImpl::getRooms(const Ice::Current& current)
{
    return this->roomList;
}

std::shared_ptr<Chat::RoomPrx> ServerImpl::FindRoom(std::string name, const Ice::Current& current)
{
    std::cout << "Find Room name: " << name << std::endl;
    for ( auto roomPrx : this->roomList)
    {
        if ( roomPrx->getName() == name )
        {
            return roomPrx;
        }
    }

    throw Chat::RoomNotExists();
}

void ServerImpl::RegisterUser(std::string name, std::string password, const Ice::Current& current)
{
    for (auto user : this->userList)
    {
        if (user->getName() == name)
        {
            throw Chat::UserAlreadyExists();
        }
    }

    Ice::Identity id;
    id.name = name;

    std::shared_ptr<Chat::User> newUserPtr = std::shared_ptr<Chat::User>(new UserImpl(name));
    auto userPrx = Ice::uncheckedCast<Chat::UserPrx>( current.adapter->add(newUserPtr, id) );

    this->userList.push_back(userPrx);

    this->registeredUsers.insert(std::pair<std::string, std::string>(username, password));

    std::cout << "User: " << name << " has been registered" << std::endl;
}

void ServerImpl::ChangePassword(std::shared_ptr<Chat::UserPrx> user, std::string oldpassword, std::string newpassword, const Ice::Current& current)
{
    if ( this->authorize(user->getName(), oldpassword) )
    {
        throw Chat::AuthenticationFailed();
    }

    auto & user = this->registeredUsers.find(user->getName());

    user.second = newpassword;

    std::cout << "Password has been changed" << std::endl;
}

void ServerImpl::getPassword(std::string user, const Ice::Current& current)
{

}

void ServerImpl::RegisterRoomFactory(std::shared_ptr<Chat::RoomFactoryPrx> factory, const Ice::Current& current)
{
    this->roomFactoryList.push_back(factory);
    std::cout << "Room Factory has been registered" << std::endl;
}

void ServerImpl::UnregisterRoomFactory(std::shared_ptr<Chat::RoomFactoryPrx> factory, const Ice::Current& current)
{
    //this->roomFactoryList.erase(factory);
}

bool ServerImpl::authorize(std::string username, std::string password)
{
    auto & user = this->registeredUsers.find(user->getName());

    if (user == this->registeredUsers.end() || user.second != password )
    {
        return false;
    }

    return true;
}