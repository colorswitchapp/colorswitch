#ifndef PTMODELOBJECTASSETFLAG_H
#define PTMODELOBJECTASSETFLAG_H

#include "attributes/PTPAttributeColor.h"
#include "models/objects/PTModelObjectAsset.h"
#include "models/PTModelPolygon.h"

class PTModelObjectAssetFlag : public PTModelObjectAsset{

public:
    PTModelObjectAssetFlag(CCString className = "PTModelObjectAssetFlag");

    virtual PTModelObjectAssetFlag* duplicated();
    virtual PTModelPolygon *collisionShape();
    virtual PTPShapeType collisionShapeType();
    virtual CCSize contentSize();

    float startWidth();
    float endWidth();

    float speed();
    float length();
    float waveHeight();
    float waveLength();

    PTModelSpriteContainer* texture();

    static PTModel* create() {
        return new PTModelObjectAssetFlag();
    }

private:
    PTModelPolygon *_collisionShape;
    PTPAttributeSprite *_textureAttribute;

    PTPAttributeFloat *_speedAttribute;
    PTPAttributeFloat *_waveLengthAttribute;
    PTPAttributeFloat *_waveHeightAttribute;
    PTPAttributeFloat *_lengthAttribute;
    PTPAttributeFloat *_startWidthAttribute;
    PTPAttributeFloat *_endWidthAttribute;


};

#endif // PTMODELOBJECTASSETFLAG_H
