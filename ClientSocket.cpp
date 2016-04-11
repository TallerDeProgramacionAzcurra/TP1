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
}

struct sockaddr_in ClientSocket::getServerAddress() {
    struct sockaddr_in newAddr;
    newAddr.sin_family = AF_INET;
    newAddr.sin_port = htons(this->socketServerPort);
    inet_pton(AF_INET, this->socketServerAddress.c_str(), &newAddr.sin_addr);
    memset(&(newAddr.sin_zero), 0, sizeof(newAddr.sin_zero));
    return newAddr;
};

void ClientSocket::clientSocketConnect() {
    struct sockaddr_in serverAddress = this->getServerAddress();
    struct sockaddr *address = (struct sockaddr *)&serverAddress;
    socklen_t addressSize = sizeof(struct sockaddr);
    
    int result = connect(this->socketFD, address, addressSize);
    if (result == kSocketError) {
        printf("Socket Connect error: %sn\n", strerror(errno));
        exit(1);
    }
    
    printf("Se conectó correctamente a la dirección: %s y puerto %d\n", this->socketServerAddress.c_str(), this->socketServerPort);
}

//struct sockaddr_in ClientSocket::socketGetAddr(int port) {
//    struct sockaddr_in newAddr;
//    newAddr.sin_family = AF_INET;
//    newAddr.sin_port = htons(port);
//    memset(&(newAddr.sin_zero), 0, sizeof(newAddr.sin_zero));
//    return newAddr;
//}
//
//void ClientSocket::socketConnect(const std::string address, int port) {
//    struct sockaddr_in server_addr = socketGetAddr(port);
//    inet_pton(AF_INET, address.c_str(), &server_addr.sin_addr);
//    
//    struct sockaddr *addr = (struct sockaddr *)&server_addr;
//    socklen_t addr_size = sizeof(struct sockaddr);
//    
//    if (connect(socketGetFileDescriptor(), addr, addr_size) == SOCKET_ERROR) {
//        perror("Socket listen error");
//        printf("Socket listen error:%sn\n", strerror(errno));
//        exit(1);
//    }
//    
//    printf("Se conectó correctamente a la dirección: %s y puerto %d\n", address.c_str(), port);
//}