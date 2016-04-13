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

class ClientThread : public Thread {
private:
    ClientSocket &clientSocket;
    
public:
    // Constructors and destructors.
    virtual ~ClientThread();
    ClientThread(ClientSocket &clientSocket);
    
    void threadRun();
    void threadStop();
};

#endif /* ClientThread_hpp */
