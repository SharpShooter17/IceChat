//
// Created by bartek on 07.05.18.
//

#include "ServerMain.hpp"
#include "../Common/chat.h"
#include "../Common/Impl/ServerImpl.hpp"
#include <iostream>

int ServerMain::run(int, char **)
{
    Ice::ObjectAdapterPtr adapterPtr = communicator()->createObjectAdapterWithEndpoints("SimpleAdapter", "default -p 10000");
    Chat::ServerPtr serverPtr = std::shared_ptr<Chat::Server>(new ServerImpl());
    adapterPtr->add(serverPtr, communicator()->stringToIdentity("MainServer"));
    adapterPtr->activate();

    communicator()->waitForShutdown();
    std::cout << "Main server is shutdown!" << std::endl;
    return 0;
}