#pragma once
#include "Image.h"

enum RendererFlags : uint8_t
{
	NONE = 0,
	MODE_TRACING = 1 << 0,
	MODE_RASTER = 1 << 1,
};

class Renderer
{
public:
	Renderer(GLFWwindow* window, int width, int height);
	~Renderer();

	bool isTracing() const;

private:
	// functions
	void registerControls();
	// members
	// window
	std::shared_ptr<GLFWwindow> window;
	int width;
	int height;
	// rasterization members
	GLuint vertShader;
	GLuint fragShader;
	GLuint shaderProgram;
	// ray tracing
	GLuint rayTraceShader;
	GLuint rayTraceProgram;
	// ray tracer
	RayTracer rayTracer;

	// create buffer for image
	std::unique_ptr<unsigned char> imgBuffer;
	uint8_t flags;
};

