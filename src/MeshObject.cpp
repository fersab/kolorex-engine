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

void MeshObject::loadObject(std::string objectPath) {
    
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(objectPath, aiProcess_CalcTangentSpace | aiProcess_Triangulate);
    
    if(!scene)
    {
        std::cout << "Error during object loading => " << importer.GetErrorString();
        return;
    }

    
    std::vector<Material> localMaterials;
    for (unsigned int m=0; m<scene->mNumMaterials; ++m)
	{
		int texIndex = 0;
		aiString filename;
        
		aiReturn texFound = scene->mMaterials[m]->GetTexture(aiTextureType_DIFFUSE, texIndex, &filename);
        
		while (texFound == AI_SUCCESS) {
			//fill map with textures, OpenGL image ids set to 0
			//textureIdMap[path.data] = 0;
			// more textures?
			texIndex++;
			texFound = scene->mMaterials[m]->GetTexture(aiTextureType_DIFFUSE, texIndex, &filename);
            
            localMaterials.push_back(Material(this->shaderProgram, objectPath.substr(0, objectPath.find_last_of("/\\") + 1) + filename.C_Str()));
		}
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
                uvs.push_back(glm::vec2(theMesh->mTextureCoords[0][i].x, theMesh->mTextureCoords[0][i].y));
        }

        
        if(theMesh->HasFaces()) {
            indices.reserve(3*theMesh->mNumFaces);
            for(int i =0; i<theMesh->mNumFaces; i++) {
                indices.push_back(theMesh->mFaces[i].mIndices[0]);
                indices.push_back(theMesh->mFaces[i].mIndices[1]);
                indices.push_back(theMesh->mFaces[i].mIndices[2]);
            }
        }
        
        Mesh* singleMesh =  new Mesh(this->shaderProgram, vertices, indices,  uvs,  normals, &localMaterials.at(0));
        singleMesh->initBuffers();
        
        this->meshBuffer.push_back(singleMesh);
    }
    
}

void MeshObject::draw() {
    for(Mesh* singleMesh: this->meshBuffer) {
        singleMesh->draw();
    }
}




