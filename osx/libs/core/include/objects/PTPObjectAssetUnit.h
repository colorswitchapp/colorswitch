#ifndef PTPObjectAssetUnit_H
#define PTPObjectAssetUnit_H

#include "PTPObjectAsset.h"
#include "models/objects/PTModelAssetObstacle.h"
#include "PTPAnimationObject.h"
#include "box2D/Box2D.h"

class PTPObjectAssetUnit : public PTPObjectAsset {
public:
    explicit PTPObjectAssetUnit( PTModelObjectAsset *model );
    virtual ~PTPObjectAssetUnit();

    void initPhysics( b2World *world );
    virtual CCRect contentRect();

    virtual void update(float dt);
    virtual void beginContact(PTPObjectAsset *obj, b2Contact *contact, bool testOneWayCollision = true );
    virtual void endContact(PTPObjectAsset *obj, b2Contact *contact);
    virtual void preSolve( PTPObjectAsset *obj, b2Contact* contact, const b2Manifold* oldManifold);
    virtual void setState( PTPObjectState s );

    virtual void wakeUp(); // perform wake up for object
    virtual float wakeUpDistance();
    virtual float sleepDistance();

    virtual float damage();
    virtual float health();
    virtual void setHealth( float health );
    virtual void setSpawner( bool spawner );

    void deathAnimationDidEnd();
    virtual void spawnObject();   
    virtual bool isCastShadow();

    virtual PTModelObjectAsset *model();

    virtual void updateContentRect();

    virtual bool isCollisionTestPassed();

    void schedulePositionXChange( float, CCString operation = "kAdd" );
    void schedulePositionYChange( float, CCString operation = "kAdd" );
    void scheduleRotationChange( float, CCString operation = "kAdd" );

private:
    PTModelObjectAssetUnit* _unitModel;

    int _wakeUpSoundId;
    int _deathSoundId;

    float _healthValue;

    PTPAnimationObject *_idleAnimation;
    PTPAnimationObject *_deathAnimation;

    CCRect _contentRect;

    bool _scheduledBodyChangeToDynamic;

    bool collisionTest(PTPObjectAsset *obj, CCPoint contactNormal);
    bool _collisionTestPassed;
    std::vector<int> _collisionPassedIds;

    float _scheduledPositionXChange;
    CCString _scheduledPositionXChangeOperation;
    float _scheduledPositionYChange;
    CCString _scheduledPositionYChangeOperation;
    float _schedulesRotationChange;
    CCString _scheduledRotationChangeOperation;
};

#endif // PTPObjectAssetUnit_H
