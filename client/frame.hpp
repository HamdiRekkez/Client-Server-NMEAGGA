//id$

/** @file frame.hpp
 * @brief The NMEA GGA frame for GPS structure presentation.
 * Global Positioning System Fix Data
 *
 * @author Hamdi Rakkez
 */

#ifndef FRAME_HPP
#define FRAME_HPP

// Internal includes
#include "enums.hpp"
#include "utils.hpp"

// Standard includes.
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// boost includes.
#include <boost/algorithm/string.hpp> // iequals;

using namespace std;

/**
 * The class frame representing the NMEA GGA GPS frame.
 */
class Frame
{
private:

	/** The frame prefix. "$GPGGA" for GGA. */
	string prefix = "$GPGGA";

	/** UTC of position fix. */
	string fixTime;

	/** The latitude. */
	string latitude;

	/** Direction of latitude. */
	latitude_direction latitudeDirection;

	/** The longitude. */
	string longitude;

	/** Direction of longitude. */
	longitude_direction longitudeDirection;

	/** GPS Quality indicator. */
	gps_quality_indicator qualityIndicator;

	/** Number of SVs in use, range from 00 through to 24+(a.k.a The number
	 * of satellites being tracked) */
	string svs;

	/** HDOP. (a.k.a Horizontal dilution of position) */
	string hdop;

	/** Orthometric height (MSL reference).
	 * a.k.a Altitude, Meters, above mean sea level. */
	string orthometricHeight;

	/* M: unit of measure for orthometric height is meters. */
	char orthometricMeasureUnit;

	/** Geoid separation. */
	string geoidSeparation;

	/** Geoid separation measured in meters. */
	char geoidSeparationMeasureUnit;

	/** Age of differential GPS data record, Type 1 or Type 9. Empty field when
	 * DGPS is not used. */
	string age;

	/** Reference station ID, range 0000-4095. A null field when any reference
	 * station ID is selected and no corrections are received. */
	string referenceStationID;

	/** The frame control checksum. Begins with '*' */
	string checksum;

public:

	/** Constructor. */
	Frame();

	/** Destructor. */
	~Frame();

	/**
	 * Encode a Frame to string representation.
	 *
	 * @return The string representation of a Frame.
	 */
	string encode();

	/**
	 * Decode a Frame to string representation.
	 *
	 * @return The string representation of a Frame.
	 */

	/**
	 * Decode a string.
	 *
	 * @param strFrame The string representation of a frame.
	 *
	 * @return True when decoding went successfully, False otherwise.
	 */
	bool decode(string strFrame);

	/**
	 * Check the frame's sanity, check for the control key.
	 *
	 * @return True when the frame is good, false otherwise.
	 */
	bool checkFrameSanity();

	/**
	 * Set the checksum.
	 *
	 * @param checksum The checksum to set.
	 */
	void setChecksum(string checksum)
	{
		this->checksum = checksum;
	}

	/**
	 * Get the checksum.
	 *
	 * @return the checksum.
	 */
	string getChecksum() const
	{
		return checksum;
	}

	/**
	 * Set the fix time.
	 *
	 * @param fixTime The fix time to set.
	 */
	void setFixTime(string fixTime)
	{
		this->fixTime = fixTime;
	}

	/**
	 * Get the fix Time.
	 *
	 * @return the fix time.
	 */
	string getFixTime() const
	{
		return fixTime;
	}

	/**
	 * Set the reference station ID.
	 *
	 * @param referenceStationID The reference station ID to set.
	 */
	void setReferenceStationID(string referenceStationID)
	{
		this->referenceStationID = referenceStationID;
	}

	/**
	 * Get the reference station ID.
	 *
	 * @return The reference station ID.
	 */
	string getReferenceStationID() const
	{
		return referenceStationID;
	}

	/**
	 * Set an age.
	 *
	 * @param age The age to set.
	 */
	void setAge(string age)
	{
		this->age = age;
	}

	/**
	 * Get the age.
	 *
	 * @return The age.
	 */
	string getAge() const
	{
		return age;
	}

	/**
	 * Set the geoid separation measure unit.
	 *
	 * @param geoidSeparationMeasureUnit The measure unit.
	 */
	void setGeoidSeparationMeasureUnit(char geoidSeparationMeasureUnit)
	{
		this->geoidSeparationMeasureUnit = geoidSeparationMeasureUnit;
	}

	/**
	 * Get the geoid separation measure unit.
	 *
	 * @return The geoid separation measure unit.
	 */
	char getGeoidSeparationMeasureUnit() const
	{
		return geoidSeparationMeasureUnit;
	}

	/**
	 * Set the geoid Separation.
	 *
	 * @param geoidSeparation the geoid Separation to set.
	 */
	void setGeoidSeparation(string geoidSeparation)
	{
		this->geoidSeparation = geoidSeparation;
	}

	/**
	 * Get the geoid Separation.
	 *
	 * @return The geoid Separation.
	 */
	string getGeoidSeparation() const
	{
		return geoidSeparation;
	}

	/**
	 * Set the orthometric measure unit.
	 *
	 * @param orthometricMeasureUnit
	 */
	void setOrthometricMeasureUnit(char orthometricMeasureUnit)
	{
		this->orthometricMeasureUnit = orthometricMeasureUnit;
	}

	/**
	 * Get the OrthometricMeasureUnit.
	 *
	 * @return The orthometric measure unit.
	 */
	char getOrthometricMeasureUnit() const
	{
		return orthometricMeasureUnit;
	}

	/**
	 * Set the OrthometricHeight.
	 *
	 * @param orthometricHeight The orthometric height to set.
	 */
	void setOrthometricHeight(string orthometricHeight)
	{
		this->orthometricHeight = orthometricHeight;
	}

	/**
	 * Get the orthometric heigh.
	 *
	 * @return orthometric heigh.
	 */
	string getOrthometricHeight() const
	{
		return orthometricHeight;
	}

	/**
	 * Set the HDOP.
	 *
	 * @param hdop The HDOP to set.
	 */
	void setHdop(string hdop)
	{
		this->hdop = hdop;
	}

	/**
	 * Get the HDOP.
	 *
	 * @return The HDOP.
	 */
	string getHdop() const
	{
		return hdop;
	}

	/**
	 * Set the svs.
	 *
	 * @param svs The svs to set.
	 */
	void setSvs(string svs)
	{
		this->svs = svs;
	}

	/**
	 * Get the svs.
	 *
	 * @return The svs.
	 */
	string getSvs() const
	{
		return svs;
	}

	/**
	 * Set the GPS quality indicator.
	 *
	 * @param qualityIndicator The GPS quality indicator to set.
	 */
	void setQualityIndicator(gps_quality_indicator qualityIndicator)
	{
		this->qualityIndicator = qualityIndicator;
	}

	/**
	 * 
	 * @return 
	 */
	gps_quality_indicator getQualityIndicator() const
	{
		return qualityIndicator;
	}

	/**
	 * 
	 * @param longitudeDirection
	 */
	void setLongitudeDirection(longitude_direction longitudeDirection)
	{
		this->longitudeDirection = longitudeDirection;
	}

	/**
	 * Get the longitude direction.
	 *
	 * @return The longitude direction.
	 */
	longitude_direction getLongitudeDirection() const
	{
		return longitudeDirection;
	}

	/**
	 * Set the longitude.
	 *
	 * @param longitude The longitude to set.
	 */
	void setLongitude(string longitude)
	{
		this->longitude = longitude;
	}

	/**
	 * Get the longitude direction.
	 *
	 * @return The longitude direction.
	 */
	string getLongitude() const
	{
		return longitude;
	}

	/**
	 * Set the latitude direction.
	 *
	 * @param latitudeDirection The latitude direction to set.
	 */
	void setLatitudeDirection(latitude_direction latitudeDirection)
	{
		this->latitudeDirection = latitudeDirection;
	}

	/**
	 * Get the latitude direction.
	 *
	 * @return The latitude direction.
	 */
	latitude_direction getLatitudeDirection() const
	{
		return latitudeDirection;
	}

	/**
	 * Set the latitude.
	 *
	 * @param latitude The latitude to set.
	 */
	void setLatitude(string latitude)
	{
		this->latitude = latitude;
	}

	/**
	 * Get the latitude.
	 *
	 * @return The latitude.
	 */
	string getLatitude() const
	{
		return latitude;
	}

	/**
	 * Set the frame prefix.
	 *
	 * @param prefix The frame's prefix to set.
	 */
	void setPrefix(string prefix)
	{
		this->prefix = prefix;
	}

	/**
	 * Get the frame's prefix.
	 *
	 * @return The frame's prefix.
	 */
	string getPrefix() const
	{
		return prefix;
	}
};

#endif /* FRAME_HPP */

