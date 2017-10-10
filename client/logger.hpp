//id$

/** @file logger.hpp
 * @brief The file logger.
 *
 * @author Hamdi Rakkez
 */

#ifndef LOGGER_HPP
#define LOGGER_HPP

// Standard includes.
#include <iostream>
#include <fstream>

// Internal includes.
#include "utils.hpp"

using namespace std;

#define LOG_FILE_FULL_PATH "/tmp/GPS_Quality_Altitude_TimeStamped.log"

/**
 * Write a content to a log file and append a time stamp before any entry.
 * The time stamp is like this : "yyyy-mm-dd hh:mm:ss" e.g : 2017-09-10 17:10:45
 *
 * @param content The content to write inside the log file as string.
 */
void LOG(const string content);

#endif /* LOGGER_HPP */
