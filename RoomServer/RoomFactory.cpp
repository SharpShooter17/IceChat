//
// Created by bartek on 11.05.18.
//

#include "../Common/chat.h"
#include "../Common/Impl/RoomFactoryImpl.hpp"
#include "../Common/Utils.hpp"
#include "RoomFactory.hpp"
#include "ProxyException.hpp"

int RoomFactory::run(int argc, char * argv[])
{
    if (argc != 2)
    {
        std::cerr << "./RoomFactory [name]" << std::endl;
        return -1;
    }

    std::cout << "Room server starting.. \n";

    std::shared_ptr<Ice::ObjectPrx> proxy = communicator()->stringToProxy("MainServer:default -p " + std::to_string(Utils::getServerPort()));
    std::shared_ptr<Chat::ServerPrx> serverPrx = Ice::uncheckedCast<Chat::ServerPrx>(proxy);

    if (serverPrx == nullptr)
    {
        throw ProxyException();
    }

    Ice::ObjectAdapterPtr adapterPtr = communicator()->createObjectAdapterWithEndpoints(argv[1], "default -p " + std::to_string(Utils::getRandomPort()));
    Chat::RoomFactoryPtr roomFactoryPtr =  std::shared_ptr<Chat::RoomFactory>(new RoomFactoryImpl( serverPrx ));
    std::shared_ptr<Chat::RoomFactoryPrx> roomFactoryPrx = Ice::uncheckedCast<Chat::RoomFactoryPrx>(adapterPtr->addWithUUID(roomFactoryPtr));
    adapterPtr->add(roomFactoryPtr, Ice::stringToIdentity("RoomFactorServer"));
    adapterPtr->activate();

    serverPrx->RegisterRoomFactory(roomFactoryPrx);

    communicator()->waitForShutdown();

    serverPrx->UnregisterRoomFactory(roomFactoryPrx);

    std::cout << "Room server server is shutdown!" << std::endl;
    return 0;
}