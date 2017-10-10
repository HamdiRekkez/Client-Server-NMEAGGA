//id$

/** @file utils.hpp
 * @brief Some handy utility functions and data structures definitions.
 *
 * @author Hamdi Rakkez
 */

#ifndef UTILS_HPP
#define UTILS_HPP

// Internal includes.
#include "frame.hpp"

// Standard includes.
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

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

// =======================    String manipulations    ======================= //

/**
 * Splits the string to a vector of strings based on a delimeter.
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

