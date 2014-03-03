//
//  Shader.cpp
//  ogl-test
//
//  Created by Ferid Sabanovic on 19/02/14.
//  Copyright (c) 2014 Ferid Sabanovic. All rights reserved.
//

#define GLFW_INCLUDE_GLCOREARB

#include "Shader.h"

Shader::Shader(std::string shader_file_path, GLenum shaderType) {
    
    this->currentShaderID = glCreateShader(shaderType);
    
    std::string shaderSourceCode;
    std::ifstream sourceFile(shader_file_path.c_str());
    
    //Source file loaded
    if( sourceFile ) {
        //Get shader source
        shaderSourceCode.assign( ( std::istreambuf_iterator< char >( sourceFile ) ), std::istreambuf_iterator< char >() );
    }else{
        std::cout << "Impossible to open " << shader_file_path << " Are you in the right directory\n" << std::endl;
        this->currentShaderID = 0;
	}
    
    
    std::cout << "Compiling shader: " << shader_file_path << std::endl;
	char const * sourcePointer = shaderSourceCode.c_str();
	glShaderSource(this->currentShaderID, 1, &sourcePointer , NULL);
	glCompileShader(this->currentShaderID);
    
	   
    GLint compileStatus;
	glGetShaderiv(this->currentShaderID, GL_COMPILE_STATUS, &compileStatus);
    if(compileStatus != GL_TRUE) {
        std::cout << "Shader failed to compile from path => " << shader_file_path << std::endl;
   
        GLint infoLogLength;
        glGetShaderiv(this->currentShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
        if ( infoLogLength > 0 ){
            GLchar * infoLog = new GLchar(infoLogLength + 1);
            glGetShaderInfoLog(this->currentShaderID, infoLogLength + 1, NULL, infoLog);
            std::cout << "Compile InfoLog => " << infoLog << std::endl;
            delete infoLog;
            this->currentShaderID = 0;
        }
    }
	
}

Shader::~Shader() {
    glDeleteShader(currentShaderID);
}


GLuint Shader::getCurrentShader() {
    return this->currentShaderID;
}

