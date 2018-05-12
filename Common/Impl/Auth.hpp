//
// Created by bartek on 12.05.18.
//

#ifndef ICECHAT_AUTH_HPP
#define ICECHAT_AUTH_HPP

#include "../chat.h"

class Auth
{
private:
    static std::map<std::string, std::string> registeredUsers;

public:
    static bool auth(std::string name, std::string password);
    static void registerUser(std::string name, std::string password);
    static void changePassword(std::string name, std::string oldpassword, std::string password);
};

#endif //ICECHAT_AUTH_HPP
