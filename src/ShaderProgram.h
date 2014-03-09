//
//  ShaderProgram.h
//  ogl-test
//
//  Created by Ferid Sabanovic on 20/02/14.
//  Copyright (c) 2014 Ferid Sabanovic. All rights reserved.
//

#ifndef __ogl_test__ShaderProgram__
#define __ogl_test__ShaderProgram__

#include <iostream>
#include <GLFW/glfw3.h>
#include "Shader.h"


class ShaderProgram {
    
private:
    GLuint currentProgramID;
    
public:
    ShaderProgram();
    ~ShaderProgram();
    void linkProgram();
    void attachShader(Shader* shader);
    void attachUniform4fv(std::string key, GLfloat* value);
    void attachUniform3fv(std::string key, GLfloat* value);
    void attachUniform1i(std::string key, GLint value);
    GLint getAttributeLocation(std::string key);
    GLuint getCurrentProgram();
};

#endif /* defined(__ogl_test__ShaderProgram__) */
