#ifndef PTMODELASSETOBSTACLE_H
#define PTMODELASSETOBSTACLE_H

#define kObstacleNoWakeup 0
#define kObstacleTimeBasedWakeup 1
#define kObstacleCollisionBasedWakeup 2

#define kObstacleStaticMovememnt 0
#define kObstacleLinearMovement 1 // 1 = kMovementLinear
#define kObstaclePhysicsMovement 2 //

#define kObstacleCollisionNo 0

#include "PTModelAsset.h"
#include "attributes/PTPAttributeShape.h"

class PTPAttributeAnimation;
class PTPAttributeFloat;
class PTPAttributeSound;
class PTModelAnimation;
class PTModelPolygon;
class PTModelSound;

class PTModelAssetObstacle : public PTModelAsset {
public:
    PTModelAssetObstacle(CCString name = "Obstacle");

    float health() const;
    float damage() const;
    void setDamage( float damage );
    void setIdleAnimation(PTModelAnimation* animation);

    PTModelAnimation* idleAnimation() const;
    PTModelAnimation* deathAnimation() const;

    virtual PTModelSpriteContainer *sprite();

    static PTModel * create() {
        return new PTModelAssetObstacle();
    }

    PTModelSound* idleSoundAttribute() const;
    PTModelSound* deathSoundAttribute() const;
    PTModelSound* wakeUpSoundAttribute() const;

private:
    void setIdleSpriteAnimation(PTModelSpriteContainer *spriteContainer);

    PTPAttributeAnimation *_idleAnimationAttribute;
    PTPAttributeAnimation *_deathAnimationAttribute;
    PTPAttributeFloat *_healthAttribute;
    PTPAttributeFloat *_damageAttribute;
    PTPAttributeSound *_idleSoundAttribute;
    PTPAttributeSound *_deathSoundAttribute;
    PTPAttributeSound *_wakeUpSoundAttribute;

    friend class PTLevelEditorScreen;
    friend class PTAnimationEditorWidget;
};

#endif // PTMODELASSETOBSTACLE_H
