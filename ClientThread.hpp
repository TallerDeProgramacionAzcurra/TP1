//
//  ClientThread.hpp
//  TP1
//
//  Created by Gaston Montes on 11/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#ifndef ClientThread_hpp
#define ClientThread_hpp

#include <stdio.h>

#include "CommonThread.hpp"
#include "ClientSocket.hpp"

static std::string const kSocketAddress = "127.0.0.1";
static int const kSocketPort = 43210;

class ClientThread : public Thread {
private:
    ClientSocket clientSocket;
    
public:
    // Constructors and destructors.
    virtual ~ClientThread();
    ClientThread() : Thread(), clientSocket(ClientSocket(kSocketAddress, kSocketPort)) {}
    
    void threadRun();
    void threadStop();
};

#endif /* ClientThread_hpp */
