#ifndef PTMODELOBJECTBUTTONPOWERUP_H
#define PTMODELOBJECTBUTTONPOWERUP_H

#include "PTModelObjectButton.h"

class PTModelObjectButtonPowerup : public PTModelObjectButton
{
public:
    PTModelObjectButtonPowerup(CCString className = "PTModelObjectButtonPowerup");

    CCPoint labelOffset();
    float labelScale() const;
    bool isUnlimitedUse();

    virtual PTModelObject* duplicated();

    bool isAboveCharacter();

    int maxRefills();
    int refillTimeout();

    bool refillAtStart();

    bool forceOnPress();

    float visibilityThreshold();

    static PTModel * create() {
        return new PTModelObjectButtonPowerup();
    }

    virtual void attributeDidUpdated(PTPAttribute *attr);

private:
    PTPAttributeFloat* _labelScaleAttribute;
    PTPAttributePoint* _labelOffsetAttribute;
    PTPAttributeBoolean* _unlimitedUseAttribute;

    PTPAttributeBoolean* _forceOnPressAttribute;

    PTPAttributeBoolean* _refillAtStartAttribute;

    PTPAttributeFloat* _refillTimeout;
    PTPAttributeFloat* _maxRefils;
    PTPAttributeEnum* _layering;

    PTPAttributeFloat* _visibilityThresholdAttribute;
};

#endif // PTMODELOBJECTBUTTONPOWERUP_H
