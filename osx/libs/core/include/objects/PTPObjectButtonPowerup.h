#ifndef PTPOBJECTBUTTONPOWERUP_H
#define PTPOBJECTBUTTONPOWERUP_H

#include "PTPObjectButton.h"
#include "models/objects/PTModelObjectButtonPowerup.h"
#include "models/objects/PTModelAssetPowerup.h"

class PTPObjectButtonPowerup : public PTPObjectButton
{
public:
    PTPObjectButtonPowerup();
    static PTPObjectButtonPowerup * create(CCNode* normalSprite, CCNode* selectedSprite, CCNode* disabledSprite = NULL);

    void setModel( PTModelObject* model);
    PTModelObjectButtonPowerup* model();

    PTModelAssetPowerup* assetModel();

    void powerupDidActivated();
    virtual void update(float delta);

    virtual void selected();
    virtual void activate();

private:
    PTModelObjectButtonPowerup *_model;
    PTModelAssetPowerup* _assetModel;
    CCLabelBMFont* _label;
    CCLabelBMFont* _labelTimer;

    bool _powerButtonUseType;
    float _counter;

};

#endif // PTPOBJECTBUTTONPOWERUP_H
