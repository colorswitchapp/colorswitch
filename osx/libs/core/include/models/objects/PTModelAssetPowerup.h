#ifndef PTMODELASSETPOWERUP_H
#define PTMODELASSETPOWERUP_H

#include "models/objects/PTModelAsset.h"
#include "attributes/PTPAttributeSprite.h"
#include "attributes/PTPAttributeAnimation.h"
#include "attributes/PTPAttributeEnum.h"
#include "attributes/PTPAttributeSound.h"

class PTModelAssetPowerup : public PTModelAsset {
public:
    PTModelAssetPowerup(CCString name = "Powerup");
    ~PTModelAssetPowerup();

    virtual PTModelSpriteContainer *sprite();
    virtual void attributeDidUpdated(PTPAttribute *attr);

    virtual void initWithDictionary(CCDictionary *dict);

    void setIdleSpriteAnimation(PTModelSpriteContainer *sprite);
    PTModelAnimation* idelAnimation();
    PTModelAnimation* startAnimation();
    PTModelAnimation* endAnimation();

    CCString constraintType();

    int reward() const ;
    bool showReward() const;
    int appearanceChance() const ;
    float cameraShake() const;
    float cameraFlash() const;
    float duration() const;

    void setPowerupType(CCString);
    CCString powerupType();
    CCString animationRepeat();
    CCString animationBehaviour();

    PTModelSound* idleSoundAttribute() const;
    PTModelSound* startSoundAttribute() const;
    PTModelSound* endSoundAttribute() const;

    CCPoint gravity();

    static PTModel * create() {
        return new PTModelAssetPowerup();
    }

    void saveSettings();
    void restoreSettings();
    void applySettings();
    void setDefaultGameplaySettings();

private:

    void updateGameplayVisibility();

private:

    PTPAttributeFloat* _rewardAttribute;
    PTPAttributeBoolean *_showRewardAttribute;
    PTPAttributeFloat* _appearanceChanceAttribute;
    PTPAttributeEnum* _powerupType;
    PTPAttributeFloat* _cameraShake;
    PTPAttributeFloat* _cameraFlash;
    PTPAttributeFloat* _durationAttribute;
    PTPAttributeEnum* _constraintTypeAttribute;
    PTPAttributeEnum* _animationBehaviorAttribute;
    PTPAttributeEnum* _animationRepeatAttribute;
    PTPAttributeAnimation* _idleAnimationAttribute;
    PTPAttributeAnimation* _startAnimationAttribute;
    PTPAttributeAnimation* _endAnimationAttribute;

    PTPAttributeSound *_idleSoundAttribute;
    PTPAttributeSound *_startSoundAttribute;
    PTPAttributeSound *_endSoundAttribute;

    // Gameplay attributes
    PTPAttributeGroup* _gameplayGroup;
    PTPAttributePoint *_moveSpeed;
    PTPAttributePoint *_gravity;
    PTPAttributePoint *_upForce;
    PTPAttributeFloat *_upForceCounter;
    PTPAttributeFloat *_upForceDuration;
    PTPAttributeBoolean *_upForceFromGround;
    PTPAttributeFloat *_rightLeanForce;
    PTPAttributeFloat *_leftLeanForce;
    PTPAttributeFloat *_gameSpeedMin;
    PTPAttributeFloat *_gameSpeedMax;
    PTPAttributeFloat *_gameSpeedIncrease;
    PTPAttributeFloat *_friction;
    PTPAttributeFloat *_simulationTimeScale;
    PTPAttributeFloat *_velocityScale;
    PTPAttributeFloat *_rotationScale;
    PTPAttributePoint *_bounceForce;
    PTPAttributeFloat *_restitution;
    PTPAttributeFloat *_scoreMultiplier;
    PTPAttributePoint *_characterFriction;
    PTPAttributeFloat *_platformFriction;
    PTPAttributeFloat *_gameplayAngleDirection;

    CCDictionary *_saveContainer;

    friend class PTLevelEditorScreen;
};

#endif // PTMODELASSETPOWERUP_H
