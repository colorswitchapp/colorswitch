#ifndef PTPATTRIBUTEANIMATION_H
#define PTPATTRIBUTEANIMATION_H

#include "PTPAttribute.h"
#include "models/PTModelAnimation.h"
#include "models/PTModelSpriteContainer.h"

class PTPAttributeAnimation : public PTPAttribute {
public:
    PTPAttributeAnimation(PTModel *node, PTPAttributeValueType valueType = PTPAttributeValueExact);

    virtual void initConnectionsWithDictionary(CCDictionary *container);
    virtual CCDictionary *getConnectionDictionary();

    virtual void cleanup();

    PTModelAnimation *value() const;
    void setValue(PTModelAnimation *value);

    PTModelSpriteContainer *spriteValue();
    void setSpriteValue(PTModelSpriteContainer *value);

#ifdef __QT__
    void buildPixmap();
#endif

private:
    PTModelAnimation *_value;
    PTModelSpriteContainer *_spriteValue;
};

#endif // PTPATTRIBUTEANIMATION_H
