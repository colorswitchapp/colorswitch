#ifndef PTModelObjectManipulator_H
#define PTModelObjectManipulator_H

#include "PTModelObjectButton.h"
#include "attributes/PTPAttributeEnum.h"

class PTModelObjectManipulator : public PTModelObject
{
public:
    PTModelObjectManipulator(CCString className = "PTModelObjectManipulator");

    static PTModel * create() {
        return new PTModelObjectManipulator();
    }

    virtual PTModelObject* duplicated();

    float sensitivity();
    CCString controlStyle();
    void setControlStyle(CCString style);

protected:
    PTPAttributeFloat* _sensitivityAttribute;
    PTPAttributeEnum* _controlStyle;
};

#endif // PTModelObjectManipulator_H
