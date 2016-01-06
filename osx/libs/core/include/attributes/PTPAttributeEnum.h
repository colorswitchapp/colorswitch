#ifndef PTPATTRIBUTEENUM_H
#define PTPATTRIBUTEENUM_H

#include "PTPAttribute.h"

class PTPAttributeEnum : public PTPAttribute
{
public:
    PTPAttributeEnum(PTModel* node, PTPAttributeValueType valueType = PTPAttributeValueExact);
    ~PTPAttributeEnum();

    virtual void initWithDictionary(CCDictionary *container);
    virtual CCDictionary* getDictionary();

    void addItem(const CCString *name, const CCString* key);
    void removeItems();
    CCDictionary* getListOfEnums();

    void setStringValue( CCString value);
    CCString stringValue();

    virtual void match(PTPAttribute* attribute);

private:
#ifdef __QT__
    CCDictionary* _enumDictionary;
#endif

    CCString _stringValue;

};

#endif // PTPATTRIBUTEENUM_H
