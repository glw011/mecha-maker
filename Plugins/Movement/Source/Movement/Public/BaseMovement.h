#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/BoxComponent.h"
#include "RobotPawnBase.h"
#include "BaseMovement.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MOVEMENT_API UBaseMovement : public UActorComponent{
    GENERATED_BODY()

public:
    UBaseMovement();

    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    // ---- Command Execution Functions (called by RobotManager) ----

    // Moves robot forward (+distance) or backward (-distance) at MoveSpeed until target reached
    UFUNCTION(BlueprintCallable, Category="RobotCommand")
    void MoveRob(float Distance);

    // Rotates robot left (+degrees, CCW) or right (-degrees, CW) at AngularSpeed until target reached
    UFUNCTION(BlueprintCallable, Category="RobotCommand")
    void TurnRob(float Degrees);

    // Sets TargetArmAlpha on robot for Claw attachment (validates AttachedComponent == 1)
    UFUNCTION(BlueprintCallable, Category="RobotCommand")
    void Claw_Arm(float Alpha);

    // Sets TargetClawAlpha on robot for Claw attachment (validates AttachedComponent == 1)
    UFUNCTION(BlueprintCallable, Category="RobotCommand")
    void Claw_Claw(float Alpha);

    // Sets TargetArmAlpha on robot for Lift attachment (validates AttachedComponent == 2)
    UFUNCTION(BlueprintCallable, Category="RobotCommand")
    void Lift_Arm(float Alpha);

    // Sets TargetClawAlpha on robot for Lift attachment (validates AttachedComponent == 2)
    UFUNCTION(BlueprintCallable, Category="RobotCommand")
    void Lift_Claw(float Alpha);

    // Resets active movement execution states (called by RobotManager::ClearQueue)
    UFUNCTION(BlueprintCallable, Category="RobotCommand")
    void StopMovement();

    // ---- Default Robot Speed Values ----

    // Units (centimeters) per second robot moves during MoveRob execution
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotConfig")
    float MoveSpeed = 300.f;

    // Degrees per second robot rotates during TurnRob execution
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotConfig")
    float AngularSpeed = 90.f;
    
    // Callable function to set robot's move and angular speed based on motor (AngularSpeed = 0.3*MoveSpeed)
    UFUNCTION(BlueprintCallable, Category="RobotConfig")
    void SetMoveSpeed(float InSpeed);

    // ---- Grab Interaction ----

    UPROPERTY()
    AActor* OverlappingObject;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grab")
    UBoxComponent* GrabCollider;

    UFUNCTION()
    void OnGrabOverlap(
        UPrimitiveComponent* OverlappedComp,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex,
        bool bFromSweep,
        const FHitResult& SweepResult
    );

    UFUNCTION()
    void OnGrabEndOverlap(
        UPrimitiveComponent* OverlappedComp,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex
    );

private:
    UPROPERTY()
    ARobotPawnBase* RobotPawn = nullptr;

    // ---- Curr Move State ----
    bool bMoving = false;
    float MoveSign = 1.f;   // +1 = forward, -1 = backward

    // ---- Curr Turn State ----
    bool bTurning = false;
    float TurnSign = 1.f;   // +1 = left (CCW/+Yaw in UE), -1 = right (CW/-Yaw in UE)

    void TryGrab();
    void ReleaseGrab();
};
