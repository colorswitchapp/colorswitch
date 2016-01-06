#ifndef PTPObjectButtonUrl_H
#define PTPObjectButtonUrl_H

#include "PTPObjectButton.h"

class PTModelObjectButtonUrl;

class PTPObjectButtonUrl : public PTPObjectButton
{
public:
    PTPObjectButtonUrl();
    static PTPObjectButtonUrl * create(CCNode* normalSprite, CCNode* selectedSprite, CCNode* disabledSprite = NULL);
    virtual void activate();

    void setModel( PTModelObject* model);

private:
    PTModelObjectButtonUrl* _model;
};

#endif // PTPObjectButtonUrl_H
