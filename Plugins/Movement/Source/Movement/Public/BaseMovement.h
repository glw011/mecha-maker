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

    // ---- Command execution functions (called by RobotManager on dequeue) ----

    // Move pawn forward (+distance) or backward (-distance) at MoveSpeed until target reached
    UFUNCTION(BlueprintCallable, Category="RobotCommand")
    void MoveRob(float Distance);

    // Rotate pawn left (+degrees, CCW) or right (-degrees, CW) at AngularSpeed until target reached
    UFUNCTION(BlueprintCallable, Category="RobotCommand")
    void TurnRob(float Degrees);

    // Set TargetArmAlpha on pawn for Claw attachment (validates AttachedComponent == 1)
    UFUNCTION(BlueprintCallable, Category="RobotCommand")
    void Claw_Arm(float Alpha);

    // Set TargetClawAlpha on pawn for Claw attachment (validates AttachedComponent == 1)
    UFUNCTION(BlueprintCallable, Category="RobotCommand")
    void Claw_Claw(float Alpha);

    // Set TargetArmAlpha on pawn for Lift attachment (validates AttachedComponent == 2)
    UFUNCTION(BlueprintCallable, Category="RobotCommand")
    void Lift_Arm(float Alpha);

    // Set TargetClawAlpha on pawn for Lift attachment (validates AttachedComponent == 2)
    UFUNCTION(BlueprintCallable, Category="RobotCommand")
    void Lift_Claw(float Alpha);

    // Reset all active movement execution state (called by RobotManager::ClearQueue)
    UFUNCTION(BlueprintCallable, Category="RobotCommand")
    void StopMovement();

    // ---- Movement speed constants ----

    // Units per second the pawn moves during MoveRob execution
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotConfig")
    float MoveSpeed = 400.f;

    // Degrees per second the pawn rotates during TurnRob execution
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RobotConfig")
    float AngularSpeed = 90.f;

    // ---- Grab interaction ----

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

    // ---- curr move state ----
    bool bMoving = false;
    float MoveSign = 1.f;   // +1 = forward, -1 = backward

    // ---- curr turn state ----
    bool bTurning = false;
    float TurnSign = 1.f;   // +1 = left (CCW/+Yaw in UE), -1 = right (CW/-Yaw in UE)

    void TryGrab();
    void ReleaseGrab();
};
