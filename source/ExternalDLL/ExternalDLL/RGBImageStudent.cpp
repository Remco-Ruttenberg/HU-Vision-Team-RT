#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()), pixel_storage(new RGB[getWidth()*getHeight()]) {
	int max = other.getHeight() * other.getWidth();
	for (int i = 0; i < max; ++i) {
		setPixel(i, other.getPixel(i));
	}
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height), pixel_storage(new RGB[width*height]) {
	/*for (int i = 0; i < width * height; ++i) {
		setPixel(i, RGB());
	}*/
}

RGBImageStudent::~RGBImageStudent() {
	delete[] pixel_storage;
	pixel_storage = nullptr;
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	delete[] pixel_storage;
	pixel_storage = new RGB[width * height];
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	delete[] pixel_storage;
	pixel_storage = new RGB[getWidth(), getHeight()];
	int max = getWidth() * getHeight();
	for (int i = 0; i < max; ++i) {
		setPixel(i, getPixel(i));
	}
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	// TODO: Add check for invalid index?
	pixel_storage[(x * y) + y] = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
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

RGB RGBImageStudent::getPixel(int x, int y) const {
	// TODO: Add check for invalid index?
	return pixel_storage[(x * y) + y];
}

RGB RGBImageStudent::getPixel(int i) const {
	// TODO: Add check for invalid index?
	return pixel_storage[i];
}