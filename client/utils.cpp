//id$

/** @file utils.cpp
 * @brief Some handy utility functions implementation.
 *
 * @author Hamdi Rakkez
 */

// Internal includes.
#include "utils.hpp"

// ==========================    NMEA GGA Sanity    ========================= //

string computeNMEAChecksum(const string& frame)
{
	char crc = 0;

	// Iterate over the string, XOR each byte with the total sum.
	for (size_t i = 0; i < frame.length(); i++) {
		crc ^= frame.at(i);
	}

	// Return the checksum result.
	return intToHexString(crc);
}

string getNMEAFrameStringToCheck(const string& frame)
{
	size_t first = frame.find("$");
	size_t second = frame.find("*");
	return frame.substr(first + 1, second - (first + 1));
}

// ========================================================================== //

// ===============================    Time    =============================== //

ostream& formatDateTime(ostream& out, const tm& t, const char* fmt)
{
  const time_put<char>& dateWriter = use_facet<time_put<char> >(out.getloc());
  int n = strlen(fmt);
  dateWriter.put(out, out, ' ', &t, fmt, fmt + n);
  return out;
}

string dateTimeToString(const tm& t, const char* format)
{
	stringstream s;
	formatDateTime(s, t, format);
	return s.str();
}

tm now()
{
	time_t now = time(0);
	return *localtime(&now);
}

// ========================================================================== //

// =======================    String manipulations    ======================= //

vector<string> splitString(const string& input, const string& delim, 
	bool ignoreEmptyStrings)
{
	vector<string> res;
	if (delim.empty()) {
		return res;
	}

	size_t start = 0;
	size_t pos = 0;
	size_t length = input.length();
	string token;
	while (pos < length) {
		pos = input.find(delim, start);
		token = input.substr(start, pos - start);
		if (!ignoreEmptyStrings || !token.empty()) {
			if (token.find('*') != string::npos) {
				vector<string> tmp = splitString(token, "*");
				res.insert(res.end(), tmp.begin(), tmp.end());
			} else {
				res.push_back(token);
			}
		}
		start = pos + delim.length();
	}
	return res;
}

string intToHexString(int intValue)
{
	// The hex-string to return.
	string hexStr;

	stringstream sstream;
	sstream << std::setfill('0') << std::setw(2) << std::hex
		<< (int)intValue;

	hexStr = sstream.str();
	sstream.clear();

	// Return the Hexadecimal representation of the integer.
	return hexStr;
}

// ========================================================================== //