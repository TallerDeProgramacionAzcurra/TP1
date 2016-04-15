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

ClientThread::ClientThread(std::string serverAddress, int serverPort) : Thread(), serverAddress(serverAddress), serverPort(serverPort) {
}

void ClientThread::threadRun() {
    // @TODO: Gastón - Aca se recibe y envía datos.
    ClientSocket *clientSocket = new ClientSocket(this->serverAddress, this->serverPort);
    clientSocket->clientSocketConnect();
    
    while(this->threadKeepTalking == true) {
        std::string dataToReceive = "Socket server envía datos al cliente.";
        clientSocket->socketRecieve(dataToReceive.size());
        
        this->threadStop();
        this->threadZombie = true;
    }
    
    clientSocket->socketShutdown();
    delete clientSocket;
}

void ClientThread::threadStop() {
    this->threadKeepTalking = false;
}