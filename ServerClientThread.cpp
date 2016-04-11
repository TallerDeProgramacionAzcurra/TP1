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
}

void ServerClientThread::threadRun() {
    while(this->threadKeepTalking == true) {
        printf("Corriendo hilo para el send del server/client\n");
        std::string dataToSend = "Socket server envía datos al cliente.";
        this->clientSocketFD.socketSend(dataToSend);
        printf("Envíe correctamente los datos\n");
        this->threadKeepTalking = false;
    }
}

void ServerClientThread::threadStop() {
    this->threadKeepTalking = false;
}

bool ServerClientThread::threadIsZombie() {
    return !this->threadKeepTalking;
}