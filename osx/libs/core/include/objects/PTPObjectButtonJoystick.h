#ifndef PTPObjectButtonJoystick_H
#define PTPObjectButtonJoystick_H

#include "PTPObjectManipulator.h"
#include "cocos2d.h"

using namespace cocos2d;

class PTModelObject;

class PTPObjectButtonJoystick : public PTPObjectManipulator, public CCTouchDelegate
{
public:
    PTPObjectButtonJoystick();
    static PTPObjectButtonJoystick * create(PTModelObject *model);
    virtual void setModel( PTModelObject* model);
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *);
    virtual void ccTouchEnded(CCTouch *, CCEvent *);

private:
    CCPoint _startTouch;

};

#endif // PTPObjectButtonJoystick_H
