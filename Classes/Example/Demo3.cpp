//
//  Demo3.cpp
//  Engine
//
//  Created by harry on 2019/10/6.
//

#include "Demo3.h"
#include "cocos2d.h"
#include "renderer/CCGLProgramCache.h"

USING_NS_CC;

void Demo3::initGLProgram() {
    // shader
    const char * vert = R"(
        attribute vec4 a_position;
        attribute vec4 a_color;
        varying vec4 v_fragmentColor;

        void main()
        {
            gl_Position = CC_PMatrix * a_position;
            v_fragmentColor = a_color;
        }
    )";

    const char * frag = R"(
        varying vec4 v_fragmentColor;
        uniform vec4 u_color;

        void main()
        {
            gl_FragColor = u_color;
        }
    )";
    
    _glPrgram = GLProgram::createWithByteArrays(vert, frag);
}

void Demo3::run(float dt) {
    if (!_glPrgram) {
        initGLProgram();
    }

    auto size = Director::getInstance()->getVisibleSize();

    float vertices[] = {
        0, 0,
        size.width/2, size.height,
        size.width, 0,
    };
    float colors[] = {
        1, 0, 0, 1,
        0, 1, 0, 1,
        0, 0, 1, 1,
    };

    GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION | GL::VERTEX_ATTRIB_FLAG_COLOR);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 2, GL_FLOAT, GL_FALSE, 0, vertices);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_FLOAT, GL_FALSE, 0, colors);

    _glPrgram->use();
    _glPrgram->setUniformsForBuiltins();
    
    _t += dt;
    
    
    float r = sin(_t) / 2 + 0.5f;
    float g = 0;
    float b = 0;
    
    GLint colorLocation = _glPrgram->getUniformLocation("u_color");
    _glPrgram->setUniformLocationWith4f(colorLocation, r, g, b, 1.0f);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}

