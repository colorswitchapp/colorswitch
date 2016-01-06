#ifndef PTPOBJECTLIGHT_H
#define PTPOBJECTLIGHT_H

#include "PTPObjectAsset.h"
#include "models/objects/PTModelObjectAssetLight.h"
#include "GLESDebugDraw.h"
#include "PTPConfig.h"

#define kLightMaxVertices 1024

#define kLigthMaxFixtures 80
#define kNumberOfThreads 6

class PTPObjectAssetLight;

struct PTPObjectAssetLightThreadData {
    PTPObjectAssetLight *object;
    int threadId;
};

class PTLightFixturesQueryCallback : public b2QueryCallback {
 public:
     std::vector<b2Fixture*> fixtures;

     bool ReportFixture(b2Fixture* fixture) {
        PTPObject* obj = (PTPObject*)fixture->GetUserData();
        if(obj && obj->isCastShadow()){
            if(fixtures.size() < kLigthMaxFixtures)
            fixtures.push_back( fixture );
        }
        return true;
     }
 };

class PTLightFixturesRaycastCallback : public b2RayCastCallback {
 public:
    PTLightFixturesRaycastCallback(){
        hit = false;
    }
    bool hit;
    b2Vec2 point;
     virtual float32 ReportFixture(	b2Fixture* fixture, const b2Vec2& _point,
                                     const b2Vec2& normal, float32 _fraction){

        PTPObject* obj = (PTPObject*)fixture->GetUserData();
        if(!obj){
            return -1;
        }

        if(! obj->isCastShadow() || fixture->IsSensor()){
            return -1;
        }

        hit = true;
        point = _point;
        return _fraction;
     }
 };


class PTPObjectAssetLight : public PTPObjectAsset QGLFUNCTIONS{

public:
    PTPObjectAssetLight( PTModelObjectAsset* model );
    virtual void initPhysics( b2World* world );
    virtual void update( float dt );
    virtual void draw();
    virtual void setState( PTPObjectState _state );
    void updateThreadSafe(int threadId);

    virtual CCRect contentRect();

private:
    void updateObjectVertices( std::vector<b2Fixture*> fixtures );
    std::vector<b2Fixture*> updateObjectFixtures();
    void appendVertex( ccVertex2F vtx );

    int tangentPointsAtCirlce(b2Vec2 center, float radius, b2Vec2 point, b2Vec2 *out);
    PTModelObjectAssetLight* _model;
    float _radius;
    GLint		_colorLocation;
    CCGLProgram *_shaderProgram;
    b2World* _world;
    ccVertex2F _vtx[ kLightMaxVertices ];
    ccVertex2F  _uv[ kLightMaxVertices ];

    b2Vec2 shapeVertices[ kLightMaxVertices ];
    b2Vec2 shapeNormals[ kLightMaxVertices ];
    int shapeVerticesCount;

    CCTexture2D *_texture;

    int vertexCounter;

    b2AABB _lightBoundingBox;

    b2Vec2 centerVertex;
    //DEBUG
//    GLESDebugDraw *_debugDraw;

};

#endif // PTPOBJECTLIGHT_H
