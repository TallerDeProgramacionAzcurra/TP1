//
//  CommonThread.hpp
//  TP1
//
//  Created by Gaston Montes on 05/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#ifndef CommonThread_hpp
#define CommonThread_hpp

#include <stdio.h>
#include <pthread.h>

class Thread
{
private:
    pthread_t thread;
    
    static void *routine(void *threadID);
    
public:
    // Constructors and destructors.
    virtual ~Thread();
    Thread();
    
    void threadJoin();
    virtual void threadRun();
};

#endif /* CommonThread_hpp */
