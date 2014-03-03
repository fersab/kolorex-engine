//
//  ShaderProgram.cpp
//  ogl-test
//
//  Created by Ferid Sabanovic on 20/02/14.
//  Copyright (c) 2014 Ferid Sabanovic. All rights reserved.
//

#include "ShaderProgram.h"

ShaderProgram::ShaderProgram() {
    this->currentProgramID = glCreateProgram();
};

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(this->currentProgramID);
};

void ShaderProgram::attachShader(Shader* shader) {
	glAttachShader(this->currentProgramID, shader->getCurrentShader());
};

void ShaderProgram::attachUniform4fv(std::string key, GLfloat* value) {
    glUniformMatrix4fv(glGetUniformLocation(this->getCurrentProgram(), key.c_str()), 1, GL_FALSE, value);
};

void ShaderProgram::attachUniform3fv(std::string key, GLfloat *value) {
    glUniformMatrix3fv(glGetUniformLocation(this->getCurrentProgram(), key.c_str()), 1, GL_FALSE, value);
}

GLint ShaderProgram::getAttributeLocation(std::string key) {
    return glGetAttribLocation(this->getCurrentProgram(), key.c_str());
};

void ShaderProgram::linkProgram() {
    
    // Link the program
    std::cout << "Linking program!" << std::endl;
    glLinkProgram(this->currentProgramID);
    
    // Check the program
    GLint linkStatus;
	glGetProgramiv(this->currentProgramID, GL_LINK_STATUS, &linkStatus);
    if(linkStatus != GL_TRUE) {
        GLint infoLogLength;
        glGetProgramiv(this->currentProgramID, GL_INFO_LOG_LENGTH, &infoLogLength);
        if ( infoLogLength > 0 ){
            GLchar * infoLog = new GLchar(infoLogLength + 1);
            glGetProgramInfoLog(this->currentProgramID, infoLogLength, NULL, infoLog);
            std::cout << "Link InfoLog => " << infoLog << std::endl;
            delete infoLog;
            this->currentProgramID = 0;
        }
    }
    
    glUseProgram(this->getCurrentProgram());
};

GLuint ShaderProgram::getCurrentProgram() {
    return this->currentProgramID;
}