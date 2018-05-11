//
// Created by bartek on 11.05.18.
//

#ifndef ICECHAT_CLIENT_HPP
#define ICECHAT_CLIENT_HPP

#include <Ice/Ice.h>

class Client : virtual public Ice::Application
{
    void run(int argc, char* argv[]);
};

#endif //ICECHAT_CLIENT_HPP
