//
// Created by bartek on 08.05.18.
//

#include "RoomFactoryImpl.hpp"
#include "RoomImpl.hpp"
#include "../Utils.hpp"

RoomFactoryImpl::RoomFactoryImpl(std::shared_ptr <Chat::ServerPrx> serverPrx) :
    serverPrx(serverPrx)
{
}

std::shared_ptr<Chat::RoomPrx> RoomFactoryImpl::createRoom(std::string name, const Ice::Current& current)
{
    std::cout << "Creating room: " << name << std::endl;

    Ice::Identity identity;

    identity.name = name;

    if ( current.adapter->find(identity) != nullptr )
    {
        throw Chat::RoomAlreadyExists();
    }

    Chat::RoomPtr roomPtr = std::shared_ptr<Chat::Room>( new RoomImpl(name, this->serverPrx) );
    std::shared_ptr<Chat::RoomPrx> roomPrx = Ice::uncheckedCast<Chat::RoomPrx>( current.adapter->add(roomPtr, identity));
    this->roomList.push_back(roomPrx);

    std::cout << "Room - " << name << " - has been added" << std::endl;

    return roomPrx;
}
Chat::RoomList RoomFactoryImpl::getRooms(const Ice::Current& current)
{
    return this->roomList;
}