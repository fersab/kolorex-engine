//
//  Mesh.h
//  ogl-test
//
//  Created by Ferid Sabanovic on 20/02/14.
//  Copyright (c) 2014 Ferid Sabanovic. All rights reserved.
//

#ifndef __ogl_test__Mesh__
#define __ogl_test__Mesh__

#define GLFW_INCLUDE_GLCOREARB
#include <iostream>
#include <vector>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "ShaderProgram.h"
#include "Material.h"

class Mesh {
    
private:
    
    GLuint VAO;
    
    GLint positionLocation;
    GLint uvLocation;
    GLint normalLocation;
    
    GLuint verticesVBO;
    GLuint uvsVBO;
    GLuint normalsVBO;
    GLuint indicesIBO;

    std::vector<glm::vec3> vertices;
    std::vector<GLushort> indices;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> normals;
    
    Material* material;
    
public:
    Mesh(ShaderProgram* shaderProgram,
         std::vector<glm::vec3> vertices,
         std::vector<GLushort> indices,
         std::vector<glm::vec2> uvs,
         std::vector<glm::vec3> normals,
         Material* material);
    
    std::vector<glm::vec3> getVertices();
    std::vector<GLushort> getIndices();
    std::vector<glm::vec2> getUVs();
    std::vector<glm::vec3> getNormals();
    
    GLint getPositionLocation();
    GLint getUVLocation();
    GLint getNormalLocation();
    
    GLuint getVerticesVBO();
    GLuint getNormalsVBO();
    GLuint getIndicesIBO();
    GLuint getUVSVBO();
    GLuint getVAO();
    
    void initBuffers();
    void draw();
    
    ~Mesh();
};


#endif /* defined(__ogl_test__Mesh__) */
