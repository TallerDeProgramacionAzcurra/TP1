//
//  Server.cpp
//  TP1
//
//  Created by Gaston Montes on 11/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <stdio.h>

#include "ServerSocket.hpp"
#include "ServerThread.hpp"

static int const kSocketPort = 43210;
static int const kSocketBacklog = 10;

int main(int argc, const char * argv[]) {
    int serverSocketFD = socket(AF_INET, SOCK_STREAM, 0);
    int yes = 1;
    setsockopt(serverSocketFD, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
    
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(kSocketPort);
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    memset(&(serverAddress.sin_zero), '\0', 8);
    
    bind(serverSocketFD, (struct sockaddr *)&serverAddress, sizeof(struct sockaddr));
    
    listen(serverSocketFD, kSocketBacklog);
    
    struct sockaddr_in clientAddress;
    socklen_t addressInSize = sizeof(struct sockaddr_in);
    int clientSocketFD = accept(serverSocketFD, (struct sockaddr *)&clientAddress, &addressInSize);
    
    std::string dataToSend = "Socket server envía datos al cliente.";
    size_t result = send(clientSocketFD, dataToSend.c_str(), dataToSend.size(), 0);
    printf("El server envío %lu/%lu datos al cliente del texto: %s\n", result, dataToSend.size(), dataToSend.c_str());
    
    close(clientSocketFD);
    close(serverSocketFD);
//
//    ServerThread serverThread(serverSocket);
//    
//    char inputChar = 'a';
//    while (inputChar != 'q' && inputChar != 'Q') {
//        printf("Ingrese la tecla 'Q' para detener la ejecución del Servidor: ");
//        std::cin >> inputChar;
//    }
//    
//    serverSocket.socketShutdown();
//    serverThread.threadStop();
//    serverThread.threadJoin();
    
    return 0;
}
