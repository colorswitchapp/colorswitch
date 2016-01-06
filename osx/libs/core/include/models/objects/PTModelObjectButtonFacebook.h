#ifndef PTMODELOBJECTBUTTONFACEBOOK_H
#define PTMODELOBJECTBUTTONFACEBOOK_H

#include "PTModelObjectButtonUrl.h"

class PTModelObjectButtonFacebook : public PTModelObjectButtonUrl
{
public:
    PTModelObjectButtonFacebook(CCString className = "PTModelObjectButtonFacebook");

    virtual PTModelObject* duplicated();

    static PTModel * create() {
        return new PTModelObjectButtonFacebook();
    }

    CCString facebookURL();
    CCString facebookID();

private:
    PTPAttributeString* _facebookIdAttribute;
};

#endif // PTMODELOBJECTBUTTONFACEBOOK_H
