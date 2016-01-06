#ifndef PTADFACEBOOK_H
#define PTADFACEBOOK_H

#include "ads/PTAdObject.h"

class PTAdFacebook : public PTAdObject
{
public:
    PTAdFacebook();
    ~PTAdFacebook();
    static PTAdFacebook* shared();
    virtual void initAdNetork();
    
    virtual void initBanner();
    virtual void initInterstitial();

    virtual void showBanner();
    virtual void hideBanner();
    virtual void showInterstitial();
    virtual void hideInterstitial();

    virtual bool isBannerVisisble();
};

#endif // PTADFACEBOOK_H
