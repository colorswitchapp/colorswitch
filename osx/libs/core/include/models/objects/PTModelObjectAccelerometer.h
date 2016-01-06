#ifndef PTMODELOBJECTACCELEROMETER_H
#define PTMODELOBJECTACCELEROMETER_H

#include "PTModelObjectManipulator.h"

class PTModelObjectAccelerometer : public PTModelObjectManipulator
{
public:
    PTModelObjectAccelerometer(CCString className = "PTModelObjectAccelerometer");

    static PTModel * create() {
        return new PTModelObjectAccelerometer();
    }

    virtual void attributeDidUpdated( PTPAttribute *attr );

    virtual void initWithDictionary( cocos2d::CCDictionary *dict );

    virtual PTModelObject* duplicated();

    CCString controlType();
    void setControlType(CCString type);

protected:
    PTPAttributeEnum *_controlTypeAttribute;

private:
    void updateControlTypeVisibility();
};

#endif // PTMODELOBJECTACCELEROMETER_H
