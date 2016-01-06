#ifndef PTPObjectAccelerometer_H
#define PTPObjectAccelerometer_H

#include "PTPObjectManipulator.h"
#include "cocos2d.h"

using namespace cocos2d;

class PTModelObject;
class PTModelObjectAccelerometer;

class PTPObjectAccelerometer : public PTPObjectManipulator, public CCAccelerometerDelegate
{
public:
    PTPObjectAccelerometer();
    ~PTPObjectAccelerometer();

    static PTPObjectAccelerometer * create(PTModelObject *model);

    virtual void didAccelerate(CCAcceleration* pAccelerationValue);
    virtual float sensitivity();
    virtual void setModel( PTModelObject* model);
    PTModelObjectAccelerometer* model();

private:
    PTModelObjectAccelerometer *_model;
};

#endif // PTPObjectAccelerometer_H
