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
	Demo *_demo;

private:
	DirectorCustom();
};

#endif
