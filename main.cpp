#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main() 
{
    //instantiate GLFW window and set maj/min version to 3.3, set profile to core
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    //create glfw window
    GLFWwindow* window = glfwCreateWindow(800, 600, "TestWindow", NULL, NULL);

    //check window object, if null throw error
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    //check if glad was intitialized, if not throw error
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to init GLAD" << std::endl;
        return -1;
    }

    //set rendering window size
    glViewport(0, 0, 800, 600);

    //call function on every window resize
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //render loop
    while (!glfwWindowShouldClose(window)) {
        //check input
        processInput(window);

        //rendering commands
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        //check and call events, then swap buffers
        glfwPollEvents();
        glfwSwapBuffers(window);
        
    }
    
    glfwTerminate();
    return 0;
}

//check if user resizes window
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    //set viewport dimensions to new width and height
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        //if esc key is registered, set window should close to true
        glfwSetWindowShouldClose(window, true);
}

