#ifndef PTADUPSIGHT_H
#define PTADUPSIGHT_H


#include "ads/PTAdObject.h"

class PTAdUpsight : public PTAdObject
{
public:
    PTAdUpsight();
    static PTAdUpsight *shared();

    virtual void initAdNetork();
    virtual void showInterstitial();
    virtual void showBanner();
    virtual void hideBanner();
};

#endif // PTADUPSIGHT_H
