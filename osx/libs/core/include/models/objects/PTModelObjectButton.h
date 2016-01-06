#ifndef PTMODELBUTTON_H
#define PTMODELBUTTON_H

#include "PTModelObjectImage.h"
#include "attributes/PTPAttributeEnum.h"
#include "attributes/PTPAttributeKey.h"

class PTModelObjectButton : public PTModelObjectImage {
public:
    PTModelObjectButton(CCString className = "PTModelObjectButton");

    CCString action();
    PTPAttributeEnum* actionAttribute();

    virtual PTModelObject* duplicated();

    int keyboardKey();
    void setKeyboardKey( int );

    bool isBlockingTouch() const;

    static PTModel * create() {
        return new PTModelObjectButton();
    }

protected:
    PTPAttributeEnum *_actionAttribute;
    PTPAttributeBoolean *_blockingTouchAttribute;
    PTPAttributeKey *_keyboardKeyAttribute;

};

#endif // PTMODELBUTTON_H
