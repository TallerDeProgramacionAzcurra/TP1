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
#include "ClientThread.hpp"

int main(int argc, const char * argv[]) {
    ClientThread clientThread;
    
    printf("Ingrese la tecla 'Q' para detener la ejecución del cliente: ");
    char inputChar;
    std::cin >> inputChar;
    
    while (inputChar != 'q' && inputChar != 'Q') {
        std::cin >> inputChar;
    }
    
    clientThread.threadStop();
    clientThread.threadJoin();
    
    return 0;
}
