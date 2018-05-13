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

    if (this->roomFactoryList.empty())
    {
        throw Chat::NoRoomFactoryAvailable();
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
    if ( this->auth(name, password, current) == true )
    {
        throw Chat::UserAlreadyExists();
    }

    this->registeredUsers.insert( std::pair<std::string, std::string>(name, password) );

    Ice::Identity id;
    id.name = "User_" + name;

    std::shared_ptr<Chat::User> newUserPtr = std::shared_ptr<Chat::User>(new UserImpl(name));
    auto userPrx = Ice::uncheckedCast<Chat::UserPrx>( current.adapter->add(newUserPtr, id) );

    this->userList.push_back(userPrx);

    std::cout << "User: " << name << " has been registered" << std::endl;
}

void ServerImpl::ChangePassword(std::shared_ptr<Chat::UserPrx> user, std::string oldpassword, std::string newpassword, const Ice::Current& current)
{
    std::string name = user->getName();

    if ( !this->auth(name, oldpassword, current) )
    {
        throw Chat::AuthenticationFailed();
    }

    auto registeredUser = this->registeredUsers.find(name);

    registeredUser->second = newpassword;

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
    for ( Chat::RoomFactoryList::iterator it = this->roomFactoryList.begin(); it != this->roomFactoryList.end(); it++)
    {
        if ( *it == factory )
        {
            this->roomFactoryList.erase(it);
            std::cout << "Room factory has been uregistered" << std::endl;
            return;
        }
    }
}

bool ServerImpl::auth(std::string name, std::string password, const Ice::Current& current)
{
    auto user = this->registeredUsers.find(name);

    if (user == this->registeredUsers.end() || user->second != password )
    {
        return false;
    }

    return true;
}