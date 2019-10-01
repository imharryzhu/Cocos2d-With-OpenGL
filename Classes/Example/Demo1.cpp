//
//  Demo1.cpp
//  Engine
//
//  Created by harry on 2019/10/5.
//

#include <iostream>
#include "Demo1.h"
#include "cocos2d.h"


USING_NS_CC;

GLuint Demo1::initGLProgram() {
    // shader
    const char * vert = R"(
        attribute vec4 a_position;
        attribute vec4 a_color;
        varying vec4 v_fragmentColor;

        void main()
        {
            gl_Position = a_position;
            v_fragmentColor = a_color;
        }
    )";

    const char * frag = R"(
        varying vec4 v_fragmentColor;

        void main()
        {
            gl_FragColor = v_fragmentColor;
        }
    )";

    int succ;
    char infoLog[512];

    // ≥ı ºªØ∂•µ„◊≈…´∆˜
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vert, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &succ);
    if (!succ) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        return 0;
    }

    // ≥ı ºªØ∆¨‘™◊≈…´∆˜
    GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &frag, NULL);
    glCompileShader(fragShader);
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &succ);
    if (!succ) {
        glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        return 0;
    }

    GLuint glProgram = glCreateProgram();
    glAttachShader(glProgram, vertexShader);
    glAttachShader(glProgram, fragShader);
    glLinkProgram(glProgram);
    glGetProgramiv(glProgram, GL_LINK_STATUS, &succ);
    if (!succ) {
        glGetShaderInfoLog(fragShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        return 0;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);

    return glProgram;
}

void Demo1::run() {
    if (_glPrgram == 0) {
        _glPrgram = initGLProgram();
    }

    // ∂•µ„◊¯±Í∫Õ—’…´ [0]◊Ûœ¬ [1]∂• [2]”“œ¬
    float vertices[] = {
        -1, -1,
        1, -1,
        0, 1,
    };
    float colors[] = {
        1, 0, 0, 1,
        0, 1, 0, 1,
        0, 0, 1, 1,
    };
    
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, colors);

    // GL use
    glUseProgram(_glPrgram);

    // ªÊ÷∆£¨»˝Ω«–Œ
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDeleteProgram(_glPrgram);
}

