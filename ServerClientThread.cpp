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

ServerClientThread::ServerClientThread(Socket clientSocket) : Thread(), clientSocketFD(clientSocket) {
    printf("ServerClientThread.cpp - ServerClientThread creado con éxito");
}

void ServerClientThread::threadRun() {
    while(this->threadKeepTalking == true) {
        printf("ServerClientThread.cpp - Corriendo hilo para el send del server/client\n");
        std::string dataToSend = "Socket server envía datos al cliente.";
        this->clientSocketFD.socketSend(dataToSend);
        printf("ServerClientThread.cpp - Envíe correctamente los datos\n");
        this->threadKeepTalking = false;
    }
}

void ServerClientThread::threadStop() {
    this->threadKeepTalking = false;
}

bool ServerClientThread::threadIsZombie() {
    return !this->threadKeepTalking;
}