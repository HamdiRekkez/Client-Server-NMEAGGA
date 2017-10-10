//id$

/** @file main.cpp
 * @brief The main entry point.
 *
 * @author Hamdi Rakkez
 */

// Internal includes.
#include "socketServer.hpp"
#include "utils.hpp"
#include "frame.hpp"

// Standard includes.
#include <cstdlib>
#include <iostream>

// Google tests includes.
#include"gtest/gtest.h"

using namespace std;

/*
 * The main program to launch the GPS Server.
 */
int main(int argc, char** argv)
{
	// The choice to navigate through the program's Menu.
	char choice;

	do {
		cout << "   ____   ____    ____            ____                                      " << endl;
		cout << "  / ___| |  _ \\  / ___|          / ___|    ___   _ __  __   __   ___   _ __ " << endl;
		cout << " | |  _  | |_) | \\___ \\          \\___ \\   / _ \\ | '__| \\ \\ / /  / _ \\ | '__|" << endl;
		cout << " | |_| | |  __/   ___) |          ___) | |  __/ | |     \\ V /  |  __/ | |   " << endl;
		cout << "  \\____| |_|     |____/   _____  |____/   \\___| |_|      \\_/    \\___| |_|   " << endl;
		cout << "                         |_____|                                            " << endl << endl;
		cout << " 1 - Run unit tests." << endl;
		cout << " 2 - Run GPS server." << endl;
		cout << " 3 - Exit." << endl << endl;
		cout << "[INPUT] Enter your choice and press Enter: ";
		cin >> choice;
		system("clear");

		switch (choice) {
			// Launching unit tests.
			case '1': {
				::testing::InitGoogleTest(&argc, argv);
				if (RUN_ALL_TESTS() == 1) {
					cout << "[FAILURE] Unit tests are broken! Something went"
						" really wrong!!" << endl;
				return EXIT_FAILURE;
				}
			}
			break;
			// Launching the server.
			case '2': {
				Server *server = new Server();
				cout << "[INFO] GPS Server launched." << endl;
				cout << "[INFO] Waiting for clients to connect..." << endl;
				server->run();

				// Cleanup.
				delete server;
			}
			break;
			case '3':
				// End of program.
				return EXIT_SUCCESS;
		} // The switch ending.
	} while (1);
} // Main program ending.