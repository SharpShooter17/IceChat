//
// Created by bartek on 11.05.18.
//

#ifndef ICECHAT_UTILS_HPP
#define ICECHAT_UTILS_HPP

#include <vector>

class Utils
{
private:
    static const unsigned short SERVER_PORT = 10000;
    static std::vector<unsigned short> usedPorts;
public:
    static unsigned short getFreePort();
    static unsigned short getServerPort();
    static unsigned short getRandomPort();
};

#endif //ICECHAT_UTILS_HPP
