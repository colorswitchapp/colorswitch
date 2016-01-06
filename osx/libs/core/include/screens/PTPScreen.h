#ifndef PTPSCREEN_H
#define PTPSCREEN_H

#include "cocos2d.h"
#include "PTPGameFieldCamera.h"
#include "models/PTModelScreen.h"
#include "models/objects/PTModelObjectLabel.h"
#include "objects/PTPObjectButton.h"

#include "ads/PTAdObject.h"

#define kRootLayerItemTag 0
#define kRootCCMenuItemTag 100

class PTPScreenScene;
class PTModelAssetPowerup;

class PTPScreen : public CCLayer
{
public:
	PTPScreen();
    ~PTPScreen();
    virtual bool init();
    static cocos2d::CCScene* scene();
    static PTPScreen *getRunningScreen();

    CREATE_FUNC( PTPScreen );

    bool load(const char* key);
    PTPObjectButton* getButton( const char* key );
    PTModelObjectLabel* getLabel( const char* key);

    void update(float dt);

    virtual void onKeyUp( int keyCode );

    void stopBackgroundMusic();
    void playBackgroundMusic();

    virtual void reset();
    virtual void removeAds();

    virtual void deleteObject(PTModelObject *model);
    void hideAds();
    virtual void showAds();

    bool isBannerWillShow();
    bool isBannerWillShow(const char* screenModelName);
    bool isInterstitialWillShow();
    bool isInterstitialWillShow(const char* screenModelName);

    virtual PTPScreenScene *parentScreenScene();
    virtual void onBackToParentScreen();
    virtual void defaultBackActionHandler();

    virtual void onEnter();

    void setUiLayerVisible( bool );
    void setChildrenButtonsEnabled( bool );

    void ignoreNextInterstitial();

    virtual void activatePowerup( PTModelAssetPowerup* powerup, bool aboveCharacter = true);

    void addChildScreen(PTPScreen *);
    PTPScreen *getChildScreen();
    static PTPScreen *getTopScreen();

    PTModelScreen* model();
protected:
    PTModelScreen* _model;

    void assignActionToButtons(const char* buttonId, CCObject* target, SEL_MenuHandler selector);
    void assignActionsToButtons(const char* buttonId, CCObject* target, SEL_MenuHandler selectedSelector, SEL_MenuHandler unselectedSelector);

    void soundOffAction(CCObject *pSender);
    void soundOnAction(CCObject* pSender);

    void powerupButtonAction(CCObject* sender);
    void purchaseButtonAction(CCObject* sender);
    virtual void coinShopAction(CCObject* sender);
    void restorePurchasesButtonAction(CCObject* pSender);
    virtual void gameServicesButtonAction(CCObject* pSender);

    std::map<PTModelObject*, CCNode*> _objectMap;

    CCNode *_uiNode;
    float _uiNodeUnhideTimeOut;
    float _uiNodeScheduleForUnhide;

    void switchToScene( CCScene* );

    bool _ignoreNextInterstitialShow;

private:
    CCLabelBMFont *_distanceSessionLabel;
    CCLabelBMFont *_distanceBestLabel;

    CCLabelBMFont *_coinsSessionLabel;
    CCLabelBMFont *_coinsTotalLabel;

    PTPObjectButton* _soundOnButton;
    PTPObjectButton* _soundOffButton;

};

#endif // PTPSCREEN_H
