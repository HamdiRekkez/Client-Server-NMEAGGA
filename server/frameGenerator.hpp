//id$

/** @file frameGenerator.hpp
 * @brief A frame generator.
 * This generates random BUT valid NMEA GGA frames.
 * This generator gets the preprepared frames from a file (Frame per line).
 *
 * @author Hamdi Rakkez
 */

#ifndef FRAMEGENERATOR_HPP
#define FRAMEGENERATOR_HPP

// Internal includes.
#include "enums.hpp"
#include "frame.hpp"

// Standard includes.
#include <random>
#include <fstream>
#include <vector>

using namespace std;

/**
 * Generate a valid NMEA GGA GPS frames list.
 *
 * @return The generated list of frames.
 */
vector<Frame> generateNMEAGGAFrame();

#endif /* FRAMEGENERATOR_HPP */

