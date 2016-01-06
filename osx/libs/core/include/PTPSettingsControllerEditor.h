#ifndef PTPSETTINGSCONTROLLEREDITOR_H
#define PTPSETTINGSCONTROLLEREDITOR_H

#include "PTPSettingsController.h"

class PTPSettingsControllerEditor : public PTPSettingsController
{
public:
    PTPSettingsControllerEditor();

    virtual void save();
    virtual void load();
};

#endif // PTPSETTINGSCONTROLLEREDITOR_H
