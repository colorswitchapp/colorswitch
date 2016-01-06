#ifndef PTPOBJECTTEXT_H
#define PTPOBJECTTEXT_H

#include "PTPObject.h"

class PTModelObjectLabel;

class PTPObjectText : public PTPObject
{
public:
    PTPObjectText(PTModelObjectLabel* model);
    virtual ~PTPObjectText();

    virtual void update( float dt);

    static PTPObjectText* create(PTModelObjectLabel* model);

    virtual PTModelObject *model();

    void setUpdateInfo(const char *key);

protected:

private:
    cocos2d::CCString *_updateType;
    PTModelObjectLabel* _model;
};

#endif // PTPOBJECTTEXT_H
