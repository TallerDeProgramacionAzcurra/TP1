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
    
    struct sockaddr_in serverSocketGetAddress();
    
public:
    // Constructors and destructors.
    virtual ~ServerSocket();
    ServerSocket(int serverPort, int serverBacklog);
    
    Socket serverSocketAcceptConnection();
    void serverSocketBind();
    void serverSocketListenConnections();
};

#endif /* ServerSocket_hpp */
