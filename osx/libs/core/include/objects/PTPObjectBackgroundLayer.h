#ifndef PTPOBJECTBACKGROUNDLAYER_H
#define PTPOBJECTBACKGROUNDLAYER_H

#include "cocos2d.h"
#include "models/objects/PTModelObjectBackground.h"
#include "PTPObject.h"
#include "CCParallaxScrollNode.h"


class PTPObjectBackgroundLayer : public PTPObject
{

public:
    PTPObjectBackgroundLayer( PTModelObjectBackground *model );

    static PTPObjectBackgroundLayer* create( PTModelObjectBackground* model );

    virtual void update( float dt );
    void scroll( float delta, float dt );

    void reset();

private:
    PTModelObjectBackground* pModel;
    CCParallaxScrollNode* pParalaxNode;

    CCPoint _originalPosition;

    float boudningRectWidth( int side ) const; // -1 left; +1 right
};

#endif // PTPOBJECTBACKGROUNDLAYER_H
