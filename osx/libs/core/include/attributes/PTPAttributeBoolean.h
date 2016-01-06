#ifndef PTPATTRIBUTEBOOLEAN_H
#define PTPATTRIBUTEBOOLEAN_H

#include "PTPAttribute.h"

class PTPAttributeBoolean : public PTPAttribute
{
public:
    PTPAttributeBoolean(PTModel * parent, PTPAttributeValueType valueType = PTPAttributeValueExact);

    virtual void initWithDictionary(CCDictionary *container);
    virtual CCDictionary *getDictionary();

    bool value() const;
    void setValue(bool value);

    void setDefaultValue(bool value);

    virtual void match(PTPAttribute *attribute);

private:
    bool _value;
    bool _defaultValue;
};

#endif // PTPATTRIBUTEBOOLEAN_H
