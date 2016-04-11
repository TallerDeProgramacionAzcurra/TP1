//
//  ServerSocket.hpp
//  TP1
//
//  Created by Gaston Montes on 11/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#ifndef ServerSocket_hpp
#define ServerSocket_hpp

#include <stdio.h>

#include "CommonSocket.hpp"

class ServerSocket: public Socket {
private:
    int serverPort;
    int serverBacklog;
    
    void serverSocketBind();
    struct sockaddr_in serverSocketGetAddress();
    void serverSocketListenConnections();
    
public:
    // Constructors and destructors.
    virtual ~ServerSocket();
    ServerSocket(int serverPort, int serverBacklog) : Socket() {
        this->serverPort = serverPort;
        this->serverBacklog = serverBacklog;
        
        this->serverSocketBind();
        this->serverSocketListenConnections();
    }
    
    int serverSocketAcceptConnection();
};

#endif /* ServerSocket_hpp */
