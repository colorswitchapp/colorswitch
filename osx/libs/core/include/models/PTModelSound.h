#ifndef PTMODELSOUND_H
#define PTMODELSOUND_H

#ifdef __QT__
#include <QtMultimedia/QMediaPlayer>
#include <QFileInfo>
#include <QObject>
#endif

#include "PTModel.h"

USING_NS_CC;

#ifdef __QT__
class PTModelSound : public QObject, public PTModel {
    Q_OBJECT
#else
class PTModelSound : public PTModel {
#endif
public:
    PTModelSound(const CCString &name = CCString());
    ~PTModelSound();
    virtual void initWithDictionary(CCDictionary *container);
    virtual CCDictionary *getDictionary();

    CCString fileName() const;
    CCString filePath() const;

    CCString fileFormat() const;
    void setFileFormat( CCString );

    static PTModel *   create() {
        return new PTModelSound();
    }

    void preload();
    int play( bool looped = false);
    void playAsBackground( bool looped = false);
    bool isBackground();
    void pause( int soundId = -1);
    void stop( int soundId = -1);
    static void stopSound( int soundId );

    void setVolume(int soundId = -1,  float value = 1.0 );
    float volume(int soundId = -1) const;

    bool isPlaying() const;


#ifdef __QT__
    static PTModelSound *create(const QUrl &url);

    void setSoundFile(const CCString &filePath);
    void deleteSoundFile();
    bool isEmpty() ;

    PTModel *getUserModel();

signals:
    void playFinished();
#endif

private:
    CCString _fileFormat;
    int _soundId;
    bool _isBackground;
    bool _isPlaying;
    friend class PTModelController;
};

#endif // PTMODELSOUND_H
