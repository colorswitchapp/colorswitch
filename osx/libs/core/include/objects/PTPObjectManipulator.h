#ifndef PTPObjectManipulator_H
#define PTPObjectManipulator_H

#include "cocos2d.h"

using namespace cocos2d;

class PTModelObject;
class PTModelObjectManipulator;

class PTPObjectManipulator : public CCNode
{
public:
    PTPObjectManipulator();
    static PTPObjectManipulator * create();

    virtual void setModel( PTModelObject* model);
    PTModelObjectManipulator* model();

    virtual float sensitivity();
    bool isAbsoluteControlStyle();

protected:
    PTModelObjectManipulator *_model;

private:
    bool _absoluteControlStyle;

};

#endif // PTPObjectManipulator_H
