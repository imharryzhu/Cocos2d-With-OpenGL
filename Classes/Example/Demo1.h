//
//  Demo1.h
//  Engine
//
//  Created by harry on 2019/10/5.
//
// 不使用cocos2d提供的方法，绘制一个三角形

#ifndef Demo1_h
#define Demo1_h

#include "DemoBase.h"
#include "renderer/CCGLProgram.h"

class Demo1 : public Demo
{
public:
    virtual void run(float) override;
    
	GLuint initGLProgram();

private:
    GLuint _glPrgram = 0;
};

#endif
