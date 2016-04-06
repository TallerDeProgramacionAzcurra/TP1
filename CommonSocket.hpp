/*
 * CommonSocket.hpp
 *
 *  Created on: 06/04/2016
 *      Author: gaston
 */

#ifndef COMMONSOCKET_HPP_
#define COMMONSOCKET_HPP_

#include <string>

class Socket {
private:
	int socketFD;

public:
	Socket();
	virtual ~Socket();

	void socketShutdown();

	void socketSend(std::string &dataToSend);
	std::string socketRecieve(size_t dataToRecieveSize);
};

#endif /* COMMONSOCKET_HPP_ */
