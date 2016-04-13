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
    printf("ServerClientThread.cpp - Destructor con socketFD: %i.\n", this->clientSocketFD);
}

ServerClientThread::ServerClientThread(int clientSocketFD) : Thread(), clientSocketFD(clientSocketFD) {
    printf("ServerClientThread.cpp - ServerClientThread creado con éxito con socketFD: %i.\n", this->clientSocketFD);
}

void ServerClientThread::threadRun() {
    while(this->threadKeepTalking == true) {
        printf("ServerClientThread.cpp - Corriendo hilo para el send del server/client\n");
        
        std::string dataToSend = "Socket server envía datos al cliente.";
        size_t bytesSent = 0;
        size_t bytesToSend = dataToSend.size();
        bool socketIsOpen = true;
        
        while(bytesSent < bytesToSend && socketIsOpen == true) {
            printf("ServerClientThread.cpp - Sending data \"%s\" to socketFD: %i\n", dataToSend.c_str(), this->clientSocketFD);
            int result = send(this->clientSocketFD, dataToSend.c_str(), bytesSent, 0);
            
            if (result == kSocketError) {
                printf("ServerClientThread.cpp - Socket send error: %sn\n", strerror(errno));
                close(this->clientSocketFD);
                exit(1);
            } else if (result == kSocketClosed) {
                printf("ServerClientThread.cpp - Socket send close: %s\n", strerror(errno));
                socketIsOpen = false;
            }
            
            bytesSent += result;
            printf("ServerClientThread.cpp - Datos parciales enviados: %lu/%lu\n", bytesSent, bytesToSend);
        }
        
        printf("ServerClientThread.cpp - Datos enviados: %lu/%lu cuyo texto: %s\n", bytesSent, bytesToSend, dataToSend.c_str());
        
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