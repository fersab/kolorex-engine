//
//  Material.h
//  kolorex-engine
//
//  Created by Ferid Sabanovic on 09/03/14.
//  Copyright (c) 2014 Ferid Sabanovic. All rights reserved.
//

#ifndef __kolorex_engine__Material__
#define __kolorex_engine__Material__

#define GLFW_INCLUDE_GLCOREARB
#include <iostream>
#include <vector>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <IL/il.h>

#include "ShaderProgram.h"

class Material {
    
private:
    GLuint materialID;
    
public:
    Material(ShaderProgram* shaderProgram, std::string path);
    GLuint getMaterialID();
    
};

#endif /* defined(__kolorex_engine__Material__) */
