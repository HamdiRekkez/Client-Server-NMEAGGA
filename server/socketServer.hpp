//id$

/** @file socketServer.hpp
 * @brief The socket server.
 *
 * @author Hamdi Rakkez
 */

#ifndef SOCKETSERVER_HPP
#define SOCKETSERVER_HPP

// Boost ASIO includes.
#include <boost/asio.hpp>
#include <boost/array.hpp>

// Internal includes.
#include "frame.hpp"
#include "utils.hpp"
#include "frameGenerator.hpp"

// Standard includes.
#include <string>

using namespace std;
using boost::asio::ip::tcp;

/**
 * The main class for the TCP server.
 */
class Server
{	
public:

	/** Constructor. */
	Server();

	/** Destructor. */
	~Server();

	/**
	 * Run the server.
	 */
	void run();
};

#endif /* SOCKETSERVER_HPP */

