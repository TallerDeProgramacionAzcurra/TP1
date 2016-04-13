//
//  ClientThread.cpp
//  TP1
//
//  Created by Gaston Montes on 11/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#include "ClientThread.hpp"

ClientThread::~ClientThread() {
}

ClientThread::ClientThread(ClientSocket &clientSocket) : Thread(), clientSocket(clientSocket) {
}

void ClientThread::threadRun() {
    // @TODO: Gastón - Aca se recibe y envía datos.
    while(this->threadKeepTalking == true) {
        std::string dataToReceive = "Socket server envía datos al cliente.";
        this->clientSocket.socketRecieve(dataToReceive.size());
        this->threadStop();
    }
}

void ClientThread::threadStop() {
    this->threadKeepTalking = false;
}