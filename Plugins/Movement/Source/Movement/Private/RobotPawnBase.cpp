#include "RobotPawnBase.h"
#include "BaseMovement.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"


ARobotPawnBase::ARobotPawnBase(){
    PrimaryActorTick.bCanEverTick = false;
    BaseMovementComp = CreateDefaultSubobject<UBaseMovement>(TEXT("BaseMovement"));

    bUseControllerRotationYaw   = false;
    bUseControllerRotationPitch = false;
    bUseControllerRotationRoll  = false;

    if(UCharacterMovementComponent* CMC = GetCharacterMovement()){
        CMC->bOrientRotationToMovement    = false;
        CMC->bUseControllerDesiredRotation = false;
    }

    // CapsuleComponent is the root — its center IS the actor origin.
    // CMC places the capsule bottom on the floor, so the actor origin sits
    // HalfHeight units above the floor at spawn. Offset the mesh down by the
    // same amount so the wheel contact point aligns with the floor surface.
    // NOTE: in the BP viewport the mesh will appear below the preview grid by
    // this amount — that is expected and correct for ACharacter floor alignment.
    const float CapsuleHalfHeight = 5.0f;
    GetCapsuleComponent()->InitCapsuleSize(GetCapsuleComponent()->GetUnscaledCapsuleRadius(), CapsuleHalfHeight);
    GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -CapsuleHalfHeight));
}

void ARobotPawnBase::TryGrab_Implementation(){
    if(BaseMovementComp) BaseMovementComp->TryGrab();
}

void ARobotPawnBase::TryRelease_Implementation(){
    if(BaseMovementComp) BaseMovementComp->ReleaseGrab();
}

bool ARobotPawnBase::IsCommandCompleted_Implementation(float DeltaTime){
    CommandTimer += DeltaTime;

    switch(CurrCommand){
        case ERobotCommand::MoveForward:
        case ERobotCommand::MoveReverse:
            return DistanceTraveled >= TargetMoveDistance;

        case ERobotCommand::TurnLeft:
        case ERobotCommand::TurnRight:
            return AngleTurned >= TargetTurnAngle;

        case ERobotCommand::Cmpnt_Claw_Arm:
        case ERobotCommand::Cmpnt_Lift_Arm:
            if(CommandTimer > 100.f) return true;
            return FMath::Abs(TargetArmAlpha - CurrArmAlpha) < 0.01f;

        case ERobotCommand::Cmpnt_Claw_GrabClaw:
        case ERobotCommand::Cmpnt_Lift_GrabClaw:
            if(CommandTimer > 100.f) return true;
            return FMath::Abs(TargetClawAlpha - CurrClawAlpha) < 0.01f;
    }

    return false;
}
