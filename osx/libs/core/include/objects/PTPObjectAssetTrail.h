#ifndef PTPOBJECTASSETTRAIL_H
#define PTPOBJECTASSETTRAIL_H

#include "PTPObjectAsset.h"
#include "models/objects/PTModelObjectAssetTrail.h"
#include "GLESDebugDraw.h"

#define kTrailVertices 40

class PTPObjectAssetTrail : public PTPObjectAsset QGLFUNCTIONS
{
public:
    PTPObjectAssetTrail( PTModelObjectAsset* model);
    virtual void update( float dt );
    virtual void draw();
    virtual CCRect contentRect();

    virtual void initPhysics(b2World* world);

private:
    CCGLProgram *_shaderProgram;
    PTModelObjectAssetTrail* _model;

    ccVertex2F _vtx[ kTrailVertices ];
    float _nse[ kTrailVertices ];

    int _vtxCounter;
    float _phase;
    float _initPhase;

    CCTexture2D *_texture;

    CCPoint worldPoint();
};

#endif // PTPOBJECTASSETTRAIL_H
