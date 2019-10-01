//
//  Demo2.cpp
//  Engine
//
//  Created by harry on 2019/10/5.
//

#include <iostream>
#include "Demo2.h"
#include "cocos2d.h"
#include "renderer/CCGLProgramCache.h"

USING_NS_CC;

void Demo2::initGLProgram() {
	_glPrgram = GLProgramCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_COLOR);
}

void Demo2::run() {
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

	glDrawArrays(GL_TRIANGLES, 0, 3);
}
