//
//  DirectorCustom.cpp
//  Engine
//
//  Created by harry on 2019/9/28.
//

#include "DirectorCustom.h"

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

void DirectorCustom::drawScene() {
    
}
