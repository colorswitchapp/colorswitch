#ifndef PTADVUNGLE_H
#define PTADVUNGLE_H

#include "ads/PTAdObject.h"

class PTAdVungle : public PTAdObject
{
public:
    PTAdVungle();
    static PTAdVungle *shared();
    virtual void initAdNetork();
    virtual void showInterstitial();
    virtual void showBanner();
    virtual void hideBanner();
};

#endif // PTADVUNGLE_H
