//
// Created by bartek on 11.05.18.
//

#ifndef ICECHAT_ROOMFACTORY_HPP
#define ICECHAT_ROOMFACTORY_HPP

#include "../Common/chat.h"
#include "../Common/Impl/RoomFactoryImpl.hpp"

class RoomFactory : virtual public Ice::Aplication
{
public:
    virtual int run(int, char*[]) override;
};

#endif //ICECHAT_ROOMFACTORY_HPP
