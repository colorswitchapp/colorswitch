#ifndef PTModelObjectButtonUrl_H
#define PTModelObjectButtonUrl_H

#include "PTModelObjectButton.h"

class PTModelObjectButtonUrl : public PTModelObjectButton {
public:
    PTModelObjectButtonUrl(CCString className = "PTModelObjectButtonUrl");

    virtual PTModelObject* duplicated();

    static PTModel * create() {
        return new PTModelObjectButtonUrl();
    }

    CCString getURL();

protected:
    PTPAttributeString* _URLAttribute;
};

#endif // PTModelObjectButtonUrl_H
