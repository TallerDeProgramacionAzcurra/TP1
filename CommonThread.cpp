//
//  CommonThread.cpp
//  TP1
//
//  Created by Gaston Montes on 05/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#include <stdlib.h>
#include <errno.h>

#include "CommonThread.hpp"

static int const kThreadOperationSucces = 0;

Thread::~Thread() {
}

Thread::Thread() {
    int operationResult = pthread_create(&this->thread, NULL, Thread::routine, this);
    
    if (operationResult != kThreadOperationSucces) {
        perror("Thread creation error.");
        exit(1);
    }
    
    printf("Thread creation success.");
}

void Thread::threadJoin() {
    int operationResult = pthread_join(this->thread, NULL);
    
    if (operationResult != kThreadOperationSucces) {
        perror("Thread join error.");
        exit(1);
    }
    
    printf("Thread joined.");
}

void Thread::threadRun() {
    
}

void *Thread::routine(void *threadID) {
    printf("Run Thread routine");
    Thread *thread = (Thread *)threadID;
    thread->threadRun();
    return NULL;
}
