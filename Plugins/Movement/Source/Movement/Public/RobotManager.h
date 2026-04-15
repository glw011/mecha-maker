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
enum class EConfigMotorSize : uint8{
    Small UMETA(DisplayName="50cc (Small)"),  // no idea what these should be called so we're using mario kart terminology
    Large UMETA(DisplayName="100cc (Large)")
};

UENUM(BlueprintType)
enum class EConfigManipulator : uint8{
    None UMETA(DisplayName="None"),
    Claw UMETA(DisplayName="Claw"),
    ElevLift UMETA(DisplayName="Elevator Lift"),
    ScisLift UMETA(DisplayName="Scissor Lift")
};


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MOVEMENT_API URobotManager : public UActorComponent{
    GENERATED_BODY()

public:
    URobotManager();

    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    // ---- Robot Config Set in Unreal ----

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robot Config")
    EConfigDriveType DriveType = EConfigDriveType::FourWheel;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robot Config")
    EConfigMotorSize MotorSize = EConfigMotorSize::Small;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robot Config")
    EConfigManipulator Manipulator = EConfigManipulator::None;

    // move speed/size constants used by MotorSize based on current config
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robot Config|Speed")
    float SmallMotorSpeed = 300.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robot Config|Speed")
    float LargeMotorSpeed = 600.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robot Config|Speed")
    float SmallMotorSize = 50.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robot Config|Speed")
    float LargeMotorSize = 100.f;

    // preset motor differential applied for turnLeft/turnRight
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Robot Config|Turn")
    float TurnMotorDiff = 100.f;

    // ---- functiones de le queue (called by RobotComponentInterface::Dispatch) ----

    void QueueStartMove(float LMotor, float RMotor, float Duration);
    void QueueStartArmMove(float ArmSpeed, float Duration);
    void QueueStartClawMove(int32 Direction, float Duration);
    void QueueTurnLeft(float Duration);
    void QueueTurnRight(float Duration);

    UFUNCTION(BlueprintCallable, Category="Robot")
    void ClearQueue();

private:
    // action types stored in queue
    enum class EActionType : uint8 {Move, ArmMove, ClawMove};

    struct FRobotAction{
        EActionType Type  = EActionType::Move;
        float Arg0        = 0.f;   // Move: LMotor | ArmMove: ArmSpeed
        float Arg1        = 0.f;   // Move: RMotor
        float Duration    = 0.f;
        int32 IArg0       = 0;     // ClawMove: direction (1=open, 0=close)
    };

    UPROPERTY()
    UBaseMovement* BaseMovementComp = nullptr;

    TArray<FRobotAction> ActionQueue;
    int32 QueueIndex = 0;
    float ElapsedTime = 0.f;
    bool bActionStarted = false;

    float GetConfigSpeed() const;
    float GetConfigSize() const;
    void DispatchAction(const FRobotAction& Action);
};
