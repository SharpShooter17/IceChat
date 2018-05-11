//
// Created by bartek on 08.05.18.
//

#ifndef ICECHAT_ROOMFACTORYIMPL_HPP
#define ICECHAT_ROOMFACTORYIMPL_HPP

#include <Ice/Ice.h>
#include "../chat.h"

class RoomFactoryImpl : virtual public Chat::RoomFactory
{
public:
    virtual std::shared_ptr<Chat::RoomPrx> createRoom(std::string name, const Ice::Current& current) override;
    virtual Chat::RoomList getRooms(const Ice::Current& current) override;
private:
    Chat::RoomList roomList;
};

#endif //ICECHAT_ROOMFACTORYIMPL_HPP
