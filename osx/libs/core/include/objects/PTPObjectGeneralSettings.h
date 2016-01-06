#ifndef PTPOBJECTGENERALSETTINGS_H
#define PTPOBJECTGENERALSETTINGS_H

#include "cocos2d.h"
using namespace cocos2d;

class PTModelGeneralSettings;

class PTPObjectGeneralSettings {
public:
    PTPObjectGeneralSettings();
    ~PTPObjectGeneralSettings();

    static PTPObjectGeneralSettings* shared();
    static void resetShared();

    void setMoveSpeed(float x, float y);
    CCPoint moveSpeed() const;

    void setGravity( CCPoint value);
    CCPoint gravity();

    void setUpForce( CCPoint value);
    CCPoint upForce() const;

    void setUpForceDuration(float value);
    float upForceDuration() const;

    void setUpForceCounter(float value);
    float upForceCounter() const;

    void setUpForceFromGround( bool upForceFromGround );
    bool isUpForceFromGround();

    void setLeftLeanForce(float value);
    float leftLeanForce() const;

    void setRightLeanForce(float value);
    float rightLeanForce() const;

    float gameSpeedMin();
    void setGameSpeedMin( float );

    float gameSpeedMax();
    void setGameSpeedMax( float );

    float gameSpeedIncrease();
    void setGameSpeedIncrease( float );

    float gameSpeedCurrent();
    void setGameSpeedCurrent( float );

    void setFriction( float value );
    float friction();

    void setSimulationTimeScale( float value);
    float simulationTimeScale();

    void setVelocityScale( float value  );
    float velocityScale();

    void setRotationScale( float rotationScale );
    float rotationScale();

    void setBounceForce( CCPoint value);
    CCPoint bounceForce();

    void setRestitution( float );
    float restitution() const;

    void setScoreMultiplier( float );
    float scoreMultiplier() const;

    void setCharacterFriction( CCPoint value);
    CCPoint characterFriction();

    void setPlatformFriction( float );
    float platformFriction() const;

    void setGameplayAngleDirection(float);
    float gameplayAngleDirection();
    CCPoint gameplayDirection();

private:
    CCPoint _gravity;
    CCPoint _moveSpeed;
    CCPoint _bounceForce;
    CCPoint _upForce;
    float _upForceDuration;
    float _upForceCounter;
    float _jumpGroundThreshold;
    float _leftLeanForce;
    float _rightLeanForce;
    float _simulationTimeScale;
    float _friction;
    CCPoint _characterFriction;
    float _velocityScale;
    float _rotationScale;
    float _restitution;
    float _platformFriction;
    float _scoreMultiplier;

    bool _upForceFromGround;

    float _gameSpeedMin;
    float _gameSpeedMax;
    float _gameSpeedCurrent;
    float _gameSpeedIncrease;
    float _gameplayAngleDirection;

    PTModelGeneralSettings* _model;
};

#endif // PTPOBJECTGENERALSETTINGS_H
