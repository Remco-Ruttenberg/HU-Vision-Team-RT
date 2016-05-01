#pragma once
#include <vector>
#include "ImageIO.h"
#include "ImageFactory.h"

// Helper file for functions like histogram creation
class StudentHelper
{
public:
	/// Creates a histogram based on the supplied data
	/// Exported file is a .png file
	/// \param data the date to create the histogram from
	/// \param filename the filename of the histogram (without extension)
	void createHistogram(const std::vector<unsigned long> & data, std::string filename);
};