#ifndef PTPScreenEndScene_H
#define PTPScreenEndScene_H

#include "PTPScreenScene.h"

class PTModelAssetPowerup;

class PTPScreenEndScene : public PTPScreenScene
{
public:
    static PTPScreenEndScene *shared();
    PTPScreenEndScene();
    ~PTPScreenEndScene();

    virtual bool init();
    static cocos2d::CCScene* scene();

    CREATE_FUNC( PTPScreenEndScene );

    virtual void update(float dt);
    void startButtonAction(CCObject* pSender);
    void startCheckpointButton(CCObject* pSender);
    virtual void shareButtonAction(CCObject* pSender);
    void reviewButtonAction(CCObject* pSender);
    void backButtonAction(CCObject* pSender);

    virtual void keyBackClicked();

    virtual void activatePowerup( PTModelAssetPowerup* powerup, bool aboveCharacter = true);

private:
    PTPObjectButton* _soundOnButton;
    PTPObjectButton* _soundOffButton;
    
    bool _schedulePlayBackgroundMusic;
};

#endif // PTPScreenEndScene_H
