#ifndef PTPOBJECTASSETFLAG_H
#define PTPOBJECTASSETFLAG_H

#include "PTPObjectAsset.h"
#include "models/objects/PTModelObjectAssetFlag.h"

#define kFlagVertices 20

class PTPObjectAssetFlag : public PTPObjectAsset QGLFUNCTIONS
{
public:
    PTModelObjectAssetFlag* _model;
    PTPObjectAssetFlag(PTModelObjectAsset* model);

    virtual CCRect contentRect();

    virtual void update( float dt );
    virtual void draw();

private:
    CCTexture2D *_texture;
    CCGLProgram *_shaderProgram;

    float _phase;
};

#endif // PTPOBJECTASSETFLAG_H
