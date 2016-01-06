#ifndef PTPATTRIBUTEFLOAT_H
#define PTPATTRIBUTEFLOAT_H

#include "PTPAttribute.h"
#include "PTAnimationCurve.h"

class PTPAttributeFloat : public PTPAttribute {
public:
    PTPAttributeFloat(PTModel *node, PTPAttributeValueType valueType = PTPAttributeValueVariable);

    virtual void initWithDictionary(CCDictionary *container);
    virtual CCDictionary *getDictionary();

    void setDefaultValue(float value);
    void setUseDefaultValue(bool value);
    bool useDefaultValue() const;

    // include original value and variableValue
    float valueVariated();

    float value();
    void setValue(float value, bool silentUpdate = false);

    void setEmpty(bool);
    bool isEmpty();

    int intValue();
    void setIntValue(int value);

    float variableValue() const;
    void setVariableValue(float variableValue);

    virtual void match(PTPAttribute *attribute);

    float minValue() const;
    void setMinValue(float);

    float maxValue() const;
    void setMaxValue(float);

    float bound(float) const;
    virtual void print();
private:
    void setKeyFrame(float value, float time);

    float _minValue;
    float _maxValue;

    bool _isEmpty;
    bool _useDefault;

    float _defaultValue;
    float _value;
    float _variableValue;
    PTAnimationCurve *_animationCurve;

    friend class PTAnimationEditorWidget;
};

#endif // PTPATTRIBUTEFLOAT_H
