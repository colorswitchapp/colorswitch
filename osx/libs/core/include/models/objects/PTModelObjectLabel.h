#ifndef PTModelObjectLabel_H
#define PTModelObjectLabel_H

#include "PTModelObject.h"
#include "attributes/PTPAttributeAction.h"
#include "attributes/PTPAttributeEnum.h"

class PTModelObjectLabel : public PTModelObject {
public:
    PTModelObjectLabel();

    virtual void initWithDictionary( cocos2d::CCDictionary *dict );
    virtual cocos2d::CCDictionary *getDictionary();

    virtual void attributeDidUpdated(PTPAttribute *attr);

    virtual PTModelObject* duplicated();

    CCLabelBMFont *getLabel() const;

    CCString getText() const;
    void setText(const CCString &);

    void setAlignment(CCString &align);
    CCString alignment() const;
    CCTextAlignment alignmentValue() const;

    float trackingValue() const;

    void addActionItem(const CCString *name, const CCString *key);

    bool isUserTextMode();
    bool isStickToEdge() const;

    PTPAttributeEnum *_actionAttribute;
    PTPAttributeEnum *_alignmentAttribute;
    PTPAttributeString *_stringAttribute;
    PTPAttributeFloat *_trackingAttribute;
    PTPAttributeBoolean *_stickToEdgeAttribute;

    virtual CCSize contentSize();

    static PTModel * create() {
        return new PTModelObjectLabel();
    }

private:
    void updateAttributesVisibility();

    CCSize _calculatedSize;
};

#endif // PTModelObjectLabel_H
