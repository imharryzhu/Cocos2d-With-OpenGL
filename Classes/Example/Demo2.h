//
//  Demo2.h
//  Engine
//
//  Created by harry on 2019/10/5.
//
// ʹ��cocos2d�ṩ�ķ���������һ��������


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

