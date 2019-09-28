//
//  DirectorCustom.h
//  Engine
//
//  Created by harry on 2019/9/28.
//

#ifndef DirectorCustom_h
#define DirectorCustom_h

#include "cocos2d.h"

class DirectorCustom : public cocos2d::Director {
public:
    
    static DirectorCustom* create();
    
    virtual void drawScene() override;
    
};

#endif
