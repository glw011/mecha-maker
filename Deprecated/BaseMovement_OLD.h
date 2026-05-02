#pragma once

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Components/BoxComponent.h"
#include "Components/MeshComponent.h"

#include "Animation/AnimSequence.h"
#include "GameFramework/Character.h"
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

    UFUNCTION(BlueprintCallable)
    void StartArmMove(float InDir, float FlArmDuration);

    UFUNCTION(BlueprintCallable)
    void StartClawMove(int32 InDir, float FlArmDuration);

    // Added so I can finish RobotManager (currently an empty function with no logic)
    UFUNCTION(BlueprintCallable)
    void StartLiftMove(int32 InDir, float LiftDuration);

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
        UPrimitiveComponent* OVerlappedComp,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex
    );


private:
    ACharacter* Character;

    USkeletalMeshComponent* ArmMesh;
    USkeletalMeshComponent* ClawMesh;

    // Might be able to delete these
    USkeletalMeshComponent* ClawMeshRight;
    USkeletalMeshComponent* ClawMeshLeft;
    
    // DELETE THIS IF STILL NOT SHOW UP
    UMeshComponent* ClawGuide;

    USkeletalMeshComponent* LiftMesh;

    UPROPERTY(EditAnywhere, Category = "Animation")
    UAnimSequence* LiftAnim;

    float LiftCurrentPos;
    float LiftTargetPos;
    float LiftDur;
    float LiftTime;
    bool bIsLiftMoving;

    void ExecuteLiftMovement(float DeltaTime);

    // Main Robot Move Vars
    float LeftMotor;
    float RightMotor;
    float Duration;
    float Speed;

    bool bIsMoving;

    void ExecuteMovement(float DeltaTime);

    // Turning vars
    float StartYaw;
    float FinishedYaw;
    float CurrentTime;
    float AngularSpeed;

    // Arm Vars
    UPROPERTY(EditAnywhere, Category = "Animation")
    UAnimSequence* ArmAnim;

    //float ArmSpeed;
    float ArmCurrent;
    float ArmDur;
    float ArmTime;

    float ArmCurrentPos;
    float ArmTargetPos;

    bool bIsMovingArm;

    void ExecuteArmMovement(float DeltaTime);

    // Claw Vars
    UPROPERTY(EditAnywhere, Category = "Animation")
    UAnimSequence* ClawAnim;

    float ClawCurrentRight;
    float ClawCurrentLeft;
    float ClawDur;
    float ClawTime;

    float ClawCurrentPos;
    float ClawTargetPos;

    bool bIsOpenClaw;
    bool bIsCloseClaw;

    void ExecuteOpenClaw(float DeltaTime);
    void ExecuteCloseClaw(float DeltaTime);

    void TryGrab();
    void ReleaseGrab();

};