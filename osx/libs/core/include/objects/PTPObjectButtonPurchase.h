#ifndef PTPOBJECTBUTTONPURCHASE_H
#define PTPOBJECTBUTTONPURCHASE_H

#include "PTPObjectButton.h"
#include "models/objects/PTModelObjectButtonPurchase.h"
#include "models/objects/PTModelAssetPowerup.h"

class PTPObjectButtonPurchase : public PTPObjectButton
{
public:
    PTPObjectButtonPurchase();
    static PTPObjectButtonPurchase * create(CCNode* normalSprite, CCNode* selectedSprite, CCNode* disabledSprite = NULL);
    void setModel( PTModelObject* model);

    void purchaseDidComplete(const char* prductId );

    PTModelAssetPowerup* assetModel();
    PTModelObjectButtonPurchase* model();

    float price();
    void didPurchase();

    virtual void update(float delta);
private:
    PTModelObjectButtonPurchase *_model;
    PTModelAssetPowerup* _assetModel;
    CCLabelBMFont* _label;
    bool _rewardedVideoMode;
};

#endif // PTPOBJECTBUTTONPURCHASE_H
