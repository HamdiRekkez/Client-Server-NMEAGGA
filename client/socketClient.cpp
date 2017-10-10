//id$

/** @file socketClient.cpp
 * @brief The client socket implementation.
 *
 * @author Hamdi Rakkez
 */

#include "socketClient.hpp"

void Client::connect(Host host)
{
	try {

		// We create the core for the socket.
		boost::asio::io_service io_service;
		tcp::resolver resolver(io_service);

		// Establishing TCP connection on port 13 daytime.
		tcp::resolver::query query(host.ipAdress, "daytime");
		tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);
		tcp::socket socket(io_service);

		while(true) {

			boost::asio::connect(socket, endpoint_iterator);

			for (;;) {
				boost::array<char, 128> buf;
				boost::system::error_code error;

				size_t len = socket.read_some(boost::asio::buffer(buf), error);

				// Handle different errors.
				if (error == boost::asio::error::eof) {
					// Connection closed cleanly by the server.
					//cout << "[INFO] Connection closed by the server!" << endl;
					break;
				} else if (error) {
					// Handle other errors.
					cout << "[INFO] " << error << endl;
                    throw boost::system::system_error(error);
				}

				// Get the string data.
				string strFrame;
				copy(buf.begin(), buf.begin() + len, back_inserter(strFrame));
				cout << "[INFO] New frame received : " << strFrame << endl;

				// Create the frame object and fill it with decode.
				Frame *frame = new Frame();
				frame->decode(strFrame);

				// We check for the frame sanity(Correct checksum).
				if (frame->checkFrameSanity()) {
					/* We prepare the stringstream with the Quality indicator,
					 * the orthometric height(Altitude) and the Altitude measure
					 * unit. */
					stringstream logData;
					logData << frame->getQualityIndicator() <<
						LOGGING_SEPARATOR;
					logData << frame->getOrthometricHeight() <<
						LOGGING_SEPARATOR;
					logData << frame->getOrthometricMeasureUnit();

					// Cleanup.
					delete frame;

					/* Create the thread for logging into the file and join to
					 * main thread of execution. */
					thread t(LOG, logData.str());
					t.join();
				} else {
					cout << "[INFO] Bad frame dropped!" << endl;
					// Cleanup.
					delete frame;
				}
			}
		}
	} catch (std::exception& e) {
		cerr << "[WARNING] " << e.what() << endl;
	}
}