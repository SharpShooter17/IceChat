CC=gcc
ODIR=obj

all: server

server: server
	$(CC) -o server "Common/chat.cpp" "Server/main.cpp" "Server/ServerMain.cpp" -lIce -lIceUtil -lpthread -lboosts_program_options
