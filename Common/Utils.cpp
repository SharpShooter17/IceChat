//
// Created by bartek on 11.05.18.
//

#include "Utils.hpp"
#include <random>
#include <algorithm>

std::vector<unsigned short> Utils::usedPorts;

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

unsigned short Utils::getRandomPort()
{
    std::random_device rd;
    std::mt19937 mt19937(rd());
    std::uniform_int_distribution<unsigned short> dist(27000, 65231);

    unsigned short port = dist(mt19937);

    if ( std::find(Utils::usedPorts.begin(), Utils::usedPorts.end(), port) == Utils::usedPorts.end() )
    {
        Utils::usedPorts.push_back(port);
        return port;
    }
    else
    {
        return Utils::getRandomPort();
    }
}