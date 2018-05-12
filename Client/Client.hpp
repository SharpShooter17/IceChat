//
// Created by bartek on 11.05.18.
//

#ifndef ICECHAT_CLIENT_HPP
#define ICECHAT_CLIENT_HPP

#include <Ice/Ice.h>
#include "../Common/chat.h"

class Client : virtual public Ice::Application
{
public:
    Client(std::string username);
    ~Client();

    virtual int run(int argc, char* argv[]) override;

    void createRoom(std::string name);
    Chat::RoomList getRoomList();
    void leaveRoom();
    void joinToRoom(std::string name);
    void changePassword(std::string password);
    void sendPrivateMessageToUser(std::string name, std::string message);
    void sendMessageToRoom(std::string message);
    void setPassword(std::string password);

private:
    std::shared_ptr<Chat::RoomPrx> roomPrx;
    std::string username;
    std::string password;
    std::shared_ptr<Chat::ServerPrx> serverPrx;
    std::shared_ptr<Chat::UserPrx> userPrx;
    std::shared_ptr<Ice::ObjectAdapter> adapter;
};

#endif //ICECHAT_CLIENT_HPP
