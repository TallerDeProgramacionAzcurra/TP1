//
//  Client.cpp
//  TP1
//
//  Created by Gaston Montes on 11/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

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
    
    std::string dataToRecieve = "Socket server envía datos al cliente.";
    std::vector<char> buffer;
    buffer.resize(dataToRecieve.size());
    size_t result = recv(clientSocket.socketGetFD(), &(buffer[0]), dataToRecieve.size(), 0);
    std::string bufferStr(buffer.begin(), buffer.end());
    
//    clientSocket.socketRecieve(dataToSend.size());
//    clientSocket.socketShutdown();
    
    printf("Client.cpp - Datos rcibidos: %lu/%lu cuyo texto: %s\n", result, dataToRecieve.size(), bufferStr.c_str());
    
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
