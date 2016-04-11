//
//  Client.cpp
//  TP1
//
//  Created by Gaston Montes on 11/04/2016.
//  Copyright © 2016 Gaston Montes. All rights reserved.
//

#include <stdio.h>
#include <iostream>

#include "ClientSocket.hpp"

static std::string const kSocketAddress = "127.0.0.1";
static int const kSocketPort = 43210;

int main(int argc, const char * argv[]) {
    ClientSocket clientSocket(kSocketAddress, kSocketPort);
    
    // La información que va a enviar el servidor.
    // Es solo una prueba.
    // @TODO: Gastón - Hay que generar un hilo nuevo para manejar el send/recieve.
    std::string dataToSend = "Socket client se conectó";
    clientSocket.socketRecieve(dataToSend.size());
    
    clientSocket.socketShutdown();
    
    return 0;
}
