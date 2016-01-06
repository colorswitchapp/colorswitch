#ifndef PTPSCREENINFO_H
#define PTPSCREENINFO_H

#include "screens/PTPScreen.h"

class PTPScreenInfo : public PTPScreen{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();

    CREATE_FUNC( PTPScreenInfo );

    void backButtonAction(CCObject* pSender);
    void resetButtonAction(CCObject* pSender);
    void resetWarningMessageClicked( bool yes );

    virtual void keyBackClicked();

    virtual void showAds();

    void fullscreenAction(CCObject *pSender);
    void windowedAction(CCObject* pSender);

private:
    PTPObjectButton* _windowedButton;
    PTPObjectButton* _fullscreenButton;
};

#endif // PTPSCREENINFO_H
