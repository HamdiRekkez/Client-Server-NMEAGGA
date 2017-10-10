//id$

/** @file enums.cpp
 * @brief The different enumeration some functions implementation. 
 *
 * @author Hamdi Rakkez
 */

// Internal includes.
#include "enums.hpp"

latitude_direction charToLatitudeDirection(const char& latitudeDirection)
{
	if (latitudeDirection == 'N') {
		return D_NORTH;
	} else if (latitudeDirection == 'S') {
		return D_SOUTH;
	}
}

longitude_direction charToLongitudeDirection(const char& longitudeDirection)
{
	if (longitudeDirection == 'W') {
		return D_WEST;
	} else if (longitudeDirection == 'E') {
		return D_EAST;
	}
}
