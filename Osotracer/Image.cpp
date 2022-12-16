#include "Image.h"

// write buffer to a PPM file
void writePPM(const char* filename, int width, int height, const unsigned char* buffer)
{
	std::ofstream ofs(filename, std::ios::out | std::ios::binary);
	
	for (int i = 0; i < width * height; i++)
	{
		ofs << buffer[i];
	}
}
