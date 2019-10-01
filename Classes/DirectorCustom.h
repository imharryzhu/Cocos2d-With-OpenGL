//
//  DirectorCustom.h
//  Engine
//
//  Created by harry on 2019/9/28.
//

#ifndef DirectorCustom_h
#define DirectorCustom_h

#include "cocos2d.h"

class Demo;

class DirectorCustom : public cocos2d::Director {
public:
    
    static DirectorCustom* create();

	void runDemo(Demo* demo);

    virtual void mainLoop() override;
    virtual void drawScene() override;
    
protected:
	void helleTriangleMVP();

	float _t = 0.0f;

	Demo *_demo;
	cocos2d::GLProgram *_glProgram;

private:
	DirectorCustom();
};

class MyGLPrograms {
public:
	static MyGLPrograms* getInstance();

	bool init();

	cocos2d::GLProgram *_glProgram;

private:
	static MyGLPrograms* _instance;
};

#endif
