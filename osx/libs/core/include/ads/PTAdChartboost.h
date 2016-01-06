#ifndef PTADCHARTBOOST_H
#define PTADCHARTBOOST_H

#include "PTAdObject.h"

class PTAdChartboost : public PTAdObject
{
public:
    PTAdChartboost();
    static PTAdChartboost* shared();
    virtual ~PTAdChartboost();
    virtual void initAdNetork();
    virtual void showInterstitial();

    bool isScheduledForShowing;
};

#endif // PTADCHARTBOOST_H
