//
// Created by bartek on 11.05.18.
//

#ifndef ICECHAT_ROOMFACTORY_HPP
#define ICECHAT_ROOMFACTORY_HPP

#include <Ice/Ice.h>

class RoomFactory : virtual public Ice::Application
{
public:
    virtual int run(int argc, char* argv[]) override;
};

#endif //ICECHAT_ROOMFACTORY_HPP
