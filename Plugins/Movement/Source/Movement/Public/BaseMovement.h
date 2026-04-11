#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseMovement.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MOVEMENT_API UBaseMovement : public UActorComponent
{
    GENERATED_BODY()

public:
    UBaseMovement();

    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    // Start movement
    UFUNCTION(BlueprintCallable)
    void StartMove(float FlLeftMotor, float FlRightMotor, float FlDuration, float FlSpeed, float FlSize);

    // Manipulator Movement
    UFUNCTION(BlueprintCallable)
    void MoveClaw(float FlPower, float FlSpeed, float FlDuration, bool ClawCheck);

    UFUNCTION(BlueprintCallable)
    void MoveLift(float FlPower, float FlSpeed, float FlDuration, bool LiftCheck);

private:
    ACharacter* Character;

    float LeftMotor;
    float RightMotor;
    float Duration;
    float Speed;

    float StartYaw;
    float FinishedYaw;
    float CurrentTime;

    float AngularSpeed;

    bool bIsMoving;

    void ExecuteMovement(float DeltaTime);
};