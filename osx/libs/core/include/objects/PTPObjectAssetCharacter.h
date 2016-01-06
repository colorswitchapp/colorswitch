#ifndef PTPObjectAssetCharacter_H
#define PTPObjectAssetCharacter_H

#include "box2D/Box2D.h"

#include "models/objects/PTModelAssetCharacter.h"
#include "models/objects/PTModelObject.h"
#include "objects/PTPObjectAsset.h"
#include "PTPAnimationObject.h"
#include "models/objects/PTModelObjectAssetCharacter.h"
#include <map>
#include "GLESDebugDraw.h"

enum PTPObjectAssetCharacterState{
    PTPObjectAssetCharacterStateIdle,
    PTPObjectAssetCharacterStateMoving,
    PTPObjectAssetCharacterStateJumpPressed,
    PTPObjectAssetCharacterStateJumpReleased,
    PTPObjectAssetCharacterStateShooting
};

enum PTPObjectAssetCharacterFlags {
    PTPObjectAssetCharacterFlagJump = 0x01,
    PTPObjectAssetCharacterFlagMoving = 0x02,
    PTPObjectAssetCharacterFlagRotateLeft  = 0x04,
    PTPObjectAssetCharacterFlagRotateRight = 0x08,
    PTPObjectAssetCharacterFlagGrounded    = 0x10,
    PTPObjectAssetCharacterFlagShooting = 0x20,
    PTPObjectAssetCharacterFlagBouncing = 0x40

};

class PTPObjectAssetCharacterRaycastCallback : public b2RayCastCallback {
 public:
    PTPObjectAssetCharacterRaycastCallback(){
        obj = NULL;
    }
    PTPObjectAsset *obj;
    PTPObjectAsset *ignore;

     virtual float32 ReportFixture(	b2Fixture* fixture, const b2Vec2& _point,
                                     const b2Vec2& normal, float32 _fraction){

        if(fixture->IsSensor()){
            return -1;
        }

        PTPObjectAsset *assetObject = (PTPObjectAsset*)fixture->GetUserData();
        if(!assetObject || ignore == assetObject ||
                assetObject->destroyType() == PTPObjectAssetDestroyCharacter ||
                assetObject->destroyType() == PTPObjectAssetDestroyAll){
            assetObject = NULL;
            return -1;
        }

        if( assetObject ){
            obj = assetObject;
        }

        return _fraction;
     }
 };


class PTPObjectAssetCharacter : public PTPObjectAsset{

public:
    PTPObjectAssetCharacter( PTModelObjectAsset* model );
    virtual ~PTPObjectAssetCharacter();

    void initPhysics( b2World* world );
    void setShooting( bool enabled );
    void setPhysicsPosition( CCPoint position );
    void setTargetPosition( CCPoint target );
    CCPoint targetPosition();
    void move(float dx, float dy);

    virtual void setState( PTPObjectState s );

    virtual void update(float dt);
    virtual void draw();
    virtual void beginContact( PTPObjectAsset *obj,  b2Contact *contact, bool testOneWayCollision = true );
    virtual void preSolve(PTPObjectAsset *obj, b2Contact* contact, const b2Manifold* oldManifold);

    void setGrounded( bool grounded );

    void actionJumpPressed();
    void actionJumpReleased();

    void actionRotateLeftPressed();
    void actionRotateLeftReleased();
    void actionRotateRightPressed();
    void actionRotateRightReleased();

    virtual float damage();

    float speed();

    void setModel(PTModelObjectAssetCharacter* model);

    CCPoint moveVector();
    void setMoveVector( CCPoint vector );
    void setMoveVectorX(float x);
    void setMoveVectorY(float y);
    void applyForce( float x, float y);

    bool isInvincibilityMode();
    void setInvincibilityMode( bool enabled );

    virtual bool isCastShadow();
    virtual b2AABB physicsBoundingBox();

    virtual const CCPoint& getPosition();
    virtual bool isVisible();

    float characterRotationSpeedMultiplier;

protected:
    void deathAnimationDidEnd();
    void jumpAnimationDidEnd();

private:
    void updateGroundedState();
    void setActiveState();

    PTPAnimationObject* _idleAnimation;
    PTPAnimationObject* _shootingAnimation;
    PTPAnimationObject* _jumpAnimation;
    PTPAnimationObject* _deathAnimation;
    PTPAnimationObject* _moveAnimation;

    PTModelObjectAssetCharacter* _model;

    int _jumpSoundId;
    int _deathSoundId;
    int _shootSoundId;

    bool pShooting;
    CCPoint pTargetPosition;

    b2MouseJoint* pMouseJoint;
    b2Body* pGroundBody;

    CCPoint _moveVector;
    b2Vec2 _forceVector;
    b2Vec2 _gravityVector;

    uint32 pFlags;

    float pSpeed;
    float _upForceDuration;
    int _upForceCounter;

    float _gameOverDelay;
    float _autoTiltFactor;
    bool _scheduleDeathFall;

    bool _invincibilityMode;

    b2WorldManifold* _worldManifold;

//    GLESDebugDraw* _debugDraw;
};

#endif // PTPObjectAssetCharacter_H
