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
    
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

	if (_demo) {
		_demo->run();
	}

    // 显存和屏幕之间的交互，也就是最终绘制到屏幕的操作
    if (_openGLView) {
        _openGLView->swapBuffers();
    }
}

void DirectorCustom::helleTriangleMVP() {
	// 顶点坐标和颜色 [0]左下 [1]顶 [2]右下
	auto size = Director::getInstance()->getVisibleSize();
	float vertices[] = {
		0, 0, 0,
		size.width, 0, 0,
		size.width/2, size.height, 0
	};
	float colors[] = {
		1, 0, 0, 1,
		0, 1, 0, 1,
		0, 0, 1, 1,
	};

	// 着色器代码
	const char * vert = R"(
        attribute vec4 a_position;
        attribute vec4 a_color;
        varying vec4 v_fragmentColor;

        void main()
        {
            gl_Position = CC_MVPMatrix * a_position;
            v_fragmentColor = a_color;
        }
    )";

	const char * frag = R"(
        varying vec4 v_fragmentColor;
		uniform vec4 u_color;		

		void main()
		{
			gl_FragColor = v_fragmentColor * u_color;
		}
    )";

	GLProgram* glProgram = GLProgram::createWithByteArrays(vert, frag);
	glProgram->use();
	glProgram->setUniformsForBuiltins();

	GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION | GL::VERTEX_ATTRIB_FLAG_COLOR);
	glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 3, GL_FLOAT, GL_FALSE, 0, vertices);
	glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_FLOAT, GL_FALSE, 0, colors);

	float redValue = (sin(_t) / 2.0f) + 0.5f;
	float greenValue = (cos(_t) / 2.0f) + 0.5f;
	float blueValue = (tan(_t) / 2.0f) + 0.5f;
	GLint vColorLocation = glProgram->getUniformLocation("u_color");
	glProgram->setUniformLocationWith4f(vColorLocation, redValue, greenValue, blueValue, 1.0f);

	// 绘制，三角形
	glDrawArrays(GL_TRIANGLES, 0, 3);
}


MyGLPrograms* MyGLPrograms::_instance = nullptr;

MyGLPrograms* MyGLPrograms::getInstance() {
	if (!_instance) {
		_instance = new MyGLPrograms;
		_instance->init();
	}
	return _instance;
}

bool MyGLPrograms::init() {

	// 创建GLProgram对象，注意这是cocos2d提供的
	_glProgram = new GLProgram;

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


	_glProgram->initWithByteArrays(vert, frag);
	_glProgram->link();
	

	return true;
}
