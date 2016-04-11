/*
 * CommonSocket.hpp
 *
 *  Created on: 06/04/2016
 *      Author: gaston
 */

#ifndef COMMONSOCKET_HPP_
#define COMMONSOCKET_HPP_

#include <string>

static int const kSocketError = -1;

class Socket {
protected:
	int socketFD;
    
    void socketClose();

public:
	Socket();
	virtual ~Socket();

	void socketShutdown();

	void socketSend(std::string &dataToSend);
	std::string socketRecieve(size_t dataToRecieveSize);
};

#endif /* COMMONSOCKET_HPP_ */
