//
//  RenderEngine.cpp
//  ogl-test
//
//  Created by Ferid Sabanovic on 20/02/14.
//  Copyright (c) 2014 Ferid Sabanovic. All rights reserved.
//

#include <algorithm>
#include "RenderEngine.h"

RenderEngine::RenderEngine(){
    
	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	this->Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    
	// Or, for an ortho camera :
	//glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // In world coordinates
	
    
	// Camera matrix
	this->View = glm::lookAt(glm::vec3(4,3,3),  // Camera is at (4,3,3), in World Space
                             glm::vec3(0,0,0),  // and looks at the origin
                             glm::vec3(0,1,0)); // Head is up (set to 0,-1,0 to look upside-down)
                             
   
	// Model matrix : an identity matrix (model will be at the origin)
	this->Model = glm::mat4(1.0f);

	// Our ModelViewProjection : multiplication of our 3 matrices
	this->MVP = Projection * View * Model; // Remember, matrix multiplication is the other way around
    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_CULL_FACE);
    
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_COLOR);
    //glEnable(GL_BLEND);
    
    
}

glm::mat4 RenderEngine::getMVP() {
    return this->MVP;
}

glm::mat4 RenderEngine::getView() {
    return this->View;
}

void RenderEngine::addMeshObject(MeshObject* mesh) {
    this->meshObjectBuffer.push_back(mesh);
}


void RenderEngine::render() {
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    for(MeshObject* singleMeshObject: this->meshObjectBuffer) {
        singleMeshObject->draw();
    }

}

