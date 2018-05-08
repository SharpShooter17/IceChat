//
// Created by bartek on 08.05.18.
//

#include "RoomFactoryImpl.hpp"


RoomPrx RoomFactoryImpl::createRoom(const ::std::string& name, const ::Ice::Current& current = ::Ice::emptyCurrent)
{
    return Chat::RoomPrx;
}
RoomList RoomFactoryImpl::getRooms(const ::Ice::Current& current = ::Ice::emptyCurrent)
{
    return this->roomList;
}