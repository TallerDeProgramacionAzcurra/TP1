//
//  ClientSocket.cpp
//  TP1
//
//  Created by Gaston Montes on 11/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "ClientSocket.hpp"

ClientSocket::~ClientSocket() {
    printf("ClientSocket.cpp - Destructor for socketFD: %i\n", this->socketFD);
}

ClientSocket::ClientSocket(const std::string serverAddress, int serverPort) : Socket() {
    printf("ClientSocket.cpp - Constructor for socketFD: %i. Address: %s:%i\n", this->socketFD, serverAddress.c_str(), serverPort);
    this->socketServerAddress = serverAddress;
    this->socketServerPort = serverPort;
}

struct sockaddr_in ClientSocket::getServerAddress() {
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(this->socketServerPort);
    serverAddress.sin_addr.s_addr = inet_addr(this->socketServerAddress.c_str());
    memset(&(serverAddress.sin_zero), 0, sizeof(serverAddress.sin_zero));
    return serverAddress;
}

void ClientSocket::clientSocketConnect() {
    struct sockaddr_in serverAddress = this->getServerAddress();
    struct sockaddr *address = (struct sockaddr *)&serverAddress;
    socklen_t addressSize = sizeof(struct sockaddr);
    
    int result = connect(this->socketFD, address, addressSize);
    if (result == kSocketError) {
        printf("ClientSocket.cpp - Socket Connect error: %s\n", strerror(errno));
        this->socketClose();
        exit(1);
    }
    
    printf("ClientSocket.cpp - Se conectó correctamente a la dirección: %s y puerto %d\n", this->socketServerAddress.c_str(), this->socketServerPort);
}
