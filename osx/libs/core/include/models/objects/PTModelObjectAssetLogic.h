#ifndef PTMODELOBJECTASSETLOGIC_H
#define PTMODELOBJECTASSETLOGIC_H

#include "PTModelObjectAsset.h"
#include "attributes/PTPAttributeShape.h"
#include "models/PTModelPolygon.h"

class PTModelObjectAssetLogic : public PTModelObjectAsset
{
public:
    PTModelObjectAssetLogic(CCString className = "PTModelObjectAssetLogic");

    virtual PTModelPolygon *collisionShape();
    virtual PTPShapeType collisionShapeType();

    virtual PTModelObjectAssetLogic* duplicated();

    virtual CCSize contentSize();

    static PTModel* create() {
        return new PTModelObjectAssetLogic();
    }

    CCPoint positionChange();
    float rotationChange();
    CCPoint scaleChange();
    CCPoint linearVelocityChange();
    float angularVelocityChange();

    PTPAttributePoint* positionChangeAttribute();
    PTPAttributeFloat* rotationChangeAttribute();
    PTPAttributePoint* scaleChangeAttribute();
    PTPAttributePoint* linearVelocityChangeAttribute();
    PTPAttributeFloat* angularVelocityChangeAttribute();

    CCString affectedAsset();
    PTPAttributeEnum* affectedAssetAttribute();

    CCString affectOperation();

private:
    PTPAttributePoint *_positionChange;
    PTPAttributeFloat *_rotationChange;
    PTPAttributePoint *_scaleChange;

    PTPAttributePoint *_linearVelocityChange;
    PTPAttributeFloat *_angularVelocityChange;

    PTPAttributeEnum *_affectedAsset;
    PTPAttributeEnum *_affectOperation;

    PTModelPolygon *_collisionShape;
};

#endif // PTMODELOBJECTASSETLOGIC_H
