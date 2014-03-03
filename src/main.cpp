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
    Window* window = new Window(800, 600, "kolorex engine");
    
    
    
    RenderEngine* renderEngine = new RenderEngine();
    
    Shader* vertexShader = new Shader("/Users/feridsabanovic/projects/private/kolorex-engine/shaders/BasicShader.vertex", GL_VERTEX_SHADER);
    Shader* fragmentShader = new Shader("/Users/feridsabanovic/projects/private/kolorex-engine/shaders/BasicShader.fragment", GL_FRAGMENT_SHADER);
    
    ShaderProgram* shaderProgram = new ShaderProgram();
    shaderProgram->attachShader(vertexShader);
    shaderProgram->attachShader(fragmentShader);
    shaderProgram->linkProgram();
    
    
    MeshObject* meshObject = new MeshObject(shaderProgram);
    
    meshObject->loadObject("/Users/feridsabanovic/bun.3ds");
    meshObject->loadObject("/Users/feridsabanovic/cube.obj");
    
    renderEngine->addMeshObject(meshObject);
    
    
    // Main Loop
    while (!window->shouldClose()) {
        glViewport(0, 0, window->getFrameBufferSize().width, window->getFrameBufferSize().height);
        
        glm::mat4 ModelMatrix = glm::mat4(1.0);
        ModelMatrix = glm::rotate(ModelMatrix, (float) glfwGetTime() * 47.0f, glm::vec3(0.0f, 1.0f, 0.0f));
        
        shaderProgram->attachUniform4fv("MVP", &renderEngine->getMVP()[0][0]);
        shaderProgram->attachUniform4fv("M", &ModelMatrix[0][0]);
        shaderProgram->attachUniform4fv("V", &renderEngine->getView()[0][0]);
        
        
        renderEngine->render();
        
        window->swapBuffers();
    }
    
    
    delete meshObject;
    delete renderEngine;
    delete vertexShader;
    delete fragmentShader;
    delete shaderProgram;
    delete window;
    return 0;
}


