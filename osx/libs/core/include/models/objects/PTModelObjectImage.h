#ifndef PTMODELOBJECTIMAGE_H
#define PTMODELOBJECTIMAGE_H

#include "attributes/PTPAttributeSprite.h"
#include "PTModelObject.h"

class PTModelObjectImage : public PTModelObject {
public:
    PTModelObjectImage(CCString className = "PTModelObjectImage");

    virtual void initWithDictionary( CCDictionary *container );
    virtual CCDictionary *getDictionary();

    virtual PTModelObject* duplicated();

    virtual void update(float dt);
    float autohide();
    bool isStickToEdge();

    virtual PTModelSpriteContainer *sprite();
    PTPAttributeSprite *spriteAttribute();

    static PTModel * create() {
        return new PTModelObjectImage();
    }

protected:
    PTPAttributeSprite *_spriteAttribute;
    PTPAttributeFloat *_autohideAttribute;
    PTPAttributeBoolean *_stickToEdgeAttribute;
};

#endif // PTMODELOBJECTIMAGE_H
