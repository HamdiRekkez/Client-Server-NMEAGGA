//id$

/** @file utils.hpp
 * @brief Some handy utility functions.
 *
 * @author Hamdi Rakkez
 */

#ifndef UTILS_HPP
#define UTILS_HPP

// Standard includes.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <stdexcept>
#include <iterator>
#include <sstream>
#include <locale>
#include <vector>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;

#define TO_UPPER(c) ((char) (c - 32))

// ==========================    Data structures    ========================= //

/**
 * A structure representing the host. An IP address and a port.
 */
struct Host
{
	/** The host's IP address. */
	string ipAdress;

	/** The port. */
	unsigned short port;
};

// ========================================================================== //

// ==========================    NMEA GGA Sanity    ========================= //

/**
 * Computes the NMEA GGA frame checksum.
 * 
 * @param frame The input frame in string format.
 *
 * @return The control key in hex-string format.
 */
string computeNMEAChecksum(const string& frame);

/**
 * Will get the string we are calculating its checksum.
 * Basically, will remove the '$' in the beginning and the '*' before the
 * control key.
 *
 * @param frame The input frame in string format.
 *
 * @return The string we are calculating its checksum.
 */
string getNMEAFrameStringToCheck(const string& frame);

// ========================================================================== //

// ===============================    Time    =============================== //

/**
 * Format the date time with given format to ostream.
 *
 * @param out The ostream to format.
 * @param t The tm date structure.
 * @param fmt The time format.
 *
 * @return An ostream formatted.
 */
ostream& formatDateTime(ostream& out, const tm& t, const char* fmt);

/**
 * Converts the date to a string format.
 *
 * @param t The tm date structure.
 * @param formats The time format. E.g ""%Y-%m-%d %H:%M:%S""
 *
 * @return A string representation of the input tm time.
 */
string dateTimeToString(const tm& t, const char* format);

/**
 * Get the now time.
 *
 * @return The current time in tm format.
 */
tm now();

// ========================================================================== //

// =======================    String manipulations    ======================= //

/**
 * Splits the string to as vector of strings based on a delimeter.
 * Also, when a substring is found containing '*' it will be split as well.
 *
 * @param input The entry string to split.
 * @param delim The delimeter (By default ',')
 * @param ignoreEmptyStrings Ignore empty strings (By default 'false').
 *
 * @return The vector of strings.
 */
vector<string> splitString(const string& input, const string& delim = ",",
	bool ignoreEmptyStrings = false);

/**
 * Converts integer value to hex-string.
 *
 * @param intValue The input integer value.
 *
 * @return The hex-string representation.
 */
string intToHexString(int intValue);

// ========================================================================== //

#endif /* UTILS_HPP */

