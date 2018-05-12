//
// Created by bartek on 11.05.18.
//
#include "Client.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Client [username]" << std::endl;
        return -1;
    }

    Client client(std::string(argv[1]));

    return 0;
}