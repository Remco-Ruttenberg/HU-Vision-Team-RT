#pragma once
#include <iostream>
#include <vector>
#include "ImageIO.h"
#include "ImageFactory.h"

// Helper file for functions like histogram creation
class StudentHelper
{
public:
	template<int Width, int Height>
	class Kernel
	{
	public:
		enum KernelCreationMode
		{
			Manual = 0x0,
			HorizontalMirrored = 0x1,
			VerticalMirrored = 0x2,
			Mirrored = HorizontalMirrored | VerticalMirrored,
			HorizontalSequential = 0x4,
			VerticalSequential = 0x6,
			Sequential = HorizontalSequential | VerticalSequential
		};

		Kernel() {
			if (Width < 1 || Height < 1) {
				throw std::invalid_argument("Kernel must be at least 1x1 in size!");
			}
			if (Width % 2 == 0 || Height % 2 == 0) {
				throw std::invalid_argument("Kernel does not (yet) support even sizes!");
			}
			for (int x = 0; x < Width; x++) {
				for (int y = 0; y < Height; y++) {
					kernel[x][y] = 0; // Necessary?
				}
			}
		}

		/// WORK IN PROGRESS

		/// Creates a kernel based on the supplied arguments
		/// \param mode this will create the kernel based on the mode type and specified values
		/// \param xvalues all the values the kernel will contain along the horizontal axis, applied according to the mode
		/// \param yvalues all the values the kernel will contain along the vertical axis, applied according to the mode
		/// \param size the size of the specified kernel. [width,height] . Only required for manual mode
		/// \return the generated kernel
		Kernel createKernel(KernelCreationMode mode, std::vector<int> xvalues, std::vector<int> yvalues, int size [2]) {
			if (xvalues.size() < 1) {
				throw std::invalid_argument("Kernel must be at least 1x1 in size!");
			}
			if (mode != KernelCreationMode::Manual && mode != KernelCreationMode::Mirrored && yvalues.size() < 1) {
				throw std::invalid_argument("Kernel must be at least 1x1 in size!");
			}
			if (mode != KernelCreationMode::Sequential) {
				throw std::runtime_error("Specified KernelCreationMode of " + (int)mode + " is not yet supported!");
			}
			int width = (mode == KernelCreationMode::Manual) ? size[0] : xvalues;
			width = (mode == KernelCreationMode::HorizontalMirrored) ? width / 2 + width % 2 : width;
			int height = (mode == KernelCreationMode::Manual) ? size[1] : yvalues;
			height = (mode == KernelCreationMode::VerticalMirrored) ? height / 2 + height % 2 : height;
			Kernel<width, height> k;

			switch (mode)
			{
			Sequential:
				for (int x = 0; x < xvalues.size(); ++x) {
					for (int y = 0; y < yvalues.size(); ++y) {
						k.kernel[x][y] = 0;
					}
				}
			}

			return k;
		}

		IntensityImage* createImageFromKernel(const IntensityImage & image, Kernel k) {
			IntensityImage * im = ImageFactory::newIntensityImage(image);
			if (im->getHeight() < k.getHeight() || im->getWidth() < k.getWidth()) {
				throw std::invalid_argument("Kernel is too big for the image!");
			}
			
			for (int x = 0; x < image.getWidth(); ++x) {
				for (int y = 0; y < image.getHeight(); y++) {
					// Apply kernel logic to pixel
					//im->setPixel(x, y, )
				}
			}
		}

		int getWidth() {
			return Width;
		}

		int getHeight() {
			return Height;
		}

		long getTotalWeight() {
			long total = 0;
			for (int x = 0; x < Width; ++x) {
				for (int y = 0; y < Height; y++)	{
					total += kernel[x][y];
				}
			}
			return total;
		}

		static Kernel<5,5> GuassianSmoothing_5x5() {
			return{
				{1,2,3,2,1},
				{2,7,11,7,2},
				{3,11,17,11,3},
				{2,7,11,7,2},
				{1,2,3,2,1}
			};
		}

		static Kernel<3,3> Edge3x3_8Minus1() {
			return{
				{-1,-1,-1},
				{-1,8,-1},
				{-1,-1,-1}
			};
		}

		static Kernel<3,3> Identity3x3() {
			return{
				{0,0,0},
				{0,1,0},
				{0,0,0} };
		}
	private:
		int kernel[Width][Height];
	};

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