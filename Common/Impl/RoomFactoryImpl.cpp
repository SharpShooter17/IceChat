//
// Created by bartek on 08.05.18.
//

#include "RoomFactoryImpl.hpp"
#include "RoomImpl.hpp"

Chat::RoomPrx RoomFactoryImpl::createRoom(const std::string& name, const Ice::Current& current)
{
    Ice::Identity identity;

    identity.name = name;

    if (!current.adapter->find(identity))
    {
        throw Chat::RoomAlreadyExists();
    }

    Chat::RoomPtr roomPtr = new RoomImpl(name);
    Chat::RoomPrx roomPrx = roomPrx.uncheckedCast(current.adapter->add(roomPtr, identity));
    this->roomList.push_back(roomPrx);

    std::cout << "Room - " << name << " - has been added" << std::endl;

    return roomPrx;
}
Chat::RoomList RoomFactoryImpl::getRooms(const Ice::Current& current)
{
    return this->roomList;
}