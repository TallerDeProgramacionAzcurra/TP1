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
    printf("ServerThread.cpp - Server Thread creado con serverSocketFD: %i\n", this->serverSocket.getSocketFD());
}

void ServerThread::threadRun() {
    printf("ServerThread.cpp - Running ThreadRun.\n");
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

//void ServerThread::threadRun() {
//    printf("Corriendo hilo para el accept del server\n");
//    while (this->serverSocket.socketGetKeepTalking() == true) {
//        printf("Estoy por aceptar una conexión en el loop\n");
//        int clientSocketFd = this->serverSocket.socketAcceptConnection();
//        TCPSocket clientSocket(clientSocketFd);
//        ProcessClientThread *clientThread;
//        clientThread = new ProcessClientThread(this->serverSocket, clientSocket);
//        
//        
//        std::list<ProcessClientThread>::iterator it = this->threadList->end();
//        this->threadList->insert(it, *clientThread);
//        
//        for (it = this->threadList->begin(); it != this->threadList->end(); it++) {
//            ProcessClientThread thread = *it;
//            
//            thread.threadJoin();
//            this->threadList->erase(it);
//        }
//        
//        delete clientThread;
//    }
//    
//    printf("SALÍ DEL WHILE :S\n");
//}
