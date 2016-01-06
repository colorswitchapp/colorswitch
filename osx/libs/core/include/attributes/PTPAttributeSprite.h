#ifndef PTPATTRIBUTESPRITE_H
#define PTPATTRIBUTESPRITE_H

#include "PTPAttribute.h"
#include "models/PTModelSprite.h"
#include "models/PTModelSpriteContainer.h"

class PTPAttributeSprite : public PTPAttribute {
public:
    PTPAttributeSprite(PTModel *node, PTPAttributeValueType valueType = PTPAttributeValueExact);

    virtual void initWithDictionary(CCDictionary *container);
    virtual void initConnectionsWithDictionary(CCDictionary *container);
    virtual CCDictionary *getConnectionDictionary();

    virtual void cleanup();

    PTModelSpriteContainer *value() const;
    void setValue(PTModelSpriteContainer *value);

    void setExcludeFromAtlas( bool value );
    bool isExcludeFromAtlas();

    virtual void match( PTPAttribute* attribute );

private:
    PTModelSpriteContainer *_value;
    bool _exlcudeFromAtlas;
};

#endif // PTPATTRIBUTESPRITE_H
