#include "StudentHelper.h"

std::vector<unsigned long> StudentHelper::createHistogram(const IntensityImage & image, bool vertical)
{
	std::vector<unsigned long> histogram(vertical ? image.getWidth() : image.getHeight());
	int hsize = histogram.size();
	for (int x = 0; x < image.getWidth(); ++x) {
		for (int y = 0; y < image.getHeight(); ++y) {
			if (image.getPixel(x, y) == 0x00)
				try
			{
				histogram.at(vertical ? x : y)++;
			}
			catch (const std::exception& ex)
			{
				std::cout << ex.what() << std::endl <<
					"size= " << hsize << ";x=" << x << ";y=" << y << ";vertical=" << vertical << std::endl;
			}
		}
	}
	return histogram;
}

void StudentHelper::createHistogramImage(const std::vector<unsigned long>& data, std::string filename) {
	if (ImageIO::isInDebugMode) {
		unsigned long max_elem = *std::max_element(data.begin(), data.end());
		IntensityImage * image = ImageFactory::newIntensityImage(data.size(), (*std::max_element(data.begin(), data.end())) + 1);
		int max = image->getWidth() * image->getHeight();
		for (int i = 0; i < max; ++i) {
			image->setPixel(i, Intensity(255));
		}
		for (int x = 0; x < data.size(); ++x) {
			for (int y = 0; y < data.at(x); ++y) {
				image->setPixel(x, max_elem - y, Intensity(0));
			}
		}

		ImageIO::saveIntensityImage(*image, ImageIO::getDebugFileName(filename + ".png"));
		delete image;
		image = nullptr;
	}
}