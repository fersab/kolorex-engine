//
//  Material.cpp
//  kolorex-engine
//
//  Created by Ferid Sabanovic on 09/03/14.
//  Copyright (c) 2014 Ferid Sabanovic. All rights reserved.
//

#include "Material.h"

Material::Material(ShaderProgram* shaderProgram, std::string path) {
    
    ilInit();
    
    GLuint image = ilGenImage();
    ilBindImage(image);
    
    ilEnable(IL_ORIGIN_SET);
    ilOriginFunc(IL_ORIGIN_LOWER_LEFT);
    ILboolean imageLoaded = ilLoadImage(path.c_str());
    
    glGenTextures(1, &this->materialID);
    
    
    if(imageLoaded) {
        
        ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
        
        glBindTexture(GL_TEXTURE_2D, this->materialID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
                     ilGetInteger(IL_IMAGE_WIDTH),
                     ilGetInteger(IL_IMAGE_HEIGHT),
                     0, GL_RGBA, GL_UNSIGNED_BYTE,
                     ilGetData());
        
        shaderProgram->attachUniform1i("textureSampler", 0);
        
    } else {
        std::cout << "Could not load image" << std::endl;
    }
    
    ilDeleteImage(image);

}

GLuint Material::getMaterialID() {
    return this->materialID;
}