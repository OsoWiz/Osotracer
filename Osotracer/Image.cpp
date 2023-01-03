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

void writeGL(GLFWwindow* window, const unsigned char* buffer)
{
	GLsizei width, height;
	// get width and height of the window
	glfwGetFramebufferSize(window, &width, &height);
	// clear and draw, then flush and swap
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, buffer);
	glFlush();
	glfwSwapBuffers(window);
}
