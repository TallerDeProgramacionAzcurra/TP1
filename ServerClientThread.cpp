//
//  ServerClientThread.cpp
//  TP1
//
//  Created by Gaston Montes on 11/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#include <stdlib.h>
#include <string>

#include "ServerClientThread.hpp"

ServerClientThread::~ServerClientThread() {
    printf("ServerClientThread.cpp - Destructor con socketFD: %i.\n", this->clientSocket->socketGetFD());
    delete this->clientSocket;
}

ServerClientThread::ServerClientThread(int clientSocket) : Thread() {
    this->clientSocket = new Socket(clientSocket);
    printf("ServerClientThread.cpp - ServerClientThread creado con éxito con socketFD: %i.\n", this->clientSocket->socketGetFD());
}

void ServerClientThread::threadRun() {
    while(this->threadKeepTalking == true) {
        printf("ServerClientThread.cpp - Corriendo hilo para el send del server/client\n");
        std::string dataToSend = "Socket server envía datos al cliente.";
        this->clientSocket->socketSend(dataToSend);
        printf("ServerClientThread.cpp - Envíe correctamente los datos\n");
        this->threadKeepTalking = false;
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