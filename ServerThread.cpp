//
//  ServerThread.cpp
//  TP1
//
//  Created by Gaston Montes on 11/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#include <stdlib.h>
#include <list>

#include "ServerClientThread.cpp"
#include "ServerThread.hpp"

ServerThread::~ServerThread() {
}

void ServerThread::threadRun() {
    std::list<ServerClientThread> clientThreads;
    
    while(this->threadKeepTalking == true) {
        int clientSocket = this->serverSocket.serverSocketAcceptConnection();
        ServerClientThread serverClientThread(clientSocket);
        clientThreads.insert(clientThreads.end(), serverClientThread);
        
        for (std::list<ServerClientThread>::iterator iter = clientThreads.begin(); iter != clientThreads.end(); iter++) {
            ServerClientThread clientThread = *iter;
            
            if (clientThread.threadIsZombie() == true) {
                clientThread.threadStop();
                clientThread.threadJoin();
            }
        }
    }
    
    for (std::list<ServerClientThread>::iterator iter = clientThreads.begin(); iter != clientThreads.end(); iter++) {
        ServerClientThread clientThread = *iter;
        clientThread.threadStop();
        clientThread.threadJoin();
    }
}

void ServerThread::threadStop() {
    this->threadKeepTalking = false;
}
