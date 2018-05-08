//
// Created by bartek on 08.05.18.
//

#ifndef ICECHAT_ROOMFACTORYIMPL_HPP
#define ICECHAT_ROOMFACTORYIMPL_HPP

#include "../chat.h"

class RoomFactoryImpl : virtual public Chat::RoomFactory
{
public:
    virtual Chat::RoomPrx createRoom(const std::string& name, const Ice::Current& current = Ice::emptyCurrent);
    virtual Chat::RoomList getRooms(const Ice::Current& current = Ice::emptyCurrent);
private:
    Chat::RoomList roomList;
};

#endif //ICECHAT_ROOMFACTORYIMPL_HPP
