#include <iostream>
#define GLEW_STATIC
#include "glew/include/GL/glew.h"
#include "glfw64/include/GLFW/glfw3.h"
#include "Tracer.h"
#include "Camera.h"
#include "Scene.h"

int main(void){

    int windowWidth = 640;
    int windowHeight = 480;

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(windowWidth, windowHeight, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    auto okay = glewInit();

    if (GLEW_OK != okay)
        return -1; //something is off
	
	// Initialize members required for rendering
    Camera camera = OrthogonalCamera();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;


}