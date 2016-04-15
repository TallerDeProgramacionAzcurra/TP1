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

ServerSocket::ServerSocket(int serverPort, int serverBacklog) : Socket() {
    this->serverPort = serverPort;
    this->serverBacklog = serverBacklog;
    
    printf("ServerSocket.cpp - Socket creado con FD: %i. Puerto asociado: %i.\n", this->socketFD, this->serverPort);
}


struct sockaddr_in ServerSocket::serverSocketGetAddress() {
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(this->serverPort);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    memset(&(serverAddress.sin_zero), 0, sizeof(serverAddress.sin_zero));
    return serverAddress;
}

void ServerSocket::serverSocketBind() {
    struct sockaddr_in  serverAddress = this->serverSocketGetAddress();
    
    int result = bind(this->socketFD, (struct sockaddr *)&serverAddress, sizeof(struct sockaddr));
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
    
    printf("ServerSocket.cpp - Escuchando conexiones. SocketFD: %i. Backlog: %i\n", this->socketFD, this->serverBacklog);
}

int ServerSocket::serverSocketAcceptConnection() {
    struct sockaddr_in clientAddress;
    socklen_t addressInSize = sizeof(struct sockaddr_in);
    
    int clientFD = accept(this->socketFD, (struct sockaddr *)&clientAddress, &addressInSize);
    if (clientFD == kSocketError) {
        printf("ServerSocket.cpp - Socket accept error:%s\n", strerror(errno));
        this->socketClose();
        exit(1);
    }
    
    printf("ServerSocket.cpp - Conexión entrante acceptada. ServerFD: %i. ClientFD: %i\n", this->socketFD, clientFD);
    
    return clientFD;
}
