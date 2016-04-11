//
//  CommonThread.hpp
//  TP1
//
//  Created by Gaston Montes on 05/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#ifndef CommonThread_hpp
#define CommonThread_hpp

#include <pthread.h>
#include <stdio.h>

class Thread {
private:
    pthread_t thread;
    
    static void *routine(void *threadID);
    
protected:
    bool threadKeepTalking;
    
public:
    // Constructors and destructors.
    virtual ~Thread();
    Thread();
    
    void threadJoin();
    virtual void threadRun();
    virtual void threadStop();
    virtual void threadIsZombie();
};

#endif /* CommonThread_hpp */
