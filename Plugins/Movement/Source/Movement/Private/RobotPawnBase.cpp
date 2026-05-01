#include "RobotPawnBase.h"
#include "BaseMovement.h"
#include "GameFramework/CharacterMovementComponent.h"


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
