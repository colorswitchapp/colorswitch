#ifndef PTPINPUTCONTROLLER_H
#define PTPINPUTCONTROLLER_H

#include "cocos2d.h"
#include "box2D/Box2D.h"
#include "models/objects/PTModelObjectAssetUnit.h"
#include "models/PTModelLinker.h"
#include "objects/PTPObjectAssetUnit.h"
#include "objects/PTPObjectAssetCharacter.h"

class PTPObjectAsset;
class PTPObjectButton;
class PTPScreen;

enum PTPInputControllerAction {
    PTPInputControllerActionUnknown,
    PTPInputControllerActionMoveUp,
    PTPInputControllerActionMoveDown,
    PTPInputControllerActionMoveRight,
    PTPInputControllerActionMoveLeft,
    PTPInputControllerActionJump,
    PTPInputControllerActionRotateLeft,
    PTPInputControllerActionRotateRight,
    PTPInputControllerActionShoot,
    PTPInputControllerActionMotorCW,
    PTPInputControllerActionMotorCCW
};

enum PTPInputControllerKey {
    PTPInputControllerKeyUnknown,
    PTPInputControllerKeyLeft,
    PTPInputControllerKeyRight,
    PTPInputControllerKeyUp,
    PTPInputControllerKeyDown,
    PTPInputControllerKeyShoot,
    PTPInputControllerKeyJump,
    PTPInputControllerKeyMotorCW,
    PTPInputControllerKeyMotorCCW,
    PTPInputControllerKeyRotateLeft,
    PTPInputControllerKeyRotateRight,
};

struct PTJointMotorStruct{
    b2RevoluteJoint* joint;
    PTModelLinker* linker;
};

class PTPInputController: public CCObject{

public:
    PTPInputController();
    ~PTPInputController();
    static PTPInputController* shared();
    static void destroy();

    void clear();

    void keyPressed( PTPInputControllerKey key);
    void keyReleased( PTPInputControllerKey key);

    void touchesBegan(CCSet *touches);
    void touchesMoved(CCSet *touches);
    void touchesEnded(CCSet *touches);

    void applyMoveVectorOnCharacters(CCPoint vector);

    void gamepadAxisMoved( int value, int axis );
    void gamepadButtonPressed( int button );
    void gamepadButtonReleased( int button );

    void buttonJumpPressed(CCObject* sender = NULL) { actionBegin( PTPInputControllerActionJump ); }
    void buttonJumpReleased(CCObject* sender = NULL){ actionEnd( PTPInputControllerActionJump ); }
    void buttonShootPressed(CCObject* sender = NULL) { actionBegin( PTPInputControllerActionShoot ); }
    void buttonShootReleased(CCObject* sender = NULL){ actionEnd( PTPInputControllerActionShoot ); }
    void buttonRotateLeftPressed(CCObject* sender = NULL){ actionBegin( PTPInputControllerActionRotateLeft ); }
    void buttonRotateLeftReleased(CCObject* sender = NULL){ actionEnd( PTPInputControllerActionRotateLeft ); }
    void buttonRotateRightPressed(CCObject* sender = NULL){ actionBegin( PTPInputControllerActionRotateRight );}
    void buttonRotateRightReleased(CCObject* sender = NULL){ actionEnd( PTPInputControllerActionRotateRight ); }

    void buttonMoveRightPressed(CCObject* sender = NULL){ actionBegin( PTPInputControllerActionMoveRight );}
    void buttonMoveRightReleased(CCObject* sender = NULL){ actionEnd( PTPInputControllerActionMoveRight ); }
    void buttonMoveLeftPressed(CCObject* sender = NULL){ actionBegin( PTPInputControllerActionMoveLeft );}
    void buttonMoveLeftReleased(CCObject* sender = NULL){ actionEnd( PTPInputControllerActionMoveLeft ); }
    void buttonMoveUpPressed(CCObject* sender = NULL){ actionBegin( PTPInputControllerActionMoveUp );}
    void buttonMoveUpReleased(CCObject* sender = NULL){ actionEnd( PTPInputControllerActionMoveUp ); }
    void buttonMoveDownPressed(CCObject* sender = NULL){ actionBegin( PTPInputControllerActionMoveDown );}
    void buttonMoveDownReleased(CCObject* sender = NULL){ actionEnd( PTPInputControllerActionMoveDown ); }

    void buttonMotorCWPressed(CCObject* sender = NULL){ actionBegin( PTPInputControllerActionMotorCW ); }
    void buttonMotorCWReleased(CCObject* sender = NULL){ actionEnd( PTPInputControllerActionMotorCW); }
    void buttonMotorCCWPressed(CCObject* sender = NULL){ actionBegin( PTPInputControllerActionMotorCCW); }
    void buttonMotorCCWReleased(CCObject* sender = NULL){ actionEnd( PTPInputControllerActionMotorCCW); }

    bool anyCharacterAlive() const;
    void killAllCharacters();
    void addCharacter(PTPObjectAssetCharacter* character);
    void removeCharacter(PTPObjectAssetCharacter* character);

    CCArray* characters();
    CCPoint charactersAveragePosition();
    CCPoint charactersAverageInitialPosition();
    CCPoint charactersAverageScale();
    CCRect charactersBoundingBox();

    void showCharacters();
    void hideCharacters();

    int characterZDepth();

    void moveCharacters( float dx, float dy);
    void setCharactersPosition( CCPoint p);
    void addMotor(PTJointMotorStruct motor);
    void removeAllMotors();

    void addSpawner( PTPObjectAsset* object, PTPInputControllerAction action);
    void removeSpawner( PTPObjectAsset* object );
    void associateSpawnerWithCharacter(PTPObjectAsset* spawner, PTPObjectAsset* character);
    void removeAllSpawners();

    void addKeyBinding( int keyCode, PTPObjectButton *button);
    void removeKeyBinding( int keyCode, PTPObjectButton *button);
    bool handleKeyPressOnScreen( int keyCode, PTPScreen *screenLayer );
    bool handleKeyReleaseOnScreen( int keyCode, PTPScreen *screenLayer );

private:
    void actionBegin(PTPInputControllerAction action);
    void actionEnd(PTPInputControllerAction action);

    CCPoint getActionsResultVector();
    float getActionsResultMotorSpeed(PTJointMotorStruct motor);

    CCArray* _characters;
    typedef std::list<PTPInputControllerAction> PTPInputControllerActionList;
    PTPInputControllerActionList _appliedActions;

    typedef std::list<PTJointMotorStruct> PTJointMotorStructList;
    PTJointMotorStructList _motors;
    typedef std::list<PTPObjectAsset*> PTPObjectAssetList;
    std::map<PTPInputControllerAction, PTPObjectAssetList> _spawnerObjects;

    
};

#endif // PTPINPUTCONTROLLER_H
