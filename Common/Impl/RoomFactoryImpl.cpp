//
// Created by bartek on 08.05.18.
//

#include "RoomFactoryImpl.hpp"


Chat::RoomPrx RoomFactoryImpl::createRoom(const std::string& name, const Ice::Current& current)
{
    return Chat::RoomPrx;
}
Chat::RoomList RoomFactoryImpl::getRooms(const Ice::Current& current)
{
    return this->roomList;
}