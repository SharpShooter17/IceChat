//
// Created by bartek on 12.05.18.
//

#include "Auth.hpp"

std::map<std::string, std::string> Auth::registeredUsers;

bool Auth::auth(std::string name, std::string password)
{
    auto user = Auth::registeredUsers.find(name);

    if (user == Auth::registeredUsers.end() || user->second != password )
    {
        return false;
    }

    return true;
}

void Auth::changePassword(std::string name, std::string oldpassword, std::string password)
{
    if ( !Auth::auth(name, oldpassword) )
    {
        throw Chat::AuthenticationFailed();
    }

    auto user = Auth::registeredUsers.find(name);

    user->second = password;
}

void Auth::registerUser(std::string name, std::string password)
{
    if ( Auth::auth(name, password) == true )
    {
        throw Chat::UserAlreadyExists();
    }

    Auth::registeredUsers.insert( std::pair<std::string, std::string>(name, password) );
}