//
//  DirectorCustom.cpp
//  Engine
//
//  Created by harry on 2019/9/28.
//
#include <iostream>
#include "DirectorCustom.h"
#include "renderer/CCGLProgramCache.h"
#include "DemoBase.h"

USING_NS_CC;

DirectorCustom* DirectorCustom::create() {
    auto pRet = new (std::nothrow) DirectorCustom;
    
    if (pRet && pRet->init()) {
        return pRet;
    } else {
        delete pRet;
        pRet = nullptr;
    }
    return pRet;
}

DirectorCustom::DirectorCustom():
_demo(nullptr)
{

}

void DirectorCustom::runDemo(Demo* demo) {
	_demo = demo;
}

void DirectorCustom::mainLoop() {
    drawScene();
}

void DirectorCustom::drawScene() {
	// 计算帧间隔时间 _deltaTime
    calculateDeltaTime();
    
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

	if (_demo) {
		_demo->run(_deltaTime);
	}

	showStats();

    // 显存和屏幕之间的交互，也就是最终绘制到屏幕的操作
    if (_openGLView) {
        _openGLView->swapBuffers();
    }
}
