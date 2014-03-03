//
//  Shader.h
//  ogl-test
//
//  Created by Ferid Sabanovic on 19/02/14.
//  Copyright (c) 2014 Ferid Sabanovic. All rights reserved.
//

#ifndef __ogl_test__Shader__
#define __ogl_test__Shader__

#include <iostream>
#include <fstream>
#include <GLFW/glfw3.h>

class Shader {
    
private:
    GLuint currentShaderID;
    
public:
    Shader(std::string shader_file_path, GLenum shaderType);
    ~Shader();
    GLuint getCurrentShader();
};

#endif /* defined(__ogl_test__Shader__) */
