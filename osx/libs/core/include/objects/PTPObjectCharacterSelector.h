#ifndef PTPOBJECTCHARACTERSELECTOR_H
#define PTPOBJECTCHARACTERSELECTOR_H

#include "cocos2d.h"
#include "models/objects/PTModelObjectCharacterSelector.h"
#include "PTPAnimationObject.h"

struct CharacterSelectorAnimation{
    PTPAnimationObject* regularAnimation;
    PTPAnimationObject* lockedAnimation;
};

class PTPObjectCharacterSelector: public CCNode, public CCTouchDelegate
{
public:
    PTPObjectCharacterSelector();
    ~PTPObjectCharacterSelector();

    static PTPObjectCharacterSelector* create(PTModelObjectCharacterSelector* model);
    void setModel(PTModelObjectCharacterSelector* model);
    virtual void update(float delta);

    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);

    void setPriceLabel(int characterIndex);
protected:
    void unlockButtonAction(CCObject* sender);
    void purchaseDidComplete(const char *productId);
    void didPurchase();

private:
    void updateUnlockCharactersIcons();
    PTPAnimationObject* createAnimationObject(PTModelAnimation* model);

    std::vector<CharacterSelectorAnimation> _characters;
    PTModelObjectCharacterSelector* _model;
    float _selectionOffset;
    float _selectionTarget;
    int _selectedCharacterIndex;
    bool _scrollMode;

    CCLabelBMFont* _priceLabel;
    CCLabelBMFont* _characterNameLabel;
    CCMenuItemSprite* _unlockButton;
    PTPAnimationObject* _buttonAnimation;
};

#endif // PTPOBJECTCHARACTERSELECTOR_H
