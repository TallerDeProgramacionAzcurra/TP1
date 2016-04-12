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
    Socket clientSocketFD;
    
public:
    virtual ~ServerClientThread();
    ServerClientThread(int clientSocket) : Thread(), clientSocketFD(Socket(clientSocket)) {}
    
    void threadRun();
    void threadStop();
    bool threadIsZombie();
};

#endif /* ServerClientThread_hpp */