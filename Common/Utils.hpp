//
// Created by bartek on 11.05.18.
//

#ifndef ICECHAT_UTILS_HPP
#define ICECHAT_UTILS_HPP

#include <vector>

class Utils
{
private:
    static const unsigned int SERVER_PORT = 10000;
    static std::vector<unsigned short> usedPorts;
public:
    static unsigned short getFreePort();
    static unsigned short getServerPort();
};

#endif //ICECHAT_UTILS_HPP
