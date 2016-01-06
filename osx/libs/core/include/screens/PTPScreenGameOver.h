#ifndef PTPSCREENGAMEOVER_H
#define PTPSCREENGAMEOVER_H

#include "PTPScreen.h"

class PTPScreenGameOver : public PTPScreen
{
public:
    PTPScreenGameOver();
    virtual bool init();
    static cocos2d::CCScene* scene();

    virtual void update( float dt );

    CREATE_FUNC( PTPScreenGameOver );

    void restartButtonAction(CCObject* pSender);
    void restartCheckpointButtonAction(CCObject* pSender);
    void backButtonAction(CCObject* pSender);

    virtual void keyBackClicked();

    void reviewButtonAction(CCObject* pSender);
    void shareButtonAction(CCObject* pSender);

    virtual void gameServicesButtonAction(CCObject* pSender);

private:
    bool _takingScreenshotMode;
    int _shareWidgetCounter;
};

#endif // PTPSCREENGAMEOVER_H
