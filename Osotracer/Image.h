#pragma once
#include <vector>
#include <fstream>
#include "Colors.h"
// Auxiliary function to write buffer of pixels to a file

void writePPM(const char* filename, int width, int height, const unsigned char* buffer);

// unsigned char* 