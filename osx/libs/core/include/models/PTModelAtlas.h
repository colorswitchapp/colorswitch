#ifndef PTMODELATLAS_H
#define PTMODELATLAS_H

#include "PTModel.h"
#include "PTModelSprite.h"

#include "attributes/PTPAttributeFloat.h"
#include "attributes/PTPAttributeAction.h"

class PTModelSpriteContainer;

class PTModelAtlas : public PTModel {
public:
    PTModelAtlas(CCString name = CCString());

    virtual void initWithDictionary( cocos2d::CCDictionary *dict );    
    void initConnectionsWithDictionary(CCDictionary *dict);
    virtual cocos2d::CCDictionary* getDictionary();
    virtual cocos2d::CCDictionary* getConnectionsDictionary();

    virtual void cleanup();

    float width() const;
    float height() const;
    float padding() const;

    // TODO: Encapsulate this member and make access and manipulation operations
    CCArray *sprites;

    void addSpriteModel( PTModelSprite* spriteModel );
    void removeSpriteModel( PTModelSprite* spriteModel );
    bool containsSpriteModel( PTModelSprite* spriteModel ) const;
    bool canFitSpriteModel( PTModelSprite* spriteModel ) const;

    void pack();
    static void packAll();
    static void cleanupSprite( PTModelSprite* spriteModel );


    void rebuild();
    
    static PTModel *  create(){
        return new PTModelAtlas();
    }
        
#ifdef __QT__
    bool needRebuild();
    void setNeedRebuild(bool);

    void exportAtlas();
    static void exportAll();
    static PTModelAtlas *findAnAtlasForModel( PTModelSprite* spriteModel );
    static PTModelAtlas *newEmptyAtlas();
    static QList<PTModelAtlas*> findContainingAtlases( PTModelSpriteContainer* );

    static void updateAtlasses();
#endif

private:

#ifdef __QT__    
    void setWidth(float width);
    void setHeight(float height);
    void setPadding(float padding);

    bool _needRebuild;
#endif

    PTPAttributeFloat* _widthAttribute;
    PTPAttributeFloat* _heightAttribute;
    PTPAttributeFloat* _paddingAttribute;

    friend class PTModelSprite;
};

static bool compareSpriteHeight(const void* p1, const void* p2);
static bool compareSpriteId(const void* p1, const void* p2);

#endif // PTMODELATLAS_H
