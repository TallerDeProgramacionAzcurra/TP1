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
        
        printf("Socket bind error: %sn\n", strerror(errno));
        exit(1);
    }
    
    printf("Bindeado al puerto: %d\n", this->serverPort);
}

void ServerSocket::serverSocketListenConnections() {
    int result = listen(this->socketFD, this->serverBacklog);
    if (result == kSocketError) {
        printf("Socket listen error:%sn\n", strerror(errno));
        exit(1);
    }
    
    printf("Escuchando conexiones...\n");
}

int ServerSocket::serverSocketAcceptConnection() {
    socklen_t socketLength = sizeof(struct sockaddr_in);
    struct sockaddr_in *addr;
    
    int clientFD = accept(this->socketFD, (struct sockaddr *)&addr, &socketLength);
    if (clientFD == kSocketError) {
        printf("Socket accept error:%sn\n", strerror(errno));
        exit(1);
    }
    
    printf("Conexión entrante acceptada\n");
    
    return clientFD;
}
