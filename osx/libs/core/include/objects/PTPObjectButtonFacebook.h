#ifndef PTPOBJECTBUTTONFACEBOOK_H
#define PTPOBJECTBUTTONFACEBOOK_H

#include "PTPObjectButton.h"
#include "models/objects/PTModelObjectButtonFacebook.h"

class PTPObjectButtonFacebook : public PTPObjectButton
{
public:
    PTPObjectButtonFacebook();
    static PTPObjectButtonFacebook * create(CCNode* normalSprite, CCNode* selectedSprite, CCNode* disabledSprite = NULL);
    virtual void activate();

    void setModel( PTModelObject* model);

private:
    PTModelObjectButtonFacebook* _model;
};

#endif // PTPOBJECTBUTTONFACEBOOK_H
