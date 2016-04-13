//
//  Client.cpp
//  TP1
//
//  Created by Gaston Montes on 11/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>

#include "ClientSocket.hpp"
#include "ClientThread.hpp"

static std::string const kSocketAddress = "127.0.0.1";
static int const kSocketPort = 43210;

struct sockaddr_in getServerAddress() {
    struct sockaddr_in newAddr;
    newAddr.sin_family = AF_INET;
    newAddr.sin_port = htons(kSocketPort);
    memset(&(newAddr.sin_zero), 0, sizeof(newAddr.sin_zero));
    inet_pton(AF_INET, kSocketAddress.c_str(), &newAddr.sin_addr);
    return newAddr;
}

//struct sockaddr_in ClientSocket::socketGetAddr(int port) {
//    struct sockaddr_in newAddr;
//    newAddr.sin_family = AF_INET;
//    newAddr.sin_port = htons(port);
//    memset(&(newAddr.sin_zero), 0, sizeof(newAddr.sin_zero));
//    return newAddr;
//}

int main(int argc, const char * argv[]) {
//    ClientSocket clientSocket(kSocketAddress, kSocketPort);
//    clientSocket.clientSocketConnect();
    
    int socketFD = socket(AF_INET, SOCK_STREAM, 0);
    printf("Client.cpp - SocketFD: %i\n", socketFD);
    
    struct sockaddr_in serverAddress = getServerAddress();
    struct sockaddr *address = (struct sockaddr *)&serverAddress;
    socklen_t addressSize = sizeof(struct sockaddr);
    int result = connect(socketFD, address, addressSize);
    printf("Client.cpp - Socket connect: %i\n", result);
    
    
    std::string dataToRecieve = "Socket server envía datos al cliente.";
    std::vector<char> buffer;
    buffer.resize(dataToRecieve.size());
    result = recv(socketFD, &(buffer[0]), dataToRecieve.size(), 0);
    printf("Client.cpp - Receive result: %i\n", result);
    std::string bufferStr(buffer.begin(), buffer.end());
//
//    clientSocket.socketRecieve(dataToSend.size());
//    clientSocket.socketShutdown();
    
    printf("Client.cpp - Datos recibidos: %i/%lu cuyo texto: %s\n", result, dataToRecieve.size(), bufferStr.c_str());
    
//    ClientThread clientThread;
//    
//    printf("Ingrese la tecla 'Q' para detener la ejecución del cliente: ");
//    char inputChar;
//    std::cin >> inputChar;
//    
//    while (inputChar != 'q' && inputChar != 'Q') {
//        std::cin >> inputChar;
//    }
//    
//    clientThread.threadStop();
//    clientThread.threadJoin();
    
    return 0;
}
