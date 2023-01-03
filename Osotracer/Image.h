#pragma once
#include "glfw64/include/GLFW/glfw3.h"
#include <vector>
#include <fstream>
#include "Colors.h"

// Auxiliary function to write buffer of pixels to a file
void writePPM(const char* filename, int width, int height, const unsigned char* buffer);

// write to gl window
void writeGL(GLFWwindow* window, const unsigned char* buffer);