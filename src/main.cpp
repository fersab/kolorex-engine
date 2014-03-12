//
//  main.cpp
//  ogl-test
//
//  Created by Ferid Sabanovic on 18/02/14.
//  Copyright (c) 2014 Ferid Sabanovic. All rights reserved.
//


#include <iostream>


#include "Window.h"
#include "Shader.h"
#include "ShaderProgram.h"
#include "Mesh.h"
#include "RenderEngine.h"


int main(int argc, const char * argv[])
{
    Window window(800, 600, "kolorex-engine");
    
    Shader vertexShader("/Users/feridsabanovic/projects/private/kolorex-engine/shaders/BasicShader.vertex", GL_VERTEX_SHADER);
    Shader fragmentShader("/Users/feridsabanovic/projects/private/kolorex-engine/shaders/BasicShader.fragment", GL_FRAGMENT_SHADER);
    
    ShaderProgram shaderProgram;
    shaderProgram.attachShader(&vertexShader);
    shaderProgram.attachShader(&fragmentShader);
    shaderProgram.linkProgram();
    
    RenderEngine renderEngine;
    
    MeshObject meshObject(&shaderProgram);
    meshObject.loadObject("/Users/feridsabanovic/new_head.3ds");
    renderEngine.addMeshObject(&meshObject);
    
    
    // Main Loop
    while (!window.shouldClose()) {
        glViewport(0, 0, window.getFrameBufferSize().width, window.getFrameBufferSize().height);
        
        glm::mat4 ModelMatrix = glm::mat4(1.0);
        ModelMatrix = glm::rotate(ModelMatrix, (float) -glfwGetTime() * 27.0f, glm::vec3(0.0f, 1.0f, 0.0f));
        
        shaderProgram.attachUniform4fv("MVP", &renderEngine.getMVP()[0][0]);
        shaderProgram.attachUniform4fv("M", &ModelMatrix[0][0]);
        shaderProgram.attachUniform4fv("V", &renderEngine.getView()[0][0]);
        
        
        renderEngine.render();
        
        window.swapBuffers();
    }
    
    return 0;
}


