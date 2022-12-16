#pragma once
#include <cstdint>


struct floatColor { // colors from 0 to 1 for each channel
	float r;
	float g;
	float b;
};

struct floatColorA : floatColor { // colors from 0 to 1 for each channel with alpha channel
	float a;
};

struct color {
	uint8_t r, g, b;
};