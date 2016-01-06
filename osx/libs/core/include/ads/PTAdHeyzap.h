#ifndef PTADHEYZAP_H
#define PTADHEYZAP_H

#include "ads/PTAdObject.h"

class PTAdHeyzap : public PTAdObject
{
public:
    PTAdHeyzap();

    static PTAdHeyzap* shared();

    virtual void initAdNetork();
    virtual void showRewardedVideo();
    virtual bool isRewardedVideoAvialable();
    virtual void showBanner();
    virtual void hideBanner();
    virtual void initBanner();
    virtual void showInterstitial();
    virtual void hideInterstitial();

    virtual bool isBannerVisisble();

};

#endif // PTADHEYZAP_H
