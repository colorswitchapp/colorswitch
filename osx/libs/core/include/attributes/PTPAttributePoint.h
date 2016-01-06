#ifndef PTPATTRIBUTEPOINT_H
#define PTPATTRIBUTEPOINT_H

#include "PTPAttribute.h"
#include "PTAnimationCurve.h"

class PTPAttributePoint : public PTPAttribute {
public:
    PTPAttributePoint(PTModel *node, PTPAttributeValueType valueType = PTPAttributeValueVariable);

    virtual void initWithDictionary(CCDictionary *container);
    virtual CCDictionary *getDictionary();

    std::vector<int> keyFrameMarkers();

    // return original value that include affect of variableValue();
    CCPoint valueVariated();

    CCPoint value();
    void setValue(const CCPoint &value, bool silentUpdate = false);

    void setXEmpty(bool);
    bool isXEmpty();

    void setYEmpty(bool);
    bool isYEmpty();

    void setDefaultValue(const CCPoint &value);
    void setUseDefaultValue(bool value);
    bool useDefaultValue() const;

    CCPoint variableValue() const;
    void setVariableValue(const CCPoint &value);

    virtual void match(PTPAttribute* attribute);
    virtual void print();
private:
    void setKeyFrame(CCPoint value, float time);

    CCPoint _variableValue;
    CCPoint _value;
    CCPoint _defaultValue;

    bool _isXEmpty;
    bool _isYEmpty;
    bool _useDefault;

    PTAnimationCurve *_animationCurveX;
    PTAnimationCurve *_animationCurveY;

    friend class PTAnimationEditorWidget;
};

#endif // PTPATTRIBUTEPOINT_H
