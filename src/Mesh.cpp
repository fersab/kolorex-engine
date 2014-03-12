//
//  Mesh.cpp
//  ogl-test
//
//  Created by Ferid Sabanovic on 20/02/14.
//  Copyright (c) 2014 Ferid Sabanovic. All rights reserved.
//

#include "Mesh.h"

Mesh::Mesh(ShaderProgram* shaderProgram,
           std::vector<glm::vec3> vertices,
           std::vector<GLushort> indices,
           std::vector<glm::vec2> uvs,
           std::vector<glm::vec3> normals,
           Material* material) {
    
    this->vertices = vertices;
    this->indices = indices;
    this->uvs = uvs;
    this->normals = normals;
    
    this->positionLocation = shaderProgram->getAttributeLocation("vertexPosition_modelspace");
    this->normalLocation = shaderProgram->getAttributeLocation("normalPosition_modelspace");
    this->uvLocation = shaderProgram->getAttributeLocation("uvPosition");
    
    
    glGenVertexArrays(1, &this->VAO);
    
    glGenBuffers(1, &this->verticesVBO);
    glGenBuffers(1, &this->normalsVBO);
    glGenBuffers(1, &this->uvsVBO);
    glGenBuffers(1, &this->indicesIBO);
    
    this->material = material;
    
}

Mesh::~Mesh() {
    glDeleteBuffers(1, &this->verticesVBO);
    glDeleteBuffers(1, &this->indicesIBO);
    glDeleteBuffers(1, &this->uvsVBO);
    glDeleteBuffers(1, &this->normalsVBO);
    glDeleteVertexArrays(1, &this->VAO);
}

void Mesh::initBuffers() {
    
    glBindVertexArray(this->VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, this->verticesVBO);
    glBufferData(GL_ARRAY_BUFFER,
                 this->vertices.size() * sizeof(glm::vec3),
                 &this->vertices[0],
                 GL_STATIC_DRAW);
    glEnableVertexAttribArray(this->positionLocation);
    glVertexAttribPointer(this->positionLocation, 3, GL_FLOAT, GL_FALSE, 0, 0);
    
    
    glBindBuffer(GL_ARRAY_BUFFER, this->normalsVBO);
    glBufferData(GL_ARRAY_BUFFER,
                 this->normals.size() * sizeof(glm::vec3),
                 &this->normals[0],
                 GL_STATIC_DRAW);
    glEnableVertexAttribArray(this->normalLocation);
    glVertexAttribPointer(this->normalLocation, 3, GL_FLOAT, GL_FALSE, 0, 0);
    
    
    glBindBuffer(GL_ARRAY_BUFFER, this->uvsVBO);
    glBufferData(GL_ARRAY_BUFFER,
                 this->uvs.size() * sizeof(glm::vec2),
                 &this->uvs[0],
                 GL_STATIC_DRAW);
    glEnableVertexAttribArray(this->uvLocation);
    glVertexAttribPointer(this->uvLocation, 2, GL_FLOAT, GL_FALSE, 0, 0);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indicesIBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 this->indices.size() * sizeof(GLushort),
                 &this->indices[0],
                 GL_STATIC_DRAW);
    
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
}

void Mesh::draw() {
    

    glBindTexture(GL_TEXTURE_2D,this->material->getMaterialID());

    glBindVertexArray(this->VAO);
    glDrawElements(GL_TRIANGLES, (GLushort) this->indices.size(), GL_UNSIGNED_SHORT, 0);
    glBindVertexArray(0);
}

std::vector<glm::vec3> Mesh::getVertices() {
    return this->vertices;
}

std::vector<GLushort> Mesh::getIndices() {
    return this->indices;
}

std::vector<glm::vec2> Mesh::getUVs() {
    return this->uvs;
}

std::vector<glm::vec3> Mesh::getNormals() {
    return this->normals;
}

GLint Mesh::getPositionLocation() {
    return this->positionLocation;
}

GLint Mesh::getNormalLocation() {
    return this->normalLocation;
}

GLint Mesh::getUVLocation() {
    return this->uvLocation;
}

GLuint  Mesh::getVerticesVBO() {
    return this->verticesVBO;
}

GLuint Mesh::getNormalsVBO(){
    return this->normalsVBO;
}
GLuint Mesh::getIndicesIBO() {
    return this->indicesIBO;
}

GLuint Mesh::getUVSVBO() {
    return this->uvsVBO;
}

GLuint Mesh::getVAO() {
    return this->VAO;
}