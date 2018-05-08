//
// Created by bartek on 07.05.18.
//

#include "ServerMain.hpp"
#include "../Common/chat.h"
#include "../Common/Impl/ServerImpl.hpp"
#include <iostream.h>

int ServerMain::run(int, char **)
{
    Ice::ObjectAdapterPtr adapterPtr = communicator()->createObjectAdapterWithEndpoints("SimpleAdapter", "default -p 10000");
    Chat::ServerPtr serverPtr = new ServerImpl();
    adapterPtr->add(serverPtr, communicator()->stringToIdentity("MainServer"));
    adapterPtr->activate();

    communicator()->waitForShutdown();
    std::cout << "Main server is shutdown!" << std::endl;
    return 0;
}