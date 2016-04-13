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
    ServerSocket serverSocket(kSocketPort, kSocketBacklog);
    serverSocket.serverSocketBind();
    serverSocket.serverSocketListenConnections();
    
    int clientSocketFD = serverSocket.serverSocketAcceptConnection();

    std::string dataToSend = "Socket server envía datos al cliente.";
    size_t result = send(clientSocketFD, dataToSend.c_str(), dataToSend.size(), 0);
    printf("El server envío %lu/%lu datos al cliente del texto: %s\n", result, dataToSend.size(), dataToSend.c_str());

    close(clientSocketFD);
    serverSocket.socketShutdown();
    
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
