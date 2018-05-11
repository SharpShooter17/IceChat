//
// Created by bartek on 11.05.18.
//

#include "Utils.hpp"

unsigned short Utils::getFreePort()
{
    unsigned short port;

    if ( usedPorts.empty() )
    {
        port = SERVER_PORT + 1;
    } else
    {
        port = usedPorts.back() + 1;
    }

    usedPorts.push_back(port);

    return port;
}

unsigned short Utils::getServerPort()
{
    return SERVER_PORT;
}