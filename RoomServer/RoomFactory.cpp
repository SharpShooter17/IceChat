//
// Created by bartek on 11.05.18.
//

#include "RoomFactory.hpp"
#include "ProxyException.hpp"

int RoomFactory::run(int, char **)
{
    std::cout << "Room server starting.. \n";

    Ice::ObjectPrx proxy = communicator()->stringToProxy("Server:default -p 10000");
    Chat::ServerPrx serverPrx = Chat::ServerPrx::checkedCast(proxy);

    if (serverPrx == nullptr)
    {
        throw ProxyException();
    }

    Ice::ObjectAdapterPtr adapterPtr = communicator()->createObjectAdapterWithEndpoints("RoomFactoryServer", "default -p 56155");
    Chat::RoomFactoryPtr roomFactoryPtr =  new RoomFactoryImpl();
    Chat::RoomFactoryPrx roomFactoryPrx = Chat::RoomFactoryPrx::uncheckedCast(adapterPtr->addWithUUID(roomFactoryPtr));
    adapterPtr->add(roomFactoryPtr, communicator()->stringToIdentity("RoomFactorServer"));
    adapterPtr->activate();

    serverPrx->RegisterRoomFactory(roomFactoryPrx);

    communicator()->waitForShutdown();

    serverPrx->UnregisterRoomFactory(roomFactoryPrx);

    std::cout << "Room server server is shutdown!" << std::endl;
    return 0;
}