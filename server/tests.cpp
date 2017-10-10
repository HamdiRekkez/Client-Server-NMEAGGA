//id$

/** @file frame.cpp
 * @brief Test file implementation.
 *
 * @author Hamdi Rakkez
 */

// Includes from the project.
#include "enums.hpp"
#include "frame.hpp"
#include "utils.hpp"

// Google tests includes.
#include "gtest/gtest.h"

using namespace std;

/** Test the encode and decode for the Frame. */
TEST(Tests, EncodingDecodingFrame1)
{
	string strFrame = "$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,"
		"46.9,M,,*47";

	Frame *frame = new Frame();
	frame->decode(strFrame);

	// We must find the same string.
	ASSERT_EQ(strFrame, frame->encode());

	// Cleanup.
	delete frame;
}

/** Test the encode and decode for the Frame. */
TEST(Tests, EncodingDecodingFrame2)
{
	// The string representation of a frame.
	string strFrame = "$GPGGA,210049.108,4054.943,N,07702.415,W,0,00,,,M,,M,,*5F";

	// Create the frame and fill it.
	Frame *frame = new Frame();
	frame->decode(strFrame);

	// Assert on all the frame attributes.
	ASSERT_EQ(frame->getPrefix(), "$GPGGA");
	ASSERT_EQ(frame->getFixTime(), "210049.108");
	ASSERT_EQ(frame->getLatitude(), "4054.943");
	ASSERT_EQ(getLatitudeDirectionAnnotation(
		frame->getLatitudeDirection()), 'N');
	ASSERT_EQ(frame->getLongitude(), "07702.415");
	ASSERT_EQ(getLongitudeDirectionAnnotation(
		frame->getLongitudeDirection()), 'W');
	ASSERT_EQ(frame->getQualityIndicator(), 0);
	ASSERT_EQ(frame->getSvs(), "00");
	ASSERT_EQ(frame->getHdop(), "");
	ASSERT_EQ(frame->getOrthometricHeight(), "");
	ASSERT_EQ(frame->getOrthometricMeasureUnit(), 'M');
	ASSERT_EQ(frame->getGeoidSeparation(), "");
	ASSERT_EQ(frame->getGeoidSeparationMeasureUnit(), 'M');
	ASSERT_EQ(frame->getAge(), "");
	ASSERT_EQ(frame->getReferenceStationID(), "");
	ASSERT_EQ(frame->getChecksum(), "5F");
}

/** Test the sanity check for the Frame. Test with good frames. */
TEST(Tests, FrameGoodSanityCheckTest)
{
	Frame *frame = new Frame();

	// Correct frames vector.
	vector<string> framesVect = {
		"$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47",
		"$GPGGA,210049.108,4054.943,N,07702.415,W,0,00,,,M,,M,,*5F",
		"$GPGGA,210050.108,4054.943,N,07702.414,W,0,00,,,M,,M,,*56",
		"$GPGGA,210051.108,4054.945,N,07702.413,W,0,00,,,M,,M,,*56",
		"$GPGGA,210052.108,4054.947,N,07702.412,W,0,00,,,M,,M,,*56",
		"$GPGGA,210053.108,4054.948,N,07702.412,W,0,00,,,M,,M,,*58",
	};

	/* We iterate all the list of valid frame, and we assert checkFrameSanity
	 * for all of them. */
	for (vector<string>::const_iterator it = framesVect.begin();
		it != framesVect.end(); it++) {
		frame->decode(*it);
		ASSERT_TRUE(frame->checkFrameSanity());
	}

	// Cleanup.
	delete frame;
}

/** Test the sanity check for the Frame. Test with bad frames. */
TEST(Tests, FrameBadSanityCheckTest)
{
	Frame *frame = new Frame();

	// Correct frames vector.
	vector<string> framesVect = {
		"$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*48",
		"$GPGGA,210049.108,4054.947,N,07702.415,W,0,00,,,M,,M,,*5F",
		"$GPGGA,450050.108,4054.943,N,07702.414,E,0,00,,,M,,M,,*5A"
		"$GPGGA,210051.108,4054.945,N,07702.413,W,0,00,,,M,,M,,*22",
		"$GPGGA,210052.108,4054.947,N,07702.412,E,0,00,,,M,,M,,*58",
		"$GPGGA,820053.108,7854.948,N,07702.412,W,0,00,,,M,,M,,*51",
	};

	/* We iterate all the list of valid frame, and we assert checkFrameSanity
	 * for all of them. */
	for (vector<string>::const_iterator it = framesVect.begin();
		it != framesVect.end(); it++) {
		frame->decode(*it);
		ASSERT_FALSE(frame->checkFrameSanity());
	}

	// Cleanup.
	delete frame;
}

/** Test getNMEAFrameStringToCheck. */
TEST(Tests, TestGetNMEAFrameStringToCheck)
{
	string frame = "$GPGGA,210049.108,4054.943,N,07702.415,W,0,00,,,M,,M,,*5F";

	ASSERT_EQ(getNMEAFrameStringToCheck(frame),
		"GPGGA,210049.108,4054.943,N,07702.415,W,0,00,,,M,,M,,");
}

/** Test getNMEAFrameStringToCheck. */
TEST(Tests, TestComputeNMEAChecksum)
{
	string frame = "$GPGGA,210049.108,4054.943,N,07702.415,W,0,00,,,M,,M,,*5F";

	ASSERT_EQ(computeNMEAChecksum(frame), "5f");
}

/** Test splitString. */
TEST(Tests, TestSplitString)
{
	string frame = "$GPGGA,210049.108,4054.943,N,07702.415,W,0,00,,,M,,M,,*5F";

	vector<string> vec = splitString(frame);
	ASSERT_EQ(vec.size(), 16);
	ASSERT_EQ(vec.at(0), "$GPGGA");
	ASSERT_EQ(vec.at(1), "210049.108");
	ASSERT_EQ(vec.at(2), "4054.943");
	ASSERT_EQ(vec.at(3), "N");
	ASSERT_EQ(vec.at(4), "07702.415");
	ASSERT_EQ(vec.at(5), "W");
	ASSERT_EQ(vec.at(6), "0");
	ASSERT_EQ(vec.at(7), "00");
	ASSERT_EQ(vec.at(8), "");
	ASSERT_EQ(vec.at(9), "");
	ASSERT_EQ(vec.at(10), "M");
	ASSERT_EQ(vec.at(11), "");
	ASSERT_EQ(vec.at(12), "M");
	ASSERT_EQ(vec.at(13), "");
	ASSERT_EQ(vec.at(14), "");
	ASSERT_EQ(vec.at(15), "5F");
}