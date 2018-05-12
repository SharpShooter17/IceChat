//
// Created by bartek on 11.05.18.
//

#include "../Common/chat.h"
#include "../Common/Impl/RoomFactoryImpl.hpp"
#include "RoomFactory.hpp"
#include "ProxyException.hpp"

int RoomFactory::run(int argc, char * argv[])
{
    std::cout << "Room server starting.. \n";

    std::shared_ptr<Ice::ObjectPrx> proxy = communicator()->stringToProxy("Server:default -p 10000");
    std::shared_ptr<Chat::ServerPrx> serverPrx = Ice::uncheckedCast<Chat::ServerPrx>(proxy);

    if (serverPrx == nullptr)
    {
        throw ProxyException();
    }

    Ice::ObjectAdapterPtr adapterPtr = communicator()->createObjectAdapterWithEndpoints("RoomFactoryServer", "default -p 56155");
    Chat::RoomFactoryPtr roomFactoryPtr =  std::shared_ptr<Chat::RoomFactory>(new RoomFactoryImpl());
    std::shared_ptr<Chat::RoomFactoryPrx> roomFactoryPrx = Ice::uncheckedCast<Chat::RoomFactoryPrx>(adapterPtr->addWithUUID(roomFactoryPtr));
    adapterPtr->add(roomFactoryPtr, communicator()->stringToIdentity("RoomFactorServer"));
    adapterPtr->activate();

    serverPrx->RegisterRoomFactory(roomFactoryPrx);

    communicator()->waitForShutdown();

    serverPrx->UnregisterRoomFactory(roomFactoryPrx);

    std::cout << "Room server server is shutdown!" << std::endl;
    return 0;
}