#ifndef PTPSCREENGAMEFIELD_H
#define PTPSCREENGAMEFIELD_H


#include "models/objects/PTModelAssetPowerup.h"
#include "screens/PTPScreenScene.h"
#include "objects/PTPObjectAssetPowerup.h"

class GLESDebugDrawLayer;
class PTPInputController;

class PTPScreenGameField : public PTPScreenScene {

public:
    static PTPScreenGameField *shared();
    PTPScreenGameField();
    ~PTPScreenGameField();

    virtual bool init();
    static cocos2d::CCScene *scene();
    virtual void update(float dt);
    virtual void updateCameraObjects(float dt);

    CREATE_FUNC( PTPScreenGameField )

    virtual void onEnter();
    virtual void onKeyDown( int keyCode );
    virtual void onKeyUp( int keyCode );
    virtual void keyBackClicked();

    bool isGameOverMode( );
    void setGameSpeedSlowDown( float factor );

    void setGameOverMode( bool gameOverMode );
    void setPauseMode( bool pauseMode );
    bool isPauseMode();
    void pauseButtonAction( CCObject *sender );
    void restartButtonAction( CCObject *sender );

    void resetGameplay();
    void setDebugMode(bool enable);

    PTPInputController* inputController();

    virtual void activatePowerup( PTModelAssetPowerup* powerup, bool aboveCharacter = true);
    PTPObjectAssetPowerup* activePowerup( CCString type,  PTPObject *sender);

    std::list<PTPObjectAssetPowerup*> powerupList(CCString type);

    void setPowerupMagnetMode( bool enabled );
    void setPowerupKillAllEnemy();
    void setPowerupCheckPoint( CCPoint point, int levelSectionId );
    void setPowerupNextCheckPoint();

    void scheduleGameRestart();

    void cloneObject(PTPObjectAsset* objectToClone,  PTPObjectAsset* cloneSpace );

    virtual void setTouchEnabled( bool enabled );

    virtual void reset();
    void resetPowerups();
    virtual void removeAds();
    virtual void coinShopAction(CCObject* sender);

    virtual void deleteObject(PTModelObject* model);

    b2World* world();

    virtual void onBackFromChildScreen();

    void endGameAction();

    void submitScoreAndUpdateBestScores();

private:
    void killAllEnemyOnObject( CCNode * );
    PTModelLevelSection *getLevelSectionByDistance( float d );

    std::list<b2RevoluteJoint *> _jointMotorsList; //TODO: need to complitly move to inputController

    PTPInputController* _inputController;

    CCArray *_levelSectionModels;
    float _levelSectionCurentLength;

    bool _pauseMode;
    bool _gameOverMode;

    CCScene *_debugScene;

    float _levelSectionLength;

    //powerups
    bool _powerupMagnetMode;
    bool _scheduleGameRestart;

    float _gameSpeedslowDownFactor;
    float _gameOverDelay;
};

#endif // PTPSCREENGAMEFIELD_H
