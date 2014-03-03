//
//  MeshObject.h
//  ogl-test
//
//  Created by Ferid Sabanovic on 28/02/14.
//  Copyright (c) 2014 Ferid Sabanovic. All rights reserved.
//

#ifndef __ogl_test__MeshObject__
#define __ogl_test__MeshObject__


#define GLFW_INCLUDE_GLCOREARB
#include <iostream>
#include <vector>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "ShaderProgram.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "ShaderProgram.h"
#include "Mesh.h"

class MeshObject {
    
private:
    std::vector<Mesh*> meshBuffer;
    ShaderProgram* shaderProgram;

public:
    MeshObject(ShaderProgram* shaderProgram);
    ShaderProgram* getCurrentShaderProgram();
    
    void loadObject(std::string path);
    void draw();
    
    ~MeshObject();

};

#endif /* defined(__ogl_test__MeshObject__) */
