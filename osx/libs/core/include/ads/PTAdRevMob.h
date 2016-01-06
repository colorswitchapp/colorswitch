#ifndef PTADREVMOB_H
#define PTADREVMOB_H

#include "ads/PTAdObject.h"

class PTAdRevMob : public PTAdObject
{
public:
    PTAdRevMob();
    ~PTAdRevMob();
    static PTAdRevMob* shared();
    virtual void initAdNetork();
    virtual void showInterstitial();
    virtual void hideInterstitial();
    virtual void showBanner();
    virtual void hideBanner();

};

#endif // PTADREVMOB_H
