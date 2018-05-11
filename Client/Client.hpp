//
// Created by bartek on 11.05.18.
//

#ifndef ICECHAT_CLIENT_HPP
#define ICECHAT_CLIENT_HPP

#include <Ice/Ice.h>

class Client : virtual public Ice::Application
{
public:
    virtual int run(int argc, char* argv[]) override;
};

#endif //ICECHAT_CLIENT_HPP
