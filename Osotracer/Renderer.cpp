#include "glew/include/GL/glew.h"
#include "Renderer.h"
#include "Oso.h"
#include "string"
#include "iostream"
#define SHADER_SOURCE
#include "basic.vert"
#include "basic.frag"

void resizeWindow(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

Renderer::Renderer(GLFWwindow* window, int width, int height)
	: window(window), width(width), height(height), flags(RendererFlags::NONE), imgBuffer(new unsigned char[width * height * 3])
{
	glViewport(0, 0, width, height);
	glfwSetFramebufferSizeCallback(window, resizeWindow);
	const char* cVertShaderCode = vertexShaderSource.c_str();
	const char* cFragShaderCode = fragmentShaderSource.c_str();
	// compile shaders
	vertShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertShader, 1, &cVertShaderCode, NULL);
	glCompileShader(vertShader);
	fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragShader, 1, &cFragShaderCode, NULL);
	glCompileShader(fragShader);

	int resV, resF;
	char info1[512], info2[512];
	glGetShaderiv(vertShader, GL_COMPILE_STATUS, &resV);
	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &resF);
	if (!resV)
	{
		glGetShaderInfoLog(vertShader, 512, NULL, info1);
		std::cout << "Vertex shader compilation failed: " << info1 << std::endl;
	}
	if (!resF)
	{
		glGetShaderInfoLog(fragShader, 512, NULL, info2);
		std::cout << "Fragment shader compilation failed: " << info2 << std::endl;
	}
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertShader);
	glAttachShader(shaderProgram, fragShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertShader);
	glDeleteShader(fragShader);

	// Enable vertex attributes
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(pnVertex), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(pnVertex), (void*)offsetof(pnVertex, normal));
	glEnableVertexAttribArray(1);

}

Renderer::~Renderer()
{
}

bool Renderer::isTracing() const
{
	return flags & RendererFlags::MODE_TRACING;
}

#pragma region controls

void Renderer::registerControls()
{
}

#pragma endregion