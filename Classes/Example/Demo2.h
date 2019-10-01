//
//  Demo2.h
//  Engine
//
//  Created by harry on 2019/10/5.
//
// 使用cocos2d提供的方法，绘制一个三角形


#include "DemoBase.h"
#include "renderer/CCGLProgram.h"

class cocos2d::GLProgram;

class Demo2 : public Demo
{
public:
	virtual void run();

	void initGLProgram();

private:
	cocos2d::GLProgram *_glPrgram = nullptr;
};

