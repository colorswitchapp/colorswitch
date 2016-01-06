#ifndef PTADAPPLOVIN_H
#define PTADAPPLOVIN_H

#include "ads/PTAdObject.h"

class PTAdAppLovin : public PTAdObject
{
public:
    PTAdAppLovin();
    virtual ~PTAdAppLovin();
    static PTAdAppLovin* shared();
    virtual void initAdNetork();
    virtual void showInterstitial();
    virtual void hideInterstitial();
    virtual void showBanner();
    virtual void hideBanner();

    virtual bool isBannerVisisble();
};

#endif // PTADAPPLOVIN_H
