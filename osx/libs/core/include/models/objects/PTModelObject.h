#ifndef PTMODELOBJECT_H
#define PTMODELOBJECT_H

#include "cocos2d.h"
#include "models/PTModel.h"
#include "models/PTModelSprite.h"
#include "attributes/PTPAttributePoint.h"
#include "attributes/PTPAttributeFloat.h"
#include "attributes/PTPAttributeSprite.h"
#include "attributes/PTPAttributeBoolean.h"

#include <vector>

class PTModelObject : public PTModel {
public:
    PTModelObject(CCString className = "PTModelObject", CCString name = "Untitled");
    ~PTModelObject();

    virtual void initWithDictionary( cocos2d::CCDictionary *dict );
    virtual cocos2d::CCDictionary *getDictionary();

    virtual void attributeDidUpdated( PTPAttribute *attr );

    virtual PTModelObject* duplicated();

    virtual void match(PTModel* model);

    CCPoint positionVariated();
    float rotationVariated();
    CCPoint scaleVariated();

    virtual void setPosition( CCPoint pos);
    virtual CCPoint position() const;
    CCPoint autoAlignedPosition() const;

    virtual void setRotation( float value );
    virtual void setScale( CCPoint value );

    // TODO: Encapsulate fields
    PTPAttributeFloat *rotation;
    PTPAttributePoint *scale;

    int zDepth() const;
    void setZDepth(int value);

    virtual bool isSpawner();
    virtual float spawnRate();

    //return sprite reperesentation
    virtual PTModelSpriteContainer *sprite();
    virtual float opacity();

    PTModelObject *parent() const;
    void setParent(PTModelObject *parent);    

    virtual CCSize contentSize();

    std::vector<int> keyframeMarkers();

    static PTModel * create() {
        return new PTModelObject();
    }       

#ifdef __QT__
    PTModel *getUserModel();
#endif

protected:
    PTPAttributePoint *_position;

private:    
    int _zDepth;
    PTModelObject *_parent;        

    friend class PTAnimationEditorWidget;
};

#endif // PTMODELOBJECT_H
