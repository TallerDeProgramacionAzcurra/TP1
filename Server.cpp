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

static int const kSocketPort = 43210;
static int const kSocketBacklog = 10;

int main(int argc, const char * argv[]) {
    ServerSocket serverSocket(kSocketPort, kSocketBacklog);
    
    char inputChar;
    std::cin >> inputChar;
    
    while (inputChar != 'q' && inputChar != 'Q') {
        std::cin >> inputChar;
    }
    
    serverSocket.socketShutdown();
    
    return 0;
}

//    ServerThread serverThread(serverSock);
//    if (inputChar == 'q') {
//        serverSock.socketSetKeepTalking(false);
//        serverThread.threadJoin();
//    }
//
//}
