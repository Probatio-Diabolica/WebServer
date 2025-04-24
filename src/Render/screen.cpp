#include "screen.hpp"
#include<iostream>
#include "GLFW/glfw3.h"
screen::screen()
{
    std::cout<<"here\n";
}

void screen::run()
{
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return;
    }

    // Set GLFW window hints (optional, e.g., OpenGL version)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW Window", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return ;
    }

    // Make the OpenGL context current
    glfwMakeContextCurrent(window);

    // Set the swap interval (for VSync, optional)
    glfwSwapInterval(1);

    // Main render loop
    while (!glfwWindowShouldClose(window)) {
        // Clear the screen with a color
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }
    // Clean up and exit
    glfwDestroyWindow(window);
    glfwTerminate();
}

void screen::operator()()
{
    run();
}

screen::~screen()
{
    std::cout<<"exit\n";
}
