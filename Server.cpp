//
//  Server.cpp
//  TP1
//
//  Created by Gaston Montes on 11/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#include <stdio.h>
#include <iostream>

#include "ServerSocket.hpp"
#include "ServerThread.hpp"

static int const kSocketPort = 43210;
static int const kSocketBacklog = 10;

int main(int argc, const char * argv[]) {
    ServerSocket serverSocket(kSocketPort, kSocketBacklog);
    
    ServerThread serverThread(serverSocket);
    
    printf("Ingrese la tecla 'Q' para detener la ejecución del Servidor: ");
    char inputChar;
    std::cin >> inputChar;
    
    while (inputChar != 'q' && inputChar != 'Q') {
        std::cin >> inputChar;
    }
    
    serverSocket.socketShutdown();
    serverThread.threadStop();
    serverThread.threadJoin();
    
    return 0;
}
