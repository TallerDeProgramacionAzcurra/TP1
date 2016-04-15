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
    Socket *newClientSocket = new Socket(this->clientSocketFD);
    
    while(this->threadKeepTalking == true) {
        printf("ServerClientThread.cpp - Corriendo hilo para el send del server/client. SocketFD: %i\n", this->clientSocketFD);
        
        std::string dataToSend = "Socket server envía datos al cliente.";
        newClientSocket->socketSend(dataToSend);
        
        this->threadStop();
    }
    
    printf("ServerClientThread.cpp - Salí del ThreadRun. SocketFD: %i\n", this->clientSocketFD);
    
    this->threadZombie = true;
    
    delete newClientSocket;
}

void ServerClientThread::threadStop() {
    printf("ServerClientThread.cpp - Stopping Thread. SocketFD: %i\n", this->clientSocketFD);
    this->threadKeepTalking = false;
}
