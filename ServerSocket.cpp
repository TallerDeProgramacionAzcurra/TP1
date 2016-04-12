//
//  ServerSocket.cpp
//  TP1
//
//  Created by Gaston Montes on 11/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "ServerSocket.hpp"

ServerSocket::~ServerSocket() {
}

struct sockaddr_in ServerSocket::serverSocketGetAddress() {
    struct sockaddr_in newAddr;
    newAddr.sin_family = AF_INET;
    newAddr.sin_port = htons(this->serverPort);
    newAddr.sin_addr.s_addr = INADDR_ANY;
    memset(&(newAddr.sin_zero), 0, sizeof(newAddr.sin_zero));
    return newAddr;
}

void ServerSocket::serverSocketBind() {
    struct sockaddr_in  serverAddress = this->serverSocketGetAddress();
    
    int result = bind(this->socketFD, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    if (result == kSocketError) {
        
        printf("ServerSocket.cpp - Socket bind error: %s\n", strerror(errno));
        this->socketClose();
        exit(1);
    }
    
    printf("ServerSocket.cpp - Bindeado al puerto: %d\n", this->serverPort);
}

void ServerSocket::serverSocketListenConnections() {
    int result = listen(this->socketFD, this->serverBacklog);
    if (result == kSocketError) {
        printf("ServerSocket.cpp - Socket listen error:%s\n", strerror(errno));
        this->socketClose();
        exit(1);
    }
    
    printf("ServerSocket.cpp - Escuchando conexiones...\n");
}

int ServerSocket::serverSocketAcceptConnection() {
    socklen_t socketLength = sizeof(struct sockaddr_in);
    struct sockaddr_in *addr;
    
    printf("ServerSocket.cpp - Accepting connection for socketFD: %i\n",this->socketFD);
    int clientFD = accept(this->socketFD, (struct sockaddr *)&addr, &socketLength);
    if (clientFD == kSocketError) {
        printf("ServerSocket.cpp - Socket accept error:%s\n", strerror(errno));
        this->socketClose();
        exit(1);
    }
    
    printf("ServerSocket.cpp - Conexión entrante acceptada\n");
    
    return clientFD;
}
