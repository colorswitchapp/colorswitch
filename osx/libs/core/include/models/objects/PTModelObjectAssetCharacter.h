#ifndef PTModelObjectAssetCharacter_H
#define PTModelObjectAssetCharacter_H

#include "models/objects/PTModelObjectAsset.h"
#include "models/PTModelAnimation.h"
#include "attributes/PTPAttributeEnum.h"

class PTModelSound;

class PTModelObjectAssetCharacter : public PTModelObjectAsset {
public:
    PTModelObjectAssetCharacter(CCString className = "PTModelObjectAssetCharacter");

    static PTModel* create() {
        return new PTModelObjectAssetCharacter();
    }

    virtual PTModelObjectAssetCharacter *duplicated();

    PTModelAnimation *idleAnimation() const ;
    PTModelAnimation *shootingAnimation() const ;
    PTModelAnimation *bulletAnimation() const ;
    PTModelAnimation *jumpAnimation() const;
    PTModelAnimation *deathAnimation() const;
    PTModelAnimation *moveAnimation() const;

    bool isCastShadow();

    bool isAutoTilt();

    float deathCameraShake() const;
    float deathCameraFlash() const;
    float gameOverDelay() const;
    float deathFall() const;

    PTModelSound* shootSound() const ;
    PTModelSound* deathSound() const ;
    PTModelSound* jumpSound() const ;

    PTModelSound* groundCollisionSound() const ;

private:

};

#endif // PTModelObjectAssetCharacter_H
