#pragma once
#include <iostream>
#include <vector>
#include "ImageIO.h"
#include "ImageFactory.h"

// Helper file for functions like histogram creation
class StudentHelper
{
public:
	/// Creates a histogram based on the supplied Intensity Image
	/// \param image the image to create the histogram data from
	/// \param vertical <b>true</b> measure number of black pixels along vertical axis, <b>false</b> for horizontal
	/// \return a vector list of frequencies
	std::vector<unsigned long> createHistogram(const IntensityImage & image, bool vertical);

	/// Creates a histogram based on the supplied data
	/// Exported file is a .png file
	/// \param data the date to create the histogram from
	/// \param filename the filename of the histogram (without extension)
	void createHistogramImage(const std::vector<unsigned long> & data, std::string filename);
};