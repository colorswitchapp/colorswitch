#ifndef PTMODELOBJECTCHARACTERSELECTOR_H
#define PTMODELOBJECTCHARACTERSELECTOR_H

#include "PTModelObject.h"
#include "attributes/PTPAttributeAnimation.h"
#include "attributes/PTPAttributeBoolean.h"
#include "attributes/PTPAttributeEnum.h"
#include "attributes/PTPAttributeSound.h"

class PTModelObjectCharacterSelector : public PTModelObject
{
public:
    PTModelObjectCharacterSelector(CCString className = "PTModelObjectCharacterSelector");
    ~PTModelObjectCharacterSelector();

    virtual void attributeDidUpdated( PTPAttribute *attr );

    virtual PTModelObjectCharacterSelector *duplicated();
    float spread();

    unsigned int labelModelId();
    bool labelVisibility();
    int labelSpacing();

    PTModelAnimation *unlockButtonSprite();

    static PTModel * create() {
        return new PTModelObjectCharacterSelector();
    }

    PTModelSound* unlockYesSound();
    PTModelSound* unlockNoSound();

private:
    PTPAttributeFloat *_spreadAttribute;
    PTPAttributeAnimation *_unlockButtonSpriteAttribute;
    PTPAttributeBoolean *_labelVisibilityAttribute;
    PTPAttributeFloat *_labelSpacingAttribute;
    PTPAttributeEnum *_labelNameAttribute;

    PTPAttributeSound *_unlockYesSoundAttribute;
    PTPAttributeSound *_unlockNoSoundAttribute;
};

#endif // PTMODELOBJECTCHARACTERSELECTOR_H
