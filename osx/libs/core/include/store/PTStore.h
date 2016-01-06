#ifndef PTSTORE_H
#define PTSTORE_H

#include "cocos2d.h"

#define PTStoreCallbackSelector(_SELECTOR) (PTStoreCallback)(&_SELECTOR)
typedef void (cocos2d::CCObject::*PTStoreCallback)( const char*);

class PTStore  {

public:
    PTStore();
    static PTStore* shared();
    void purchase( const char* productId );
    void purchaseDidComplete( const char* productId );
    void restorePurchases();
    void purchaseDidCompleteRestoring( const char* productId );
    void showProcessingMessage();
    void dismissProcessingMessage();

    void setTarget(cocos2d::CCObject *listener, PTStoreCallback selector);

private:
    cocos2d::CCObject *_callbackListener;
	PTStoreCallback _callbackSelector;
};

#endif // PTSTORE_H
