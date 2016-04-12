/*
 * CommonSocket.cpp
 *
 *  Created on: 06/04/2016
 *      Author: gaston
 */

#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <vector>

#include "CommonSocket.hpp"

static int const kSocketClosed = 0;
static int const kShutdownMode = 2;

Socket::Socket() {
    this->socketFD = socket(AF_INET, SOCK_STREAM, 0);
    
    if (this->socketFD == kSocketError) {
        printf("CommonSocket.cpp - Socket creation error: %s\n", strerror(errno));
        this->socketClose();
        exit(1);
    }
    
    printf("CommonSocket.cpp - Socket created with FD: %i\n", this->socketFD);
}

Socket::Socket(int socketFD) {
    this->socketFD = socketFD;
}

Socket::~Socket() {
    this->socketClose();
    this->socketFD = 0;
}

void Socket::socketShutdown() {
    int result = shutdown(this->socketFD, kShutdownMode);
    
    if (result == kSocketError) {
        printf("CommonSocket.cpp - Socket shutdown error: %s\n", strerror(errno));
        this->socketClose();
        exit(1);
    }
}

void Socket::socketClose() {
    int result = close(this->socketFD);
    
    if (result == kSocketError) {
        printf("CommonSocket.cpp - Socket close error: %s\n", strerror(errno));
        exit(1);
    }
}

void Socket::socketSend(std::string &dataToSend) {
    // TODO: Gaston - Implementar el protocolo.
    size_t bytesSent = 0;
    size_t bytesToSend = dataToSend.size();
    bool socketIsOpen = true;
    
    while(bytesSent < bytesToSend && socketIsOpen == true) {
        int result = send(this->socketFD, dataToSend.c_str(), bytesSent, 0);
        
        if (result == kSocketError) {
            printf("CommonSocket.cpp - Socket send error: %sn\n", strerror(errno));
            this->socketClose();
            exit(1);
        } else if (result == kSocketClosed) {
            printf("CommonSocket.cpp - Socket receive close: %sn\n", strerror(errno));
            socketIsOpen = false;
        }
        
        bytesSent += result;
        printf("CommonSocket.cpp - Datos parciales enviados: %lu/%lu\n", bytesSent, bytesToSend);
    }
    
    printf("CommonSocket.cpp - Datos enviados: %lu/%lu cuyo texto: %s\n", bytesSent, bytesToSend, dataToSend.c_str());
}

std::string Socket::socketRecieve(size_t dataToRecieveSize) {
    // TODO: Gaston - Implementar el protocolo.
    printf("CommonSocket.cpp - Data to receive length: %lu\n", dataToRecieveSize);
    size_t dataReceivedSize = 0;
    std::string dataReceived;
    bool socketOpen = true;
    
    while (dataReceivedSize < dataToRecieveSize && socketOpen == true) {
        int result;
        std::vector<char> buffer;
        buffer.resize(dataToRecieveSize - dataReceivedSize, 0);
        
        result = recv(this->socketFD, &(buffer[0]), dataToRecieveSize, 0);
        
        if (result == kSocketError) {
            printf("CommonSocket.cpp - Socket receive error: %s\n", strerror(errno));
            this->socketClose();
            exit(1);
        } else if (result == kSocketClosed) {
            printf("CommonSocket.cpp - Socket receive close: %s\n", strerror(errno));
            socketOpen = false;
        }
        
        dataReceivedSize += result;
        std::string bufferStr(buffer.begin(), buffer.end());
        std::string acumStr(dataReceived.c_str());
        dataReceived = acumStr + bufferStr;
        
        printf("CommonSocket.cpp - Datos parciales recibidos: %lu/%lu Texto: %s\n", dataReceivedSize, dataReceivedSize, bufferStr.c_str());
        printf("CommonSocket.cpp - Acumulado: %s\n", dataReceived.c_str());
    }
    
    printf("CommonSocket.cpp - Datos recibidos: %s\n", dataReceived.c_str());
    return dataReceived;
}
