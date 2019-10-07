//
//  Demo3.h
//  Engine
//
//  Created by harry on 2019/10/6.
//

#ifndef Demo3_h
#define Demo3_h

#include "DemoBase.h"

namespace cocos2d {
    class GLProgram;
};

class Demo3 : public Demo
{
public:
    virtual void run(float) override;

    void initGLProgram();

private:
    cocos2d::GLProgram *_glPrgram = nullptr;
    float _t = 0.0f;
};

#endif
