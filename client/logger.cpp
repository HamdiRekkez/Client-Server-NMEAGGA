//id$

/** @file logger.cpp
 * @brief The file logger implementation.
 * This logger is featured with a time stamping at the beginning of every entry.
 * The time is in this format "2015-10-07 12:04:32".
 *
 * @author Hamdi Rakkez
 */

// Internal includes.
#include "logger.hpp"

void LOG(const string content)
{
	ofstream out;
	out.open(LOG_FILE_FULL_PATH, ios_base::app);
	out << dateTimeToString(now(), "%Y-%m-%d %H:%M:%S") << " " << content
		<< endl;
}