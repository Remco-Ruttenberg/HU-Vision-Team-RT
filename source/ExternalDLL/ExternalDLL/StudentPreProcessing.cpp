#include "StudentPreProcessing.h"


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	int max = image.getHeight() * image.getWidth();
	IntensityImageStudent* ii = new IntensityImageStudent(image.getWidth(), image.getHeight());
	for (int i = 0; i < max; ++i) {
		RGB p = image.getPixel(i);
		ii->setPixel(i, Intensity(p.r * 0.299f + p.g * 0.587f + p.b * 0.114f));
	}
	return ii;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}