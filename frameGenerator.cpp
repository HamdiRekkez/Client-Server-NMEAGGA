//id$

/** @file frameGenerator.cpp
 * @brief A frame generator implementation.
 *
 * @author Hamdi Rakkez
 */

// Internal includes.
#include "frameGenerator.hpp"

// A prepared file containing GPS NMEA GGA frames (Frame/Line).
#define NMEA_SENTENCES_FILE "NMEAGGA"

vector<Frame> generateNMEAGGAFrame()
{
	// The current frame object.
	Frame *frame = new Frame();

	// The list of frames to return.
	vector<Frame> frameVect;

	// The ifstream reading from the file.
	ifstream file(NMEA_SENTENCES_FILE);
	string str;

	// While we have more frames inside the file.
	while (getline(file, str)) {
		// Build the frame object and push it to the list once decoding succeeded.
		if(frame->decode(str)) {
			frameVect.push_back(*frame);
		}
	}

	// Always clean up after yourself.
	delete frame;

	// Return the generated frame vector.
	return frameVect;
}