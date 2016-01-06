//
//  GLESDEbugDrawLayer.h
//  ProjectMayhem
//
//  Created by Nik Rudenko on 12/10/12.
//
//

#ifndef __ProjectMayhem__GLESDEbugDrawLayer__
#define __ProjectMayhem__GLESDEbugDrawLayer__

#include <iostream>
#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "GLESDebugDraw.h"

class GLESDebugDrawLayer : public cocos2d::CCLayer
{
    
public:
    GLESDebugDrawLayer();
    b2World *world;
    virtual void draw( void );
    
	static cocos2d::CCScene* scene();

    CREATE_FUNC( GLESDebugDrawLayer );

private:
    GLESDebugDraw* _debugDraw;
};


#endif /* defined(__ProjectMayhem__GLESDEbugDrawLayer__) */
