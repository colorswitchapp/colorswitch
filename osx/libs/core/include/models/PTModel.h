#ifndef PTMODEL_H
#define PTMODEL_H

#include "cocos2d.h"
#include "attributes/PTPAttribute.h"
#include "attributes/PTPAttributeString.h"
#include "attributes/PTPAttributeGroup.h"

USING_NS_CC;


class PTModel : public CCObject {
public:
    PTModel(CCString className, CCString name = CCString());
    virtual ~PTModel();

    virtual void initWithDictionary(CCDictionary *container);
    virtual CCDictionary *getDictionary();
    virtual CCDictionary *getConnectionsDictionary();
    virtual void initConnectionsWithDictionary(CCDictionary *container);

    void setDeleted(bool);
    bool isDeleted();

    virtual void cleanup();

    int id() const;
    CCString name() const;
    void setName(const CCString &name);

    CCString className() const;
    bool isKindOf(CCString className) const;

    float time() const;
    void setTime(float time);

    virtual void match(PTModel* model); //match current model with input model

    virtual void update(float dt);
    virtual void attributeDidUpdated(PTPAttribute *attr);
    virtual void attributeDidConnected(PTPAttribute *attr);
    virtual void attributeWillDisconnected(PTPAttribute *attr);

    PTPAttribute *addAttribute(const CCString &name,
                               PTPAttributeType type,
                               PTPAttributeValueType valueType = PTPAttributeValueExact,
                               PTPAttributeGroup *group = NULL,
                               PTPAttributeDirection direction = PTPAttributeInput,
                               bool connectable = false);
    int attributeCount() const;
    PTPAttribute *attributeAt(int index) const;
    int attributeIndex(PTPAttribute *) const;

protected:
    PTPAttributeString *_nameAttribute;

private:
    void setId( int );

private:        
    CCString _className;
    CCArray *_attributes;

    unsigned int _id;
    float _time;

    bool _deleted;

    friend class PTAnimationEditorWidget;
    friend class PTLevelEditorScreen;
    friend class PTUndoGraphicsObjectCommand;
};

#endif // PTMODEL_H
