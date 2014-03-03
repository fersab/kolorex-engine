//
//  MeshObject.cpp
//  ogl-test
//
//  Created by Ferid Sabanovic on 28/02/14.
//  Copyright (c) 2014 Ferid Sabanovic. All rights reserved.
//


#include "MeshObject.h"

MeshObject::MeshObject(ShaderProgram* shaderProgram) {
    this->shaderProgram = shaderProgram;
}

MeshObject::~MeshObject() {
    
}

ShaderProgram* MeshObject::getCurrentShaderProgram() {
    return this->shaderProgram;
}

void MeshObject::loadObject(std::string path) {
    
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path, aiProcess_CalcTangentSpace | aiProcess_Triangulate);
    
    if(!scene)
    {
        std::cout << "Error during object loading => " << importer.GetErrorString();
        return;
    }
    
    
    for(int i=0; i<scene->mNumMeshes; i++) {
        
        aiMesh* theMesh = scene->mMeshes[i];
        
        std::vector<glm::vec3> vertices;
        std::vector<GLushort> indices;
        std::vector<glm::vec2> uvs;
        std::vector<glm::vec3> normals;
        
        vertices.reserve(theMesh->mNumVertices);
        for(int i =0; i<theMesh->mNumVertices; i++) {
            vertices.push_back(glm::vec3(theMesh->mVertices[i].x , theMesh->mVertices[i].y, theMesh->mVertices[i].z));
        }
        
        if(theMesh->HasNormals()) {
            normals.reserve(theMesh->mNumVertices);
            for(int i=0; i<theMesh->mNumVertices; i++) {
                normals.push_back(glm::vec3(theMesh->mNormals[i].x, theMesh->mNormals[i].y, theMesh->mNormals[i].z));
            }
        }
        
        
        uvs.reserve(theMesh->mNumVertices);
        for(int i =0; i<theMesh->mNumVertices; i++) {
            if(theMesh->HasTextureCoords(i)) {
                uvs.push_back(glm::vec2(theMesh->mTextureCoords[0][i].x, theMesh->mTextureCoords[0][i].y));
            }
        }
        
        if(theMesh->HasFaces()) {
            indices.reserve(3*theMesh->mNumFaces);
            for(int i =0; i<theMesh->mNumFaces; i++) {
                indices.push_back(theMesh->mFaces[i].mIndices[0]);
                indices.push_back(theMesh->mFaces[i].mIndices[1]);
                indices.push_back(theMesh->mFaces[i].mIndices[2]);
            }
        }
        
        Mesh* singleMesh =  new Mesh(this->shaderProgram, vertices, indices,  uvs,  normals);
        singleMesh->initBuffers();
        
        this->meshBuffer.push_back(singleMesh);
    }
    
}

void MeshObject::draw() {
    for(Mesh* singleMesh: this->meshBuffer) {
        singleMesh->draw();
    }
}




