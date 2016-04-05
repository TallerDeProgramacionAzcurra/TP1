//
//  CommonMutex.cpp
//  TP1
//
//  Created by Gaston Montes on 05/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#include "CommonMutex.hpp"

Mutex::~Mutex() {
    pthread_mutex_destroy(&this->mutex);
}

Mutex::Mutex() {
    pthread_mutex_init(&this->mutex, NULL);
}

void Mutex::mutexLock() {
    pthread_mutex_lock(&this->mutex);
}

void Mutex::mutexUnlock() {
    pthread_mutex_unlock(&this->mutex);
}
