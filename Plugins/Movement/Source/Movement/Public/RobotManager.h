#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RobotPawnBase.h"
#include "RobotManager.generated.h"

class UBaseMovement;

// Reserved for future differential steering (FourWheel vs TankTread turn calculations)
UENUM(BlueprintType)
enum class EConfigDriveType : uint8{
    FourWheel UMETA(DisplayName="Four Wheel"),
    TankTread UMETA(DisplayName="Tank Tread")
};

UENUM(BlueprintType)
enum class EMotorType : uint8{
    Balanced UMETA(DisplayName="Balanced"),
    HiSpeedLoTorque UMETA(DisplayName="Hi-Speed / Lo-Torque")
};

UENUM(BlueprintType)
enum class EManipType : uint8{
    Claw UMETA(DisplayName="Claw"),
    Lift UMETA(DisplayName="Lift"),
    None UMETA(DisplayName="None")
};


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MOVEMENT_API URobotManager : public UActorComponent{
    GENERATED_BODY()

public:
    URobotManager();

    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    // ---- Robot Config ----

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotConfig")
    EMotorType MotorType = EMotorType::Balanced;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotConfig")
    EManipType ManipType = EManipType::Claw;

    UFUNCTION(BlueprintCallable, Category="RobotConfig")
    void SetCurrConfig(int32 InMotorType, int32 InManipSlot);

    // ---- Component Function Enqueue API ----
    // Called by RobotComponentInterface::Dispatch when interpreter encounters these calls

    void EnqueueMoveForward(float Distance);
    void EnqueueMoveBackward(float Distance);   // stored as negative distance -> MoveRob(-distance)
    void EnqueueTurnLeft(float Degrees);
    void EnqueueTurnRight(float Degrees);       // stored as negative degrees -> TurnRob(-degrees)
    void EnqueueClawRaiseArm();
    void EnqueueClawLowerArm();
    void EnqueueClawOpenClaw();
    void EnqueueClawCloseClaw();
    void EnqueueLiftRaiseArm();
    void EnqueueLiftLowerArm();
    void EnqueueLiftOpenClaw();
    void EnqueueLiftCloseClaw();

    UFUNCTION(BlueprintCallable, Category="Robot")
    void ClearQueue();

private:
    // Action types mapped to 6 BaseMovement execution functions
    enum class EActionType : uint8{ MoveRob, TurnRob, ClawArm, ClawClaw, LiftArm, LiftClaw };

    struct FRobotAction{
        EActionType Type = EActionType::MoveRob;
        float Arg0 = 0.f;
    };

    UPROPERTY()
    ARobotPawnBase* RobotPawn = nullptr;

    UPROPERTY()
    UBaseMovement* BaseMovementComp = nullptr;

    TArray<FRobotAction> ActionQueue;
    int32 QueueIndex = 0;
    bool CanExecuteCommand = true;  // true = queue idle, ready to dispatch next command

    // tick timing to track seconds for DeltaTime passed to IsCommandCompleted
    float LastTick = 0.f;
    float CurrTick = 0.f;

    void DispatchAction(const FRobotAction& Action);
};
