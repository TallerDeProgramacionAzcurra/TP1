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

int main(int argc, const char * argv[]) {
    ClientSocket clientSocket(kSocketAddress, kSocketPort);
    clientSocket.clientSocketConnect();
    
    std::string dataToReceive = "Socket server envía datos al cliente.";
    clientSocket.socketRecieve(dataToReceive.size());
    
    clientSocket.socketShutdown();
    
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
