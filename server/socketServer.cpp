//id$

/** @file socketServer.cpp
 * @brief The socket server implementation.
 *
 * @author Hamdi Rakkez
 */

// Internal includes.
#include "socketServer.hpp"

// Constructor.
Server::Server()
{
	// Nothing to do.
};

// Destructor.
Server::~Server()
{
	// Nothing to do.
};

void Server::run()
{
	try {

		// Create the socket core.
		boost::asio::io_service io_service;

		// We are accepting connections from client who uses IPv4 on the port 13.
		tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 13));

		// Get the frames vector.
		vector<Frame> frameVect = generateNMEAGGAFrame();

		/** Wait for client to connect, and iterate over the frame vector
		 * to send them one by one. 1 frame/second a.k.a 1HZ. */
		for (size_t i = 0; i < frameVect.size(); i++) {
			tcp::socket socket(io_service);
			acceptor.accept(socket);

			string message = frameVect.at(i).encode();
			cout << "[INFO] Sending frame #" << i << " : " << message << endl;

			boost::system::error_code ignored_error;
			boost::asio::write(socket, boost::asio::buffer(message),
				ignored_error);

			// Wait 1 second for sending the next frame.
			sleep(1);
		}
    } catch (std::exception& e) {
		cerr << "[WARNING] " << e.what() << endl;
	}
}