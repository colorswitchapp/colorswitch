#ifndef PTPOBJECTASSETLOGIC_H
#define PTPOBJECTASSETLOGIC_H

#include "PTPObjectAsset.h"

class PTModelObjectAsset;
class PTModelObjectAssetLogic;

class PTPObjectAssetLogic : public PTPObjectAsset QGLFUNCTIONS{

public:
    PTPObjectAssetLogic( PTModelObjectAsset* model );

    virtual void initPhysics( b2World* world );

    virtual void beginContact(PTPObjectAsset *obj, b2Contact *contact, bool testOneWayCollision = true );

    virtual bool isCastShadow();

private:
    PTModelObjectAssetLogic* _model;
};

#endif // PTPOBJECTASSETLOGIC_H
