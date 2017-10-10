//id$

/** @file frame.cpp
 * @brief The GPS NMEA GGA frame structure implementation.
 *
 * @author Hamdi Rakkez
 */

// Internal includes.
#include "frame.hpp"

#define SEPERATOR ',';
#define CHECHSUMDELIMITER '*';

using namespace std;

// Constructor.
Frame::Frame()
{
	// Nothing to do.
};

// Destructor.
Frame::~Frame()
{
	// Nothing to do.
};

// The frame string decoder.
bool Frame::decode(string strFrame)
{
	// We return false when the string is empty.
	/*if (strFrame.empty()) {
		return false;
	}*/

	// We split the string to vector of strings considering ',' as delimeter.
	vector<string> frameVec = splitString(strFrame);

	// We build/feed the current Frame object.
	this->prefix = frameVec.at(0);
	this->fixTime = frameVec.at(1);
	this->latitude = frameVec.at(2);
	this->latitudeDirection = charToLatitudeDirection(frameVec.at(3).at(0));
	this->longitude = frameVec.at(4);
	this->longitudeDirection = charToLongitudeDirection(frameVec.at(5).at(0));
	this->qualityIndicator = gps_quality_indicator(stoi(frameVec.at(6).c_str()));
	this->svs = frameVec.at(7);
	this->hdop = frameVec.at(8);
	this->orthometricHeight = frameVec.at(9);
	this->orthometricMeasureUnit = frameVec.at(10)[0];
	this->geoidSeparation = frameVec.at(11);
	this->geoidSeparationMeasureUnit = frameVec.at(12)[0];
	this->age = frameVec.at(13);
	this->referenceStationID = frameVec.at(14);
	this->checksum = frameVec.at(15);

	return true;
}

// The frame string encoder.
string Frame::encode()
{
	// The string stream to contain the frame in string format.
	stringstream tmp;
	tmp << this->prefix << SEPERATOR;
	tmp << this->fixTime << SEPERATOR
	tmp << this->latitude << SEPERATOR;
	tmp << getLatitudeDirectionAnnotation(this->latitudeDirection) << SEPERATOR;
	tmp << this->longitude << SEPERATOR;
	tmp << getLongitudeDirectionAnnotation(this->longitudeDirection) << SEPERATOR;
	tmp << this->qualityIndicator << SEPERATOR;
	tmp << this->svs << SEPERATOR;
	tmp << this->hdop << SEPERATOR;
	tmp << this->orthometricHeight << SEPERATOR;
	tmp << this->orthometricMeasureUnit << SEPERATOR;
	tmp << this->geoidSeparation << SEPERATOR;
	tmp << this->geoidSeparationMeasureUnit << SEPERATOR;
	tmp << this->age << SEPERATOR;
	tmp << this->referenceStationID << CHECHSUMDELIMITER;
	tmp << this->checksum;

	// Return the string representation. 	
	return tmp.str();
}

// The frame check sanity.
bool Frame::checkFrameSanity()
{
	// We get the string representation for the current Frame object.
	string strFrame = this->encode();

	// We are using iequals because it compares the string case insensitive.
	return (boost::iequals(computeNMEAChecksum(strFrame),
		this->getChecksum()));
}