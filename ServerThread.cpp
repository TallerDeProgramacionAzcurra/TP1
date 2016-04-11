//
//  ServerThread.cpp
//  TP1
//
//  Created by Gaston Montes on 11/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#include "ServerThread.hpp"

ServerThread::~ServerThread() {
}

void ServerThread::threadRun() {
    // @TODO: Gastón - Aca se recibe y envía datos.
    while(this->threadKeepTalking == true) {
    }
}

void ServerThread::threadStop() {
    this->threadKeepTalking = false;
}
