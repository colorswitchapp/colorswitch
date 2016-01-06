#ifndef PTADLEADBOLT_H
#define PTADLEADBOLT_H

#include "PTAdObject.h"

class PTAdLeadBolt : public PTAdObject
{
public:
    PTAdLeadBolt();
    static PTAdLeadBolt* shared();
    virtual void initAdNetork();
    virtual void showBanner();
    virtual void hideBanner();
    virtual void showInterstitial();
    virtual void hideInterstitial();
};

#endif // PTADLEADBOLT_H
