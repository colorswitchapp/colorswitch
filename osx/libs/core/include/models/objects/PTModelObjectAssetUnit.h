#ifndef PTModelObjectAssetUnit_H
#define PTModelObjectAssetUnit_H

#include "PTModelObjectAsset.h"
#include "PTModelAsset.h"
#include "models/PTModelAnimation.h"
#include "attributes/PTPAttributeShape.h"
#include "attributes/PTPAttributeAsset.h"
#include "attributes/PTPAttributeEnum.h"

class PTModelSound;

class PTModelObjectAssetUnit : public PTModelObjectAsset {
public:
    PTModelObjectAssetUnit(CCString className = "PTModelObjectAssetUnit");

    virtual PTModelObjectAssetUnit *duplicated();

    virtual void initWithDictionary( cocos2d::CCDictionary *dict );
    virtual cocos2d::CCDictionary *getDictionary();

    CCString wakeUpType() const;
    CCString movementType() const;

    CCString  sleepType() const;
    float sleepDistance() const;

    CCPoint linearVelocity() const;
    void setLinearVelocity( CCPoint value );
    CCPoint linearVelocityVariable() const;

    float angularVelocity() const;
    float angularVelocityVariable() const;

    float wakeUpDistance() const;

    PTModelAnimation *idleAnimation();
    PTModelAnimation *deathAnimation();
    float health() const;
    float damage();

    void setSpawnAction(CCString spawnAction);
    CCString spawnAction();

    void setSpawner( bool isSpawner );
    virtual bool isSpawner();

    void setSpawnRate(float spawnRate);
    virtual float spawnRate();

    virtual void attributeDidUpdated(PTPAttribute *attr);

    static PTModel * create() {
        return new PTModelObjectAssetUnit();
    }

    CCString collisionType();
    void setCollisionType( const char* value);

    CCString destroyType();
    void setDestroyType( const char* value);

    PTModelSound* idleSound() const ;
    PTModelSound* deathSound() const ;
    PTModelSound* wakeUpSound() const ;

    void setObjectType(CCString);
    CCString objectType();

private:    
    PTPAttributeEnum *_collisionType;
    PTPAttributeEnum *_destroyType;
    PTPAttributeEnum *_objectTypeAttribute;

    PTPAttributeBoolean *_isSpawner;
    PTPAttributeFloat *_spawnRate;
    PTPAttributeEnum *_spawnAction;

    PTPAttributePoint *_linearVelocity;
    PTPAttributeFloat *_angularVelocity;
    PTPAttributeFloat *_wakeUpDistance;
    PTPAttributeEnum  *_wakeUpType;

    PTPAttributeEnum  *_sleepType;
    PTPAttributeFloat *_sleepDistance;
    PTPAttributeEnum  *_movementType;

    friend class PTLevelEditorPresetController;
};

#endif // PTModelObjectAssetUnit_H
