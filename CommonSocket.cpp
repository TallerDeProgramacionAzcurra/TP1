/*
 * CommonSocket.cpp
 *
 *  Created on: 06/04/2016
 *      Author: gaston
 */

#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "CommonSocket.hpp"

static int const kSocketError = -1;
static int const kShutdownMode = 2;

Socket::Socket() {
	this->socketFD = socket(AF_INET, SOCK_STREAM, 0);

	if (this->socketFD == kSocketError) {
		printf("Socket creation error: %s\n", strerror(errno));
		exit(1);
	}
}

Socket::~Socket() {
	close(this->socketFD);
	this->socketFD = 0;
}

void Socket::socketShutdown() {
	int result = shutdown(this->socketFD, kShutdownMode);

	if (result == kSocketError) {
		printf("Socket shutdown error: %s\n", strerror(errno));
		exit(1);
	}
}
