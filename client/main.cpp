//id$

/** @file main.cpp
 * @brief The main entry point for the GPS client.
 *
 * @author Hamdi Rakkez
 */

//  Internal includes.
#include "socketClient.hpp"

// Standard includes.
#include <iostream>
#include <stdlib.h>

using namespace std;

/*
 * The main program to launch the GPS Client.
 * This will take in parameters the IP address of the host(Server) and the port.
 */
int main(int argc, char** argv)
{
	/* We need three arguments in order to continue. The binary, the host IP
	 * address and the port. */
	if (argc == 3) {
		// Instantiate the client.
		Client *client = new Client();

		Host host = {argv[1], (short unsigned)atoi(argv[2])};

		// Connect the client to host.
		client->connect(host);

		// Always cleanup after yourself.
		delete client;
		//delete frame;

		return EXIT_SUCCESS;
	} else {
		// Print some help when something went wrong.
		cout << "[INFO] Usage : ./gps_client host_ip_address host_port" << endl;

		return EXIT_FAILURE;
	}
}

