//id$

/** @file socketClient.hpp
 * @brief The client socket header file.
 *
 * @author Hamdi Rakkez
 */

#ifndef SOCKETCLIENT_HPP
#define SOCKETCLIENT_HPP

// Boost ASIO includes.
#include <boost/asio.hpp> // The boost socket.
#include <boost/array.hpp> // The boost array data structure.

// Internal includes.
#include "utils.hpp" // Internal utility functions.
#include "logger.hpp" // For logging with time stanp into a log file.
#include "frame.hpp" // The Frame object.

// Standard includes.
#include <iostream> // For print to the console(cout).
#include <thread> // For launching seperate threads.

// The space separator between data in the log file.
#define LOGGING_SEPARATOR ' '

// Name spaces.
using namespace std;
using boost::asio::ip::tcp;

/**
 * The base client class which provides the connect method to establish
 * a TCP connection with a host(server).
 */
class Client
{
public :

	/**
	 * Connect to a given host. A host contains an IP address and a port.
	 *
	 * @param host The host(server) to connect.
	 */
	void connect(Host host);
};

#endif /* SOCKETCLIENT_HPP */
