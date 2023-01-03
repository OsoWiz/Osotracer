#pragma once
#include <cstdint>

namespace Colors {

	struct floatColor { // colors from 0 to 1 for each channel
		float r;
		float g;
		float b;
		floatColor operator *= (float factor)
			{
			r *= factor;
			g *= factor;
			b *= factor;
				return *this;
			}
		floatColor operator += (floatColor color)
		{
			r += color.r;
			g += color.g;
			b += color.b;
			return *this;
		}
		floatColor operator * (float factor)
		{
			*this *= factor; return *this;
		}
		floatColor operator + (floatColor color)
		{
			*this += color; return *this;
		}
		
	};

	struct floatColorA : floatColor { // colors from 0 to 1 for each channel with alpha channel
		float a;
	};

	struct color {
		uint8_t r, g, b;
	};

	color floatToColor(floatColor color) {
		uint8_t r = (uint8_t)(color.r * 255);
		uint8_t g = (uint8_t)(color.g * 255);
		uint8_t b = (uint8_t)(color.b * 255);
		return { r, g, b };
	};
}