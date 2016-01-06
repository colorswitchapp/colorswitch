#ifndef PTPATTRIBUTE_H
#define PTPATTRIBUTE_H

#include "cocos2d.h"

enum PTPAttributeType {
    PTPAttributeTypeFloat,
    PTPAttributeTypePoint,
    PTPAttributeTypeSprite,
    PTPAttributeTypeObject,
    PTPAttributeTypeArray,
    PTPAttributeTypeAction,
    PTPAttributeTypeString,
    PTPAttributeTypeEnum,
    PTPAttributeTypeShape,
    PTPAttributeTypeAnimation,
    PTPAttributeTypePath,
    PTPAttributeTypeAsset,
    PTPAttributeTypeGroup,
    PTPAttributeTypeColor,
    PTPAttributeTypeBoolean,
    PTPAttributeTypeSound,
    PTPAttributeTypeKey
};

enum PTPAttributeDirection {
    PTPAttributeInput = 0,
    PTPAttributeOutput
};

enum PTPAttributeValueType {
    PTPAttributeValueExact,
    PTPAttributeValueVariable
};

USING_NS_CC;

class PTModel;

class PTPAttribute : public CCObject {
public:
    PTPAttribute(PTModel *model, PTPAttributeType type, PTPAttributeValueType valueType);

    virtual void initWithDictionary(CCDictionary *container);
    virtual void initConnectionsWithDictionary(CCDictionary *container);
    virtual CCDictionary *getDictionary();
    virtual CCDictionary* getConnectionDictionary();

    virtual void cleanup();

    CCString name() const;
    CCString displayName() const;
    void setDisplayName( CCString );
    PTModel *model() const;
    PTPAttributeType type() const;

    bool isConnectable() const;
    bool isEditable() const;
    PTPAttributeDirection direction() const;

    void setEditable(bool editable);

    PTPAttributeValueType valueType() const;
    bool isVariableValue() const;

    virtual void attributeDidChanged();
    virtual void attributeDidConnected();
    virtual void attributeWillDisconnected();

    PTPAttribute *connected;

    virtual void match( PTPAttribute* attribute ); // make current attribute with same set of values as input attribute

    virtual void show();
    virtual void hide();
    bool isVisible() const;
    bool isAdvanced() const;
    void setAdvanced( bool advanced );

    virtual void update(float dt);

    void setName(const CCString &name);

    virtual void print();

protected:
    static CCDictionary *mergeContainers(CCDictionary *target, CCDictionary *source);

private:
    // Factory method to create all the attributes
    static PTPAttribute *createAttribute(PTModel *parent,
                                         PTPAttributeType type,
                                         PTPAttributeValueType valueType = PTPAttributeValueExact);

    void setDirection(PTPAttributeDirection direction);
    void setConnectable(bool connectable);

    CCString _name;
    CCString _displayName;
    PTModel *_model;

    bool _visible;
    bool _advanced; // by default we hiding all advanced attribute

    PTPAttributeDirection _direction;
    PTPAttributeType _type;    
    PTPAttributeValueType _valueType;

    bool _connectable;
    bool _editable;

    friend class PTModel;
    friend class PTInterfaceScreen;
    friend class PTNode;
};

#endif // PTPATTRIBUTE_H
