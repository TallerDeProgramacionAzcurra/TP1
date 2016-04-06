/*
 * CommonSocket.hpp
 *
 *  Created on: 06/04/2016
 *      Author: gaston
 */

#ifndef COMMONSOCKET_HPP_
#define COMMONSOCKET_HPP_

class Socket {
private:
	int socketFD;

public:
	Socket();
	virtual ~Socket();

	void socketShutdown();
};

#endif /* COMMONSOCKET_HPP_ */
