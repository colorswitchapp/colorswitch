#ifndef PTMODELOBJECTASSETTRAIL_H
#define PTMODELOBJECTASSETTRAIL_H

#include "PTModelObjectAsset.h"
#include "attributes/PTPAttributeColor.h"
#include "models/PTModelPolygon.h"


class PTModelObjectAssetTrail : public PTModelObjectAsset
{
public:
    PTModelObjectAssetTrail(CCString className = "PTModelObjectAssetTrail");

    virtual PTModelPolygon *collisionShape();
    virtual PTPShapeType collisionShapeType();

    virtual PTModelObjectAssetTrail* duplicated();

    virtual CCSize contentSize();

    float startWidth();
    float endWidth();

    float speed();
    float length();
    float waveHeight();
    float waveLength();

    PTModelSpriteContainer* texture();

    static PTModel* create() {
        return new PTModelObjectAssetTrail();
    }

private:
    PTPAttributeFloat *_speedAttribute;
    PTPAttributeFloat *_waveLengthAttribute;
    PTPAttributeFloat *_waveHeightAttribute;
    PTPAttributeFloat *_lengthAttribute;
    PTPAttributeFloat *_startWidthAttribute;
    PTPAttributeFloat *_endWidthAttribute;

    PTModelPolygon *_collisionShape;

    PTPAttributeSprite *_textureAttribute;
};

#endif // PTMODELOBJECTASSETTRAIL_H
