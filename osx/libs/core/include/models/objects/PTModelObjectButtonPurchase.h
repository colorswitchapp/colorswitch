#ifndef PTMODELOBJECTBUTTONPURCHASE_H
#define PTMODELOBJECTBUTTONPURCHASE_H

#include "PTModelObjectButton.h"
#include "attributes/PTPAttributeSound.h"


class PTModelObjectButtonPurchase : public PTModelObjectButton
{
public:
    PTModelObjectButtonPurchase(CCString className = "PTModelObjectButtonPurchase");

    static PTModel * create() {
        return new PTModelObjectButtonPurchase();
    }

    virtual void initWithDictionary(CCDictionary *container);

    virtual void attributeDidUpdated( PTPAttribute *attr );

    virtual PTModelObject* duplicated();

    float visibilityThreshold();

    CCString storeIdentifier();
    CCString rewardedVideoAdNetwork();
    CCString actionType();

    PTModelSound* purchaseCompleteSound();

    bool isBuyAndUse();
    bool isInAppPurchase();
    bool isRewardedVideo();
    float price();
    int quantity();

private:
    PTPAttributeEnum *_actionTypeAttribute;
    PTPAttributeString* _storeIdentifierAttribute;
    PTPAttributeBoolean* _inAppPurchase;
    PTPAttributeBoolean* _buyAndUseAttribute;
    PTPAttributeFloat* _priceAttribute;
    PTPAttributeFloat* _quantityAttribute;
    PTPAttributeFloat* _visibilityThresholdAttribute;

    PTPAttributeEnum* _purchaseMethodAttribute;
    PTPAttributeEnum* _rewardedVideoAdNetworkAttribute;
    PTPAttributeSound* _pucrhaseCompleteSoundAttribute;
};

#endif // PTMODELOBJECTBUTTONPURCHASE_H
