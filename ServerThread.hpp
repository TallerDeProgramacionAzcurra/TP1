//
//  ServerThread.hpp
//  TP1
//
//  Created by Gaston Montes on 11/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#ifndef ServerThread_hpp
#define ServerThread_hpp

#include <stdio.h>

#include "CommonThread.hpp"
#include "ServerSocket.hpp"

class ServerThread : public Thread {
private:
    ServerSocket &serverSocket;
    
public:
    // Constructors and destructors.
    virtual ~ServerThread();
    ServerThread(ServerSocket &serverSocket);
    
    void threadRun();
    void threadStop();
};

#endif /* ServerThread_hpp */
