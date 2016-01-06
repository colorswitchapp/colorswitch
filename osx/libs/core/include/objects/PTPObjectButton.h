#ifndef PTPOBJECTBUTTON_H
#define PTPOBJECTBUTTON_H

#include "cocos2d.h"
#include "models/PTModelScreen.h"

class PTPScreen;

using namespace cocos2d;
class PTPObjectButton : public CCMenuItemSprite
{
public:
    PTPObjectButton();
    virtual ~PTPObjectButton();
    static PTPObjectButton * create(CCNode* normalSprite, CCNode* selectedSprite, CCNode* disabledSprite = NULL);
    void setTarget(CCObject *rec, SEL_MenuHandler selectedSelector, SEL_MenuHandler unslectedSelector);
    void setTarget(CCObject *rec, SEL_MenuHandler selector);
    virtual void selected();
    virtual void unselected();

    virtual void update( float delta );
    virtual void setAutohide( float );

    virtual void setUserObject(CCObject *pUserObject);

    void pressed();
    void released();

    PTPScreen *getParentScreen();

protected:
    SEL_MenuHandler    m_pfnSelectedSelector;
    SEL_MenuHandler    m_pfnUnselectedSelector;

    float _autohide;
    float _time;
    bool _autohideReached;
};

#endif // PTPOBJECTBUTTON_H
