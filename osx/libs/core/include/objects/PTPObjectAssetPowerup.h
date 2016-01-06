#ifndef PTPASSETPOWERUP_H
#define PTPASSETPOWERUP_H

#include "PTPObjectAsset.h"
#include "models/objects/PTModelObjectAssetPowerup.h"
#include "PTPAnimationObject.h"

class PTPObjectAssetPowerup : public PTPObjectAsset
{
public:
    explicit PTPObjectAssetPowerup( PTModelObjectAsset* model);
    virtual ~PTPObjectAssetPowerup();
    virtual void initPhysics(b2World* world);
    virtual void update(float dt);
    virtual void beginContact(PTPObjectAsset *obj,  b2Contact *contact,  bool testOneWayCollision = true );
    virtual void endContact(PTPObjectAsset *obj,  b2Contact *contact);

    virtual void setState( PTPObjectState s );

    CCString powerupType() const;

    virtual void wakeUp();

    CCString actionGroupId();
    bool isActivated();

    void deleteContactObject();

private:
    void activatePowerup();
    void deactivatePowerup();

    void endAnimationDidEnd();
    void startAnimationDidEnd();

    void contactObjectDeleted();

    PTModelObjectAssetPowerup* _model;
    PTPAnimationObject *_idleAnimation;
    PTPAnimationObject *_startAnimation;

    bool _rewardAnimation;
    float _rewardAnimationCounter;
    CCLabelBMFont* _rewardLabel;

    bool _characterConstraint;
    bool _screenConstarint;

    bool _scheduleForNextChepointSearch;
    bool _scheduleEndSceneStart;

    float _duration;

    int _startSoundId;
    int _endSoundId;

    bool _singleActionPowerup;

    bool _activated;

    PTPObjectAsset *_contactObject;

};

#endif // PTPASSETCOIN_H
