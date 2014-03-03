//
//  Window.h
//  ogl-test
//
//  Created by Ferid Sabanovic on 19/02/14.
//  Copyright (c) 2014 Ferid Sabanovic. All rights reserved.
//

#ifndef __ogl_test__Window__
#define __ogl_test__Window__

#define GLFW_INCLUDE_GLCOREARB
#include <iostream>
#include <GLFW/glfw3.h>

struct FrameBufferSize {
    int width;
    int height;
};

class Window {
    
private:
    GLFWwindow* window;
    FrameBufferSize frameBufferSize;
    
public:
    Window(int width, int height, std::string title);
    bool shouldClose();
    void swapBuffers();
    FrameBufferSize getFrameBufferSize();
    ~Window();
};


#endif /* defined(__ogl_test__Window__) */


