//
//  CommonThread.cpp
//  TP1
//
//  Created by Gaston Montes on 05/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "CommonThread.hpp"

static int const kThreadOperationSucces = 0;

Thread::~Thread() {
}

Thread::Thread() {
    int operationResult = pthread_create(&this->thread, NULL, Thread::routine, this);
    
    if (operationResult != kThreadOperationSucces) {
    	printf("CommonThread.cpp - Thread creation error: %s\n", strerror(errno));
        exit(1);
    }
    
    this->threadKeepTalking = true;
    this->threadZombie = false;
    
    printf("CommonThread.cpp - Thread creation success.\n");
}

void Thread::threadJoin() {
    int operationResult = pthread_join(this->thread, NULL);
    
    if (operationResult != kThreadOperationSucces) {
        printf("CommonThread.cpp - Thread join error: %s\n", strerror(errno));
        exit(1);
    }
    
    printf("CommonThread.cpp - Thread joined.\n");
}

void Thread::threadRun() {
}

void Thread::threadStop() {
}

bool Thread::threadIsZombie() {
    return this->threadZombie;
}

void *Thread::routine(void *threadID) {
    printf("CommonThread.cpp - Run Thread routine\n");
    Thread *thread = (Thread *)threadID;
    thread->threadRun();
    return NULL;
}
