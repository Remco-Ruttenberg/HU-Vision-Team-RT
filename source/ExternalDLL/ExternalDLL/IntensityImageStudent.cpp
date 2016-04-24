#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()), pixel_storage(new Intensity[other.getWidth() * other.getHeight()]) {
	int max = other.getHeight() * other.getWidth();
	for (int i = 0; i < max; ++i) {
		pixel_storage[i] = other.pixel_storage[i];
	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height), pixel_storage(new Intensity[width * height]) {
	/*for (int i = 0; i < width * height; i++) {
		setPixel(i, Intensity());
	}*/
}

IntensityImageStudent::~IntensityImageStudent() {
	delete[] pixel_storage;
	this->pixel_storage = nullptr;
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	delete[] pixel_storage;
	this->pixel_storage = new Intensity[width * height];
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	delete[] pixel_storage;
	this->pixel_storage = new Intensity[getWidth() * getHeight()];
	int max = getHeight() * getWidth();
	for (int i = 0; i < max; ++i) {
		pixel_storage[i] = other.pixel_storage[i];
	}
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	// TODO: Add check for invalid index?
	pixel_storage[y * getWidth() + x] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	// TODO: Add check for invalid index?
	pixel_storage[i] = pixel;
	/*
	* TODO: set pixel i in "Row-Major Order"
	*
	*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	// TODO: Add check for invalid index?
	return pixel_storage[y * getWidth() + x];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	// TODO: Add check for invalid index?
	return pixel_storage[i];
}