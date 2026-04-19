#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RobotManager.generated.h"

class UBaseMovement;

UENUM(BlueprintType)
enum class EConfigDriveType : uint8{
    FourWheel UMETA(DisplayName="Four Wheel"),
    TankTread UMETA(DisplayName="Tank Tread")
};

UENUM(BlueprintType)
enum class EMotorType : uint8{
    Balanced        UMETA(DisplayName="Balanced"),
    HiSpeedLoTorque UMETA(DisplayName="Hi-Speed / Lo-Torque")
};

UENUM(BlueprintType)
enum class EManipType : uint8{
    Claw UMETA(DisplayName="Claw"),
    Lift UMETA(DisplayName="Lift")
};


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MOVEMENT_API URobotManager : public UActorComponent{
    GENERATED_BODY()

public:
    URobotManager();

    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    // --- Curr Robot Config (set via SetCurrConfig call or panel in Unreal) ---

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotConfig")
    EMotorType MotorType = EMotorType::Balanced;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotConfig")
    EManipType ManipType = EManipType::Claw;

    // Called by the 'Accept Config' button in the RobotConfig menu
    UFUNCTION(BlueprintCallable, Category="Robot Config")
    void SetCurrConfig(int32 InMotorType, int32 InManipSlot);

    // --- Movement Constants ---
    // move speed
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotConfig Speed")
    float MoveSpeed = 300.f;

    // scaling factor for motor types used for AngularSpeed calc
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotConfig Speed")
    float BalancedMotorSize = 50.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotConfig Speed")
    float HiSpeedMotorSize = 100.f;

    // differential used for TurnLeft/TurnRight ComponentFunction calls
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotConfig Turn")
    float TurnMotorDiff = 100.f;

    // degrees arm rotates for RaiseArm/LowerArm calls (+X=clockwise/down, -X=counter-clockwise/up)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotConfig Arm")
    float ArmRotationAmount = 45.f;

    // --- Duration Constants for ComponentFunctions ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotConfig Duration")
    float RaiseArmDuration = 1.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotConfig Duration")
    float LowerArmDuration = 1.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotConfig Duration")
    float OpenClawDuration = 0.8f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotConfig Duration")
    float CloseClawDuration = 0.8f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotConfig Duration")
    float RaiseLiftDuration = 1.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotConfig Duration")
    float LowerLiftDuration = 1.5f;

    // --- Enqueue Functions ---
    // * called by RobotComponentInterface::Dispatch when interpreter encounters ComponentFunction calls by player
    // * component actions skipped if component already up/down/open/closed
    void EnqueueMoveForward(float Duration);
    void EnqueueMoveBackward(float Duration);
    void EnqueueTurnLeft(float Duration);
    void EnqueueTurnRight(float Duration);
    void EnqueueRaiseArm();
    void EnqueueLowerArm();
    void EnqueueOpenClaw();
    void EnqueueCloseClaw();
    void EnqueueRaiseLift();
    void EnqueueLowerLift();

    UFUNCTION(BlueprintCallable, Category="Robot")
    void ClearQueue();

private:
    enum class EActionType : uint8{ Move, ArmMove, ClawMove, LiftMove };

    struct FRobotAction{
        EActionType Type = EActionType::Move;
        float Arg0 = 0.f; // Robot Move: LMotorPower or ArmMove: rotation degrees
        float Arg1 = 0.f; // Robot Move: RMotorPower
        float Duration = 0.f;
        int32 IArg0 = 0; // ClawMove/LiftMove: direction (0=close/lower, 1=open/raise)
    };

    UPROPERTY()
    UBaseMovement* BaseMovementComp = nullptr;

    TArray<FRobotAction> ActionQueue;
    int32 QueueIndex    = 0;
    float ElapsedTime   = 0.f;
    bool  bActionStarted = false;

    // curr component state on robot
    bool bArmIsUp    = true;   // arm starts in up state (??)
    bool bClawIsOpen = false;  // claw starts closed (??)
    bool bLiftIsUp   = false;  // lift starts in down state (??)

    float GetConfigSize() const;
    float GetActionWaitTime(EActionType ActionType, float Duration) const;
    void  DispatchAction(const FRobotAction& Action);
};
