//
//  Window.cpp
//  ogl-test
//
//  Created by Ferid Sabanovic on 19/02/14.
//  Copyright (c) 2014 Ferid Sabanovic. All rights reserved.
//

#include "Window.h"

void error_callback(int error, const char* description) {
    fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}


Window::Window(int width, int height, std::string title) {
    
    glfwSetErrorCallback(error_callback);
    
    if(!glfwInit()) {
        exit(EXIT_FAILURE);
    }

     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    this->window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    glfwMakeContextCurrent(this->window);
    glfwSetKeyCallback(this->window, key_callback);
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    std::cout << "Available OpenGL Version => " << glGetString(GL_VERSION) << std::endl;
}

Window::~Window() {
    glfwDestroyWindow(this->window);
    glfwTerminate();
}

bool Window::shouldClose() {
    return glfwWindowShouldClose(this->window);
}

void Window::swapBuffers() {
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}

FrameBufferSize Window::getFrameBufferSize() {
    glfwGetFramebufferSize(this->window, &this->frameBufferSize.width, &this->frameBufferSize.height);
    return this->frameBufferSize;
}

