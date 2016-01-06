#ifndef PTSERVICES_H
#define PTSERVICES_H

#include "cocos2d.h"
#define PTServicesCallbackSelector(_SELECTOR) (PTServicesCallback)(&_SELECTOR)
typedef void (cocos2d::CCObject::*PTServicesCallback)( bool );

class PTServices
{
public:
    PTServices();
    static PTServices* shared();
    static void printMemoryStat();

    void openUrl(const char* link);
    void openReviewUrl();
    void openShareWidget(const char* message);

    void shareScore();
    void shareScore( int score );

    void loginGameServices();
    bool isGameServiceEnabled();
    void showLeaderboard();

    void submitScore();
    void submitScroe(int score);

    void showFacebookPage( const char* facebookURL, const char* facebookID);

    void showWarningMessage( const char* message, cocos2d::CCObject *listener,  PTServicesCallback selector);
    void warningMessageClicked( bool yes );

    void saveScreenshot();

    char* sha1( unsigned char *data, unsigned long size);
    char* fileSignature( const char* fileName );

    int availableProcessors();
    int getCoresNumber();

    void loadingDidComplete();

    void setFullscreen( bool value );
    void exitApplication();

    const char *platformName() const;

    void showCustomFullScreenAd();

private:
    bool isGameServiceAvialable();
    bool _gameServicesEnabled;

    cocos2d::CCObject *_callbackListener;
    PTServicesCallback _callbackSelector;

};

#endif // PTSERVICES_H
