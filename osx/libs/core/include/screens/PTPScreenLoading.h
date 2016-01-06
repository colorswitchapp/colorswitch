#ifndef PTPScreenLoading_H
#define PTPScreenLoading_H

#include "PTPScreen.h"

class PTPScreenLoading : public PTPScreen
{
public:
    PTPScreenLoading();
    virtual bool init();
    static cocos2d::CCScene* scene();

    virtual void draw();

    CREATE_FUNC( PTPScreenLoading );

private:
    int _drawCounter;
    CCLabelBMFont* _loadingLabel;
};

#endif // PTPScreenLoading_H
