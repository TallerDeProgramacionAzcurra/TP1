//
//  CommonMutex.hpp
//  TP1
//
//  Created by Gaston Montes on 05/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#ifndef CommonMutex_hpp
#define CommonMutex_hpp

#include <pthread.h>
#include <stdio.h>

class Mutex {
private:
    pthread_mutex_t mutex;
    
public:
    // Constructors and destructors.
    virtual ~Mutex();
    Mutex();
    
    void mutexLock();
    void mutexUnlock();
};

#endif /* CommonMutex_hpp */
