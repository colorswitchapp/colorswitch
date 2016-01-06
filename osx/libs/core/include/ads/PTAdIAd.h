#ifndef PTADIAD_H
#define PTADIAD_H

#include "PTAdObject.h"

class PTAdIAd : public PTAdObject
{
public:
    PTAdIAd();
    ~PTAdIAd();
    static PTAdIAd* shared();
    virtual void initAdNetork();
    
    virtual void initBanner();
    virtual void initInterstitial();

    virtual void showBanner();
    virtual void hideBanner();
    virtual void showInterstitial();
    virtual void hideInterstitial();

    
	virtual bool isBannerVisisble();
};

#endif // PTADIAD_H
