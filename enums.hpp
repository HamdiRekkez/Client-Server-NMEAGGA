//id$

/** @file enums.hpp
 * @brief The different enumeration to use.
 *
 * @author Hamdi Rakkez
 */

#ifndef ENUMS_HPP
#define ENUMS_HPP

// Standard includes.
#include <vector>
#include <string>

using namespace std;

// ========================== gps_quality_indicator ========================= //

/**
 * Represents the different possible GPS quality indicator, called fix type.
 */
enum gps_quality_indicator
{
	/** No position available. */
	QI_INVALID = 0,

	/** Autonomous GPS fix, no correction data used. */
	QI_AUTONOMOUS_GPS_FIX = 1,

	/** Using a local DGPS base station or correction service such as
	 * WAAS or EGNOS. */
	QI_DGPS_FIX = 2,

	/** Probably never used. */
	QI_PPS_FIX = 3,

	/** High accuracy Real Time Kinematic. */
	QI_RTK_FIX = 4,

	/** Better than DGPS, but not quite RTK. */
	QI_RTK_FLOAT = 5,

	/** Dead reckoning. */
	QI_ESTIMATED_FIX = 6,

	/** Manual input mode. */
	QI_MANUAL = 7,

	/** Simulation mode. */
	QI_SIMULATION = 8,

	/** Not NMEA standard, but NovAtel receivers report this instead of a 2. */
	QI_WAAS_FIX = 9
};

/**
 * GPS Quality Indicator Descriptions:
 * <table>
 * <tr> <th> GPS Quality Indicator </th> <th> Description                                                         </th> </tr>
 * <tr> <td> QI_INVALID            </td> <td> No position available                                               </td> </tr>
 * <tr> <td> QI_AUTONOMOUS_GPS_FIX </td> <td> Autonomous GPS fix, no correction data used                         </td> </tr>
 * <tr> <td> QI_DGPS_FIX           </td> <td> Using a local DGPS base station or WAAS or EGNOS correction service </td> </tr>
 * <tr> <td> QI_PPS_FIX            </td> <td> Probably never used                                                 </td> </tr>
 * <tr> <td> QI_RTK_FIX            </td> <td> High accuracy Real Time Kinematic                                   </td> </tr>
 * <tr> <td> QI_RTK_FLOAT          </td> <td> Better than DGPS, but not quite RTK                                 </td> </tr>
 * <tr> <td> QI_ESTIMATED_FIX      </td> <td> Dead reckoning                                                      </td> </tr>
 * <tr> <td> QI_MANUAL             </td> <td> Manual input mode                                                   </td> </tr>
 * <tr> <td> QI_SIMULATION         </td> <td> Simulation mode                                                     </td> </tr>
 * <tr> <td> QI_WAAS_FIX           </td> <td> Not NMEA standard, but NovAtel receivers report this instead of a 2 </td> </tr>
 * </table>
 */
const vector<string> gpsQualityIndicatorDescriptions =
{
	/** QI_INVALID */
	"No position available",

	/** QI_AUTONOMOUS_GPS_FIX */
	"Autonomous GPS fix, no correction data used",

	/** QI_DGPS_FIX */
	"Using a local DGPS base station or WAAS or EGNOS correction service",

	/** QI_PPS_FIX */
	"Probably never used",

	/** QI_RTK_FIX */
	"High accuracy Real Time Kinematic",

	/** QI_RTK_FLOAT */
	"Better than DGPS, but not quite RTK",

	/** QI_ESTIMATED_FIX */
	"Dead reckoning",

	/** QI_MANUAL */
	"Manual input mode",

	/** QI_SIMULATION */
	"Simulation mode",

	/** QI_WAAS_FIX */
	"Not NMEA standard, but NovAtel receivers report this instead of a 2"
};

/**
 * Gets the description of a \ref gps_quality_indicator.
 * 
 * @param gpsQualityIndicator The input \ref gps_quality_indicator.
 *
 * @return The description of the input \ref gps_quality_indicator as string.
 */
inline string getGpsQualityIndicatorDescription(
	gps_quality_indicator gpsQualityIndicator)
{
	return gpsQualityIndicatorDescriptions[gpsQualityIndicator];
};

/**
 * GPS Quality Indicator Names:
 * <table>
 * <tr> <th> GPS Quality Indicator </th> <th> Name               </th> </tr>
 * <tr> <td> QI_INVALID            </td> <td> INVALID            </td> </tr>
 * <tr> <td> QI_AUTONOMOUS_GPS_FIX </td> <td> AUTONOMOUS-GPS-FIX </td> </tr>
 * <tr> <td> QI_DGPS_FIX           </td> <td> DGPS-FIX           </td> </tr>
 * <tr> <td> QI_PPS_FIX            </td> <td> PPS-FIX            </td> </tr>
 * <tr> <td> QI_RTK_FIX            </td> <td> RTK-FIX            </td> </tr>
 * <tr> <td> QI_RTK_FLOAT          </td> <td> RTK-FLOAT          </td> </tr>
 * <tr> <td> QI_ESTIMATED_FIX      </td> <td> ESTIMATED-FIX      </td> </tr>
 * <tr> <td> QI_MANUAL             </td> <td> MANUAL             </td> </tr>
 * <tr> <td> QI_SIMULATION         </td> <td> SIMULATION         </td> </tr>
 * <tr> <td> QI_WAAS_FIX           </td> <td> WAAS-FIX           </td> </tr>
 * </table>
 */
const vector<string> gpsQualityIndicatorNames =
{
	/** QI_INVALID */
	"INVALID",

	/** QI_AUTONOMOUS_GPS_FIX */
	"AUTONOMOUS-GPS-FIX",

	/** QI_DGPS_FIX */
	"DGPS-FIX",

	/** QI_PPS_FIX */
	"PPS-FIX",

	/** QI_RTK_FIX */
	"RTK-FIX",

	/** QI_RTK_FLOAT */
	"RTK-FLOAT",

	/** QI_ESTIMATED_FIX */
	"ESTIMATED-FIX",

	/** QI_MANUAL */
	"MANUAL",

	/** QI_SIMULATION */
	"SIMULATION",

	/** QI_WAAS_FIX */
	"WAAS-FIX"
};

/**
 * Gets the name of a \ref gps_quality_indicator.
 * 
 * @param gpsQualityIndicator The input \ref gps_quality_indicator.
 *
 * @return The name of the input \ref gps_quality_indicator as string.
 */
inline string getGpsQualityIndicatorName(
	gps_quality_indicator gpsQualityIndicator)
{
	return gpsQualityIndicatorNames[gpsQualityIndicator];
};

// ========================================================================== //

// ========================== longitude_direction =========================== //

/**
 * Represents the different longitude directions(East and West).
 */
enum longitude_direction
{
	/** The East longitude direction. */
	D_EAST = 0,

	/** The West longitude direction. */
	D_WEST = 1
};

/**
 * Longitude direction annotations:
 * <table>
 * <tr> <th> Longitude direction </th> <th> Annotation </th> </tr>
 * <tr> <td> D_EAST              </td> <td> E          </td> </tr>
 * <tr> <td> D_WEST              </td> <td> W          </td> </tr>
 * </table>
 */
const vector<char> longitudeDirectionAnnotation =
{
	/** D_EAST */
	'E',

	/** D_WEST */
	'W'
};

/**
 * Gets the Annotation for a \ref longitude_direction.
 * 
 * @param longitudeDirection The input \ref longitude_direction.
 *
 * @return The annotations of the input \ref longitude_direction as char.
 */
inline char getLongitudeDirectionAnnotation(
	longitude_direction longitudeDirection)
{
	return longitudeDirectionAnnotation[longitudeDirection];
};

/**
 * 
 * @param longitudeDirection
 *
 * @return 
 */
longitude_direction charToLongitudeDirection(const char& longitudeDirection);

// ========================================================================== //

// ========================== latitude_direction =========================== //

/**
 * Represents the different latitude directions(North and SOUTH).
 */
enum latitude_direction
{
	/** The North latitude direction. */
	D_NORTH = 0,

	/** The South latitude direction. */
	D_SOUTH = 1
};

/**
 * Latitude direction annotations:
 * <table>
 * <tr> <th> Longitude direction  </th> <th> Annotation </th> </tr>
 * <tr> <td> D_NORTH              </td> <td> N          </td> </tr>
 * <tr> <td> D_SOUTH              </td> <td> S          </td> </tr>
 * </table>
 */
const vector<char> latitudeDirectionAnnotation =
{
	/** D_NORTH */
	'N',

	/** D_SOUTH */
	'S'
};

/**
 * Gets the Annotation for a \ref latitude_direction.
 * 
 * @param latitudeDirection The input \ref latitude_direction.
 *
 * @return The annotation of the input \ref latitude_direction as char.
 */
inline char getLatitudeDirectionAnnotation(
	latitude_direction latitudeDirection)
{
	return latitudeDirectionAnnotation[latitudeDirection];
};

/**
 * 
 * @param latitudeDirection
 *
 * @return 
 */
latitude_direction charToLatitudeDirection(const char& latitudeDirection);

// ========================================================================== //

#endif /* ENUMS_HPP */
 