//
//  RenderEngine.h
//  ogl-test
//
//  Created by Ferid Sabanovic on 20/02/14.
//  Copyright (c) 2014 Ferid Sabanovic. All rights reserved.
//

#ifndef __ogl_test__RenderEngine__
#define __ogl_test__RenderEngine__

#include <iostream>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "RenderEngine.h"
#include "MeshObject.h"

class RenderEngine {
    
private:
    std::vector<MeshObject*> meshObjectBuffer;
    glm::mat4 Projection;
    glm::mat4 View;
    glm::mat4 Model;
    glm::mat4 MVP;
    
public:
    RenderEngine();
    void addMeshObject(MeshObject* mesh);
    void render();
    glm::mat4 getMVP();
    glm::mat4 getView();
};

#endif
