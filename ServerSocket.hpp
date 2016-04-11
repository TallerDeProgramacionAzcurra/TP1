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
    
    void serverSocketBind();
    struct sockaddr_in serverSocketGetAddress();
    void serverSocketListenConnections();
    int serverSocketAcceptConnection();
    
public:
    // Constructors and destructors.
    virtual ~ServerSocket();
    ServerSocket(int serverPort) : Socket() {
        this->serverPort = serverPort;
        
        this->serverSocketBind();
        this->serverSocketListenConnections();
        this->serverSocketAcceptConnection();
    }
};

#endif /* ServerSocket_hpp */
