//
//  ClientThread.cpp
//  TP1
//
//  Created by Gaston Montes on 11/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#include "ClientThread.hpp"

ClientThread::~ClientThread() {
    this->clientSocket.socketShutdown();
}

ClientThread::ClientThread(ClientSocket &clientSocket) : Thread(), clientSocket(clientSocket) {
}

void ClientThread::threadRun() {
    // @TODO: Gastón - Aca se recibe y envía datos.
    while(this->threadKeepTalking == true) {
        std::string dataToSend = "Socket server envía datos al cliente.";
        this->clientSocket.socketRecieve(dataToSend.size());
        this->threadKeepTalking = false;
    }
}

void ClientThread::threadStop() {
    this->threadKeepTalking = false;
}