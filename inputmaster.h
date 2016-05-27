#ifndef INPUTMASTER_H
#define INPUTMASTER_H

#include "master.h"

#define VOLUME_STEP 0.1f
#define IDLE_THRESHOLD 5.0f
#define STEP_INTERVAL 0.23f
#define DEADZONE 0.34f

class InputMaster : public Master
{
    URHO3D_OBJECT(InputMaster, Master);
public:
    InputMaster();
    WeakPtr<Node> firstHit_;

    bool IsIdle() const noexcept { return idle_; }
    void ResetIdle();

    void SetIdle();

    JoystickState* GetActiveJoystick();
    bool MultipleJoysticks();
private:
    Input* input_;

    IntVector2 mousePos_;

    float idleTime_;
    bool idle_;
    Vector2 smoothCamRotate_;
    float smoothCamZoom_;

    HashSet<int> pressedKeys_;
    HashSet<int> pressedMouseButtons_;
    HashMap<int, HashSet<int>> pressedJoystickButtons_;
    float sinceStep_;
    bool actionDone_;

    void HandleKeyDown(StringHash eventType, VariantMap &eventData);
    void HandleKeyUp(StringHash eventType, VariantMap &eventData);
    void HandleMouseButtonDown(StringHash eventType, VariantMap &eventData);
    void HandleMouseButtonUp(StringHash eventType, VariantMap &eventData);
    void HandleJoystickButtonDown(StringHash eventType, VariantMap &eventData);
    void HandleJoystickButtonUp(StringHash eventType, VariantMap &eventData);
    void HandleUpdate(StringHash eventType, VariantMap &eventData);
    void SmoothCameraMovement(Vector2 camRot, float camZoom);
    void HandleCameraMovement(float t);
    void HandleJoystickButtons();

    void Screenshot();
    void HandleActionButtonPressed();
    void Step(Vector3 step);
    void HandleDownArrowPressed();
    void HandleRightArrowPressed();
    void HandleLeftArrowPressed();
    bool CorrectJoystickId(int joystickId);
    void HandleKeys();
};

#endif // INPUTMASTER_H
