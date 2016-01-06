#ifndef PTADOBJECT_H
#define PTADOBJECT_H

#include "cocos2d.h"

class PTAdObject
{
public:
    PTAdObject();
    virtual ~PTAdObject();
    virtual void initAdNetork();

    virtual void initBanner();
    virtual void initInterstitial();

    virtual void showBanner();
    virtual void hideBanner();

    virtual void showInterstitial();
    virtual void hideInterstitial();

    virtual void showRewardedVideo();

    bool _failBanner;
    bool _failInterstitial;
    
    bool _visibleBanner;
    bool _visibleInterstitial;

    bool _initBanner;
    bool _initInterstitial;

	virtual bool isBannerVisisble();
	
    virtual bool isRewardedVideoAvialable();

protected:


};

#endif // PTADOBJECT_H
