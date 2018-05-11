//
// Created by bartek on 07.05.18.
//

#ifndef ICECHAT_MAIN_HPP
#define ICECHAT_MAIN_HPP

#include <Ice/Ice.h>

class ServerMain : virtual public Ice::Application
{
public:
    virtual int run(int, char*[]) override;
};

#endif //ICECHAT_MAIN_HPP
