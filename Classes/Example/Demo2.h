//
//  Demo2.h
//  Engine
//
//  Created by harry on 2019/10/5.
//
// 使用cocos2d提供的方法，绘制一个三角形

#ifndef Demo2_h
#define Demo2_h

#include "DemoBase.h"

namespace cocos2d {
    class GLProgram;
};

class Demo2 : public Demo
{
public:
	virtual void run(float) override;

	void initGLProgram();

private:
	cocos2d::GLProgram *_glPrgram = nullptr;
};

#endif
