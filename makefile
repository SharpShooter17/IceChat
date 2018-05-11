CC=c++
ODIR=obj
CFLAGS = -g -Wall -Werror -Wpedantic
LIBSFLAGS = -lpthread -lIce++11 --std=c++11 -DICE_CPP11_MAPPING
TARGETDIR = Debug/
TARGETCLIENT = Debug/Client
TARGETSERVER = Debug/Server
TARGETROOMFACTORY = Debug/RoomFactory
CLIENTSRCDIR = Client
SERVERSRCDIR = Server
ROOMFACTORYSRC = RoomServer
COMMONDIR = Common

INCLUDES = -I $(CLIENTSRCDIR) -I $(ROOMFACTORYSRC) -I $(SERVERSRCDIR) -I $(COMMONDIR)
SRCCOMMON = $(COMMONDIR)/chat.cpp $(COMMONDIR)/Impl/RoomFactoryImpl.cpp $(COMMONDIR)/Impl/RoomImpl.cpp $(COMMONDIR)/Impl/ServerImpl.cpp $(COMMONDIR)/Impl/UserImpl.cpp $(COMMONDIR)/Utils.cpp
SRCCLIENT = $(SRCCOMMON) $(CLIENTSRCDIR)/main.cpp $(CLIENTSRCDIR)/Client.cpp
SRCSERVER = $(SRCCOMMON) $(CLIENTSRC)/main.cpp $(CLIENTSRC)/ServerMain.cpp
SRCROOMFACTORY = $(SRCCOMMON) $(ROOMFACTORYSRC)/main.cpp $(ROOMFACTORYSRC)/RoomFactory.cpp

.PHONY: clean all

all: $(TARGETCLIENT) $($TARGETROOMSERVER) $(TARGETSERVER)

$(TARGETROOMSERVER):
	mkdir -p $(TARGETDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGETSERVER) $(SRCROOMSERVER) $(LIBSFLAGS)

$(TARGETCLIENT):
	mkdir -p $(TARGETDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGETCLIENT) $(SRCCLIENT) $(LIBSFLAGS)

$(TARGETSERVER):
	mkdir -p $(TARGETDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGETSERVER) $(SRCSERVER) $(LIBSFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -o $< -o $@

clean:
	$RM *.o *~$(TARGETCLIENT)
	$RM *.o *~$(TARGETROOMFACTORY)
	$RM *.o *~$(TARGETSERVER)
