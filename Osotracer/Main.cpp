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
	Camera* camera = new OrthogonalCamera(glm::vec3(0, 0, 0), glm::vec3(0, 0, 1), glm::vec3(0, 1, 0), 1, 1);
    Material mat = Material{ {1.0, 0.0, 0.0}, {1.0, 1.0, 0.0}, {1.0, 0.0, 1.0}, 0.5f};
	Material green = Material{ {0.0, 1.0, 0.0}, {0.f, 1.0, 0.f}, {0.2f, 1.0, 0.2f}, 0.2f };
	Object* ball = new Sphere(glm::vec3(0, 0, 2), 1, mat);
	Object* plane = new Plane(glm::vec3(0, 0, 0), glm::vec3(0, 1, 0), mat);
	ObjectList sceneObjects = ObjectList();
	sceneObjects.addObject(ball);
	sceneObjects.addObject(plane);
	Scene scene = Scene(sceneObjects);
	
	
	// create a test scene with a ball in the middle

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