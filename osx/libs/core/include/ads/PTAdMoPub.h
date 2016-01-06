#ifndef PTADMOPUB_H
#define PTADMOPUB_H

#include "PTAdObject.h"

class PTAdMoPub : public PTAdObject
{
public:
    PTAdMoPub();

    static PTAdMoPub* shared();

    virtual void initAdNetork();
    virtual void showInterstitial();
    virtual void showBanner();
    virtual void hideBanner();

};

#endif // PTADMOPUB_H
