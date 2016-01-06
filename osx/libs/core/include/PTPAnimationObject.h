#ifndef PTPANIMATIONOBJECT_H
#define PTPANIMATIONOBJECT_H

#include "cocos2d.h"
#include "attributes/PTPAttributeAnimation.h"
#include "models/PTModelAnimation.h"
#include "attributes/PTPAttributeAction.h"

class PTPAnimationObject : public CCNode {
public:
    PTPAnimationObject( PTModelAnimation *model, CCNode *parent = NULL, bool isBatchMode = true);
    ~PTPAnimationObject();

    virtual void update(float delta);
    virtual void setParent(CCNode *parent);

    CCRect contentRect();

    int childrenCount();

    virtual int getZOrder();

    void setTime( float time );
    void reset();

    void setAnimationCallback(PTPActionPointer action, CCObject *target);

private:
    float _time;

    void updateContentRect();
    CCRect _contentRect;

    PTPActionPointer _actionPointer;
    CCObject *_actionTarget;

    PTModelAnimation *_model;
    std::map<PTModelObject *, CCNode *> _nodeMap;

    friend class PTPObjectCharacterSelector;
};

#endif // PTPANIMATIONOBJECT_H
