#ifndef PTPSCREENPAUSE_H
#define PTPSCREENPAUSE_H

#include "PTPScreen.h"

class PTPScreenPause : public PTPScreen
{

public:
    virtual bool init();
    static cocos2d::CCScene* scene();

    CREATE_FUNC( PTPScreenPause );

    void restartButtonAction(CCObject* pSender);
    void restartCheckpointButtonAction(CCObject *pSender);
    void continueButtonAction(CCObject* pSender);
    void backButtonAction(CCObject* pSender);

    virtual void keyBackClicked();

    void soundOffAction(CCObject *pSender);
    void soundOnAction(CCObject* pSender);

    virtual void gameServicesButtonAction(CCObject* pSender);

private:
    PTPObjectButton* _soundOnButton;
    PTPObjectButton* _soundOffButton;
};

#endif // PTPSCREENPAUSE_H
