#ifndef PTMODELSPRITECONTAINER_H
#define PTMODELSPRITECONTAINER_H

#include "PTModel.h"
#include "PTModelSprite.h"
#include "attributes/PTPAttributeFloat.h"
#include "attributes/PTPAttributePoint.h"

USING_NS_CC;

class PTModelSpriteContainer : public PTModel {
public:
    PTModelSpriteContainer(CCString name = CCString());
    virtual ~PTModelSpriteContainer();

    virtual void initWithDictionary(CCDictionary *container);
    virtual void initConnectionsWithDictionary(CCDictionary *container);
    virtual CCDictionary *getConnectionsDictionary();

    virtual void cleanup();

    PTModelSpriteContainer* duplicated();

    CCPoint pivot() const; //realted cooridnates of pivot point (related to 0,0 - origin)

    void addSpriteModel( PTModelSprite *sprite );
    PTModelSprite *spriteModelAtIndex( int index );
    bool containsSpriteModel( PTModelSprite *sprite );
    int spriteModelsCount();       

    CCSize sourceSize();
    CCSize size();
    CCPoint offset();


    void setExcludeFromAtlas( bool value );
    bool isExcludeFromAtlas();

    CCSprite *getSprite(float animationSpeed = 1.0);
    CCTexture2D *getTexture();

    int count();

    void setOpacity( float );
    float opacity() const;
    void setBrightness( float );
    float brightness() const;
    void setContrast( float );
    float contrast() const;
    void setHue( float );
    float hue() const;
    void setSaturation( float );
    float saturation() const;

    static PTModel * create() {
        return new PTModelSpriteContainer();
    }

#ifdef __QT__
    static PTModelSpriteContainer *create(const QList<QUrl> &urls, bool excludeFromAtlas = false );
    void buildPixmap();
    QPixmap pixmap();
    void paint(QPainter *painter);
    void resetOffset();

    PTModel *getUserModel() const;

    // returns true if at least one sprite has non empty pixmap
    bool isValid();
#endif

private:
#ifdef __QT__
    void deleteSprites();
#endif

    void setPivot(const CCPoint &pivot);
    inline void setPivot(float x, float y);

    PTPAttributeFloat *_brightnessAttribute;
    PTPAttributeFloat *_contrastAttribute;
    PTPAttributeFloat *_hueAttribute;
    PTPAttributeFloat *_saturationAttribute;
    PTPAttributeFloat *_opacityAttribute;

    CCArray *_sprites;
    CCPoint _pivot;

    bool _excludeFromAtlas;

    friend class PTPAttributeAnimation;
    friend class PTDropImageWidget;
};

inline void PTModelSpriteContainer::setPivot(float x, float y) {
    setPivot(ccp(x, y));
}

#endif // PTMODELSPRITECONTAINER_H
