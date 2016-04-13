//
//  ServerThread.cpp
//  TP1
//
//  Created by Gaston Montes on 11/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#include <stdlib.h>
#include <list>

#include "ServerClientThread.hpp"
#include "ServerThread.hpp"

ServerThread::~ServerThread() {
}

ServerThread::ServerThread(ServerSocket &serverSocket) : Thread(), serverSocket(serverSocket) {
    printf("ServerThread.cpp - Server Thread creado.\n");
}

void ServerThread::threadRun() {
    printf("ServerThread.cpp - Running ThreadRun para aceptar clientes.\n");
    std::list<ServerClientThread *> *clientThreadList = new std::list<ServerClientThread *>;
    std::list<ServerClientThread *>::iterator listIterator = clientThreadList->end();
    
    printf("ServerThread.cpp - Entre en el while del server.\n");
    while(this->threadKeepTalking == true) {
        int clientSocketFD = this->serverSocket.serverSocketAcceptConnection();
        
        printf("ServerThread.cpp - Aceptando conexión.\n");
        
        ServerClientThread *serverClientThread = new ServerClientThread(clientSocketFD);
        
        clientThreadList->insert(listIterator, serverClientThread);
        
        for (listIterator = clientThreadList->begin(); listIterator != clientThreadList->end(); listIterator++) {
            ServerClientThread *clientThread = *listIterator;
            
            if (clientThread->threadIsZombie() == true) {
                clientThread->threadStop();
                clientThread->threadJoin();
                clientThreadList->erase(listIterator);
                delete clientThread;
            }
        }
    }
    
    printf("ServerThread.cpp - Salí en el while del server.\n");
    
    for (listIterator = clientThreadList->begin(); listIterator != clientThreadList->end(); listIterator++) {
        ServerClientThread *clientThread = *listIterator;
        clientThread->threadStop();
        clientThread->threadJoin();
        delete clientThread;
    }
    
    delete clientThreadList;
}

void ServerThread::threadStop() {
    printf("ServerThread.cpp - Stop server called.\n");
    this->threadKeepTalking = false;
}
