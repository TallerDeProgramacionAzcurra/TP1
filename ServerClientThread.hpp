//
//  ServerClientThread.hpp
//  TP1
//
//  Created by Gaston Montes on 11/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#ifndef ServerClientThread_hpp
#define ServerClientThread_hpp

#include <stdio.h>

#include "CommonThread.hpp"
#include "CommonSocket.hpp"

class ServerClientThread : public Thread {
private:
    int clientSocketFD;
    bool clientThreadIsZombie;
    
public:
    virtual ~ServerClientThread();
    ServerClientThread(int clientSocketFD);
    
    void threadRun();
    void threadStop();
};

#endif /* ServerClientThread_hpp */
