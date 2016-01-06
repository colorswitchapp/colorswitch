#ifndef PTPOBJECTASSET_H
#define PTPOBJECTASSET_H

#include "PTPObject.h"
#include "attributes/PTPAttributeAction.h"
#include "models/objects/PTModelAsset.h"
#include "box2D/Box2D.h"
#include "models/objects/PTModelObjectAssetUnit.h"
#include "models/PTModelGeneralSettings.h"

enum PTPObjectAssetType {
    PTPObjectAssetDefault = 0,
    PTPObjectAssetPlatform ,
    PTPObjectAssetEnemy,
    PTPObjectAssetDecoration
};

enum PTPObjectAssetCollisionType{
    PTPObjectAssetCollisionNo = 0,
    PTPObjectAssetCollisionYes
};

enum PTPObjectAssetDestroyType{
    PTPObjectAssetDestroyNo = 0,
    PTPObjectAssetDestroyCharacter,
    PTPObjectAssetDestroyEnemy,
    PTPObjectAssetDestroyAll,
};


enum PTPObjectAssetWakeupType{
    PTPObjectAssetWakeupNo = 0,
    PTPObjectAssetWakeupDistance,
    PTPObjectAssetWakeupCollide
};

enum PTPObjectAssetSleepType{
    PTPObjectAssetSleepNo = 0,
    PTPObjectAssetSleepDistance,

};

class PTPObjectGeneralSettings;

class PTPObjectAsset : public PTPObject
{
public:
    PTPObjectAsset(PTModelObjectAsset* model);
    virtual ~PTPObjectAsset();

    static PTPObjectAsset* create(PTModelObject* model);

    virtual void initPhysics(b2World* world);
    virtual void update(float dt);

    virtual void beginContact( PTPObjectAsset *obj,  b2Contact *contact,  bool testOneWayCollision = true );
    virtual void endContact( PTPObjectAsset *obj,  b2Contact *contact );
    virtual void preSolve( PTPObjectAsset *obj, b2Contact* contact, const b2Manifold* oldManifold);
    bool isMovementTypeLinear();

    virtual void setState( PTPObjectState s );

    bool isLinked();
    void setLinked( bool linked);
    bool isSpawnEnabled();
    void setSpawnEnabled( bool spawnEnabled );
    CCPoint linearMoveSpeed();
    void setLinearMoveSpeed( CCPoint moveSpeed );
    float linearRotationSpeed();
    void setLinearRotationSpeed( float rotateSpeed );
    virtual void spawnObject();
    virtual float wakeUpDistance();

    float distance(); //distance betwwen character and object (can be negative of object behind character related to game direction)
    float distanceToCamera(); //distance between camera and object (can be negative of object behind camera related to game direction)

    virtual float sleepDistance();

    PTPObjectAssetCollisionType collisionType();
    PTPObjectAssetDestroyType destroyType();

    void setParentLevelSectionId( unsigned int id);
    unsigned int parentLevelSectionId();

    virtual void updateContentRect();

    virtual PTModelObject *model();
    virtual bool isCollisionTestPassed();

    void scheduleDeath();

    PTPObjectAssetType assetType();

    void subscribeOnEvent(PTPObjectAssetEventType event, CCObject *target, PTPActionPointer selector);
    void unsubscribeOnEvent(CCObject *target);

    void deleteAsset(PTModelObject*assetModel);

protected:
    void updateIdleSound(float dt);
    int _idleSoundId;

protected:

    PTPObjectGeneralSettings* _generalSettingsObject;
    PTModelGeneralSettings* _generalSettingsModel;
    PTPObjectAssetCollisionType _collisionType;
    PTPObjectAssetDestroyType  _destroyType;
    PTPObjectAssetWakeupType _wakeupType;
    PTPObjectAssetSleepType _sleepType;

    float _linearRotationSpeed;
    CCPoint _linearMoveSpeed;
    bool _movementTypeLinear;

    bool _sleep;
    float _travelDistance;
    bool _linked;
    bool _spawnEnabled;
    float _spawnCounter;
    bool _resetCounterOnStartSpawning;

    unsigned int _parentLevelSectionId;

    void performDestroyCollision(PTPObjectAsset *objA, PTPObjectAsset *objB);

    PTPObjectAssetType _assetType;

    PTModelObjectAsset* _model;
    bool _scheduledDeath;

private:
    PTModelSound* _idleSoundModel;
    std::list<PTActionSubscriberStruct> _subscribers;

    friend class PTPScreenGameField;
};

#endif // PTPOBJECTASSET_H
