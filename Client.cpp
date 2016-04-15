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
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>

#include "ClientSocket.hpp"
#include "ClientThread.hpp"

static std::string const kSocketAddress = "127.0.0.1";
static int const kSocketPort = 43210;

int main(int argc, const char * argv[]) {
    char inputChar = 'a';
    while (inputChar != 'q' && inputChar != 'Q') {
        ClientSocket clientSocket(kSocketAddress, kSocketPort);
        clientSocket.clientSocketConnect();
        
        ClientThread clientThread(clientSocket);
            
        clientThread.threadStop();
        clientThread.threadJoin();
        clientSocket.socketShutdown();
    }
    
    return 0;
}
