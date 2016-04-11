//
//  ClientSocket.hpp
//  TP1
//
//  Created by Gaston Montes on 11/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#ifndef ClientSocket_hpp
#define ClientSocket_hpp

#include <stdio.h>

#include "CommonSocket.hpp"

class ClientSocket: public Socket {
private:
    std::string socketServerAddress;
    int socketServerPort;
    
    struct sockaddr_in getServerAddress();
    void clientSocketConnect();
    
public:
    // Constructors and destructors.
    virtual ~ClientSocket();
    ClientSocket(const std::string serverAddress, int serverPort) : Socket() {
        this->socketServerAddress = serverAddress;
        this->socketServerPort = serverPort;
        this->clientSocketConnect();
    };
};

#endif /* ClientSocket_hpp */
