#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RobotPawnBase.generated.h"


UENUM(BlueprintType)
enum class EBaseMoveState : uint8{
    Idle UMETA(DisplayName="Idle"),
    MoveForward UMETA(DisplayName="MoveForward"),
    MoveReverse UMETA(DisplayName="MoveReverse"),
    TurnLeft UMETA(DisplayName="TurnLeft"),
    TurnRight UMETA(DisplayName="TurnRight")
};

UENUM(BlueprintType)
enum class ERobotCommand : uint8{
    MoveForward UMETA(DisplayName="MoveForward"),
    MoveReverse UMETA(DisplayName="MoveReverse"),
    TurnLeft UMETA(DisplayName="TurnLeft"),
    TurnRight UMETA(DisplayName="TurnRight"),
    Cmpnt_Claw_Arm UMETA(DisplayName="Cmpnt_Claw_Arm"),
    Cmpnt_Claw_GrabClaw UMETA(DisplayName="Cmpnt_Claw_GrabClaw"),
    Cmpnt_Lift_Arm UMETA(DisplayName="Cmpnt_Lift_Arm"),
    Cmpnt_Lift_GrabClaw UMETA(DisplayName="Cmpnt_Lift_GrabClaw")
};


UCLASS()
class MOVEMENT_API ARobotPawnBase : public ACharacter{
    GENERATED_BODY()

public:
    ARobotPawnBase();

    // ---- Float state variables ----

    // Interpolation target for arm (0=lowest, 1=highest) — read by Animation Blueprint
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotState")
    float TargetArmAlpha = 0.f;

    // Interpolation target for grab claw (0=closed, 1=open) — read by Animation Blueprint
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotState")
    float TargetClawAlpha = 0.f;

    // Distance (units) the pawn should travel for a MoveForward/MoveReverse command
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotState")
    float TargetMoveDistance = 0.f;

    // Angle (degrees) the pawn should rotate for a TurnLeft/TurnRight command
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotState")
    float TargetTurnAngle = 0.f;

    // Accumulated distance traveled since the current move command was dispatched
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotState")
    float DistanceTraveled = 0.f;

    // Accumulated degrees turned since the current turn command was dispatched
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotState")
    float AngleTurned = 0.f;

    // Elapsed time for the current command — used as fallback timeout for component commands
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotState")
    float CommandTimer = 0.f;

    // Current interpolated arm alpha — written back by Animation Blueprint each frame via FInterpTo
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotState")
    float CurrArmAlpha = 0.f;

    // Current interpolated claw alpha — written back by Animation Blueprint each frame via FInterpTo
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotState")
    float CurrClawAlpha = 0.f;

    // ---- Enum/integer state variables ----

    // Current locomotion state — drives animation blueprint state machine
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotState")
    EBaseMoveState TargetMoveState = EBaseMoveState::Idle;

    // Which manipulator is currently attached (0=None, 1=Claw, 2=Lift)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotState")
    int32 AttachedComponent = 0;

    // Command currently being executed — used by IsCommandCompleted to branch completion logic
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotState")
    ERobotCommand CurrCommand = ERobotCommand::MoveForward;

    // ---- IsCommandCompleted ----
    //   - Increments CommandTimer by DeltaTime then returns true if curr command finished
    //   - For move/turn commands: True if (DistanceTraveled >= TargetMoveDistance) or (AngleTurned >= TargetTurnAngle)
    //   - For component commands: True if (|targetA - currA| < 0.01)  OR  (CommandTimer > 100s)
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="RobotState")
    bool IsCommandCompleted(float DeltaTime);
    virtual bool IsCommandCompleted_Implementation(float DeltaTime);
};
