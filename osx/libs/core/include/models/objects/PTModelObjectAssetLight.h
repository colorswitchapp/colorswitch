#ifndef PTMODELOBJECTLIGHT_H
#define PTMODELOBJECTLIGHT_H

#include "PTModelObjectAsset.h"
#include "attributes/PTPAttributeColor.h"
#include "models/PTModelPolygon.h"

class PTModelObjectAssetLight : public PTModelObjectAsset
{
public:
    PTModelObjectAssetLight(CCString className = "PTModelObjectAssetLight");

    virtual PTModelPolygon *collisionShape();
    virtual PTPShapeType collisionShapeType();

    virtual PTModelObjectAssetLight* duplicated();

    virtual CCSize contentSize();

    float radius();
    ccColor4F color();
    bool isCastShadow();

    static PTModel* create() {
        return new PTModelObjectAssetLight();
    }

private:
    PTModelPolygon *_collisionShape;
    PTPAttributeFloat *_radiusAttribute;
    PTPAttributeColor *_colorAttribute;
    PTPAttributeBoolean *_castShadowAttribute;

};

#endif // PTMODELOBJECTLIGHT_H
