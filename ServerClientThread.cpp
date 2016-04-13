//
//  ServerClientThread.cpp
//  TP1
//
//  Created by Gaston Montes on 11/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <string>

#include "ServerClientThread.hpp"
#include "CommonSocket.hpp"

ServerClientThread::~ServerClientThread() {
    printf("ServerClientThread.cpp - Destructor con socketFD: %i.\n", this->clientSocket.socketGetFD());
}

ServerClientThread::ServerClientThread(Socket &clientSocket) : Thread(), clientSocket(clientSocket) {
    printf("ServerClientThread.cpp - ServerClientThread creado con éxito con socketFD: %i.\n", this->clientSocket.socketGetFD());
}

void ServerClientThread::threadRun() {
    while(this->threadKeepTalking == true) {
        printf("ServerClientThread.cpp - Corriendo hilo para el send del server/client\n");
        
        std::string dataToSend = "Socket server envía datos al cliente.";
        this->clientSocket.socketSend(dataToSend);
        
        this->threadStop();
    }
    
    printf("ServerClientThread.cpp - Salí del ThreadRun.\n");
}

void ServerClientThread::threadStop() {
    printf("ServerClientThread.cpp - Stopping Thread.\n");
    this->threadKeepTalking = false;
}

bool ServerClientThread::threadIsZombie() {
    printf("ServerClientThread.cpp - Thread is Zombie called: %i\n", !this->threadKeepTalking);
    return !this->threadKeepTalking;
}