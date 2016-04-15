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
#include <list>

#include "ClientSocket.hpp"
#include "ClientThread.hpp"

static std::string const kSocketAddress = "127.0.0.1";
static int const kSocketPort = 43210;

int main(int argc, const char * argv[]) {
    std::list<ClientThread> *clientThreadList = new std::list<ClientThread>;
    std::list<ClientThread>::iterator listIterator = clientThreadList->end();
    
    char inputChar = 'a';
    while (inputChar != 'q' && inputChar != 'Q') {
        ClientThread clientThread(kSocketAddress, kSocketPort);
        clientThreadList->insert(listIterator, clientThread);
        
        for (listIterator = clientThreadList->begin(); listIterator != clientThreadList->end(); listIterator++) {
            ClientThread clientThread = *listIterator;
            
            if (clientThread.threadIsZombie() == true) {
                clientThread.threadStop();
                clientThread.threadJoin();
                clientThreadList->erase(listIterator);
            }
        }
        
        clientThread.threadStop();
        clientThread.threadJoin();
        
        printf("Ingrese la tecla 'Q' para detener la ejecución del Servidor: ");
        std::cin >> inputChar;
    }
    
    for (listIterator = clientThreadList->begin(); listIterator != clientThreadList->end(); listIterator++) {
        ClientThread clientThread = *listIterator;
        
        clientThread.threadStop();
        clientThread.threadJoin();
        clientThreadList->erase(listIterator);
    }
    
    delete clientThreadList;
    
    return 0;
}
