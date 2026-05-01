#include "RobotManager.h"
#include "BaseMovement.h"


URobotManager::URobotManager(){
    PrimaryComponentTick.bCanEverTick = true;
}

void URobotManager::BeginPlay(){
    Super::BeginPlay();

    RobotPawn = Cast<ARobotPawnBase>(GetOwner());
    if(!RobotPawn){
        UE_LOG(LogTemp, Warning, TEXT("URobotManager: owner is not an ARobotPawnBase — commands will not execute"));
    }

    if(AActor* Owner = GetOwner()){
        BaseMovementComp = Owner->FindComponentByClass<UBaseMovement>();
        if(!BaseMovementComp){
            UE_LOG(LogTemp, Warning, TEXT("URobotManager: no UBaseMovement found on owner '%s'"), *Owner->GetName());
        }
    }
}

void URobotManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction){
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if(!RobotPawn || !BaseMovementComp) return;

    // Nothing queued — idle
    if(QueueIndex >= ActionQueue.Num()) return;

    if(CanExecuteCommand){
        // ---- Dequeue and dispatch next command ----
        const FRobotAction& Action = ActionQueue[QueueIndex];

        CanExecuteCommand = false;

        // Reset per-command pawn state before dispatch
        RobotPawn->DistanceTraveled = 0.f;
        RobotPawn->AngleTurned = 0.f;
        RobotPawn->CommandTimer = 0.f;

        LastTick = GetWorld()->GetTimeSeconds();

        DispatchAction(Action);
        QueueIndex++;
    }
    else{
        // ---- Poll completion of the running command ----
        CurrTick = GetWorld()->GetTimeSeconds();
        float Delta = CurrTick - LastTick;
        LastTick = CurrTick;

        CanExecuteCommand = RobotPawn->IsCommandCompleted(Delta);

        if(CanExecuteCommand){
            // Return loco state to Idle for movement commands
            ERobotCommand Cmd = RobotPawn->CurrCommand;
            if(Cmd == ERobotCommand::MoveForward || Cmd == ERobotCommand::MoveReverse || Cmd == ERobotCommand::TurnLeft    || Cmd == ERobotCommand::TurnRight){
                RobotPawn->TargetMoveState = EBaseMoveState::Idle;
            }
        }
    }
}

// ---- Config ----

void URobotManager::SetCurrConfig(int32 InMotorType, int32 InManipSlot){
    MotorType = (InMotorType == 1) ? EMotorType::HiSpeedLoTorque : EMotorType::Balanced;
    ManipType = (InManipSlot == 1) ? EManipType::Lift : EManipType::Claw;
}

// ---- Queue management ----

void URobotManager::ClearQueue(){
    ActionQueue.Empty();
    QueueIndex        = 0;
    CanExecuteCommand = true;

    if(RobotPawn){
        RobotPawn->DistanceTraveled = 0.f;
        RobotPawn->AngleTurned = 0.f;
        RobotPawn->CommandTimer = 0.f;
        RobotPawn->TargetMoveState = EBaseMoveState::Idle;
    }

    if(BaseMovementComp){
        BaseMovementComp->StopMovement();
    }
}

// ---- Dispatch ----

void URobotManager::DispatchAction(const FRobotAction& Action){
    if(!RobotPawn || !BaseMovementComp) return;

    switch(Action.Type){

        case EActionType::MoveRob:
            if(Action.Arg0 >= 0.f){
                RobotPawn->CurrCommand = ERobotCommand::MoveForward;
                RobotPawn->TargetMoveState = EBaseMoveState::MoveForward;
                RobotPawn->TargetMoveDistance = Action.Arg0;
            } else {
                RobotPawn->CurrCommand = ERobotCommand::MoveReverse;
                RobotPawn->TargetMoveState = EBaseMoveState::MoveReverse;
                RobotPawn->TargetMoveDistance = FMath::Abs(Action.Arg0);
            }
            BaseMovementComp->MoveRob(Action.Arg0);
            break;

        case EActionType::TurnRob:
            if(Action.Arg0 >= 0.f){
                RobotPawn->CurrCommand = ERobotCommand::TurnLeft;
                RobotPawn->TargetMoveState = EBaseMoveState::TurnLeft;
                RobotPawn->TargetTurnAngle = Action.Arg0;
            } else {
                RobotPawn->CurrCommand = ERobotCommand::TurnRight;
                RobotPawn->TargetMoveState = EBaseMoveState::TurnRight;
                RobotPawn->TargetTurnAngle = FMath::Abs(Action.Arg0);
            }
            BaseMovementComp->TurnRob(Action.Arg0);
            break;

        case EActionType::ClawArm:
            RobotPawn->CurrCommand = ERobotCommand::Cmpnt_Claw_Arm;
            BaseMovementComp->Claw_Arm(Action.Arg0);
            break;

        case EActionType::ClawClaw:
            RobotPawn->CurrCommand = ERobotCommand::Cmpnt_Claw_GrabClaw;
            BaseMovementComp->Claw_Claw(Action.Arg0);
            break;

        case EActionType::LiftArm:
            RobotPawn->CurrCommand = ERobotCommand::Cmpnt_Lift_Arm;
            BaseMovementComp->Lift_Arm(Action.Arg0);
            break;

        case EActionType::LiftClaw:
            RobotPawn->CurrCommand = ERobotCommand::Cmpnt_Lift_GrabClaw;
            BaseMovementComp->Lift_Claw(Action.Arg0);
            break;
    }
}

// ---- Enqueue functions ----

void URobotManager::EnqueueMoveForward(float Distance){
    ActionQueue.Add({EActionType::MoveRob, Distance});
}

void URobotManager::EnqueueMoveBackward(float Distance){
    ActionQueue.Add({EActionType::MoveRob, -Distance});  // neg -> backward
}

void URobotManager::EnqueueTurnLeft(float Degrees){
    ActionQueue.Add({EActionType::TurnRob, Degrees});    // pos -> CCW/turnLeft
}

void URobotManager::EnqueueTurnRight(float Degrees){
    ActionQueue.Add({EActionType::TurnRob, -Degrees});   // neg -> CW/turnRight
}

void URobotManager::EnqueueClawRaiseArm(){
    ActionQueue.Add({EActionType::ClawArm, 1.f});
}

void URobotManager::EnqueueClawLowerArm(){
    ActionQueue.Add({EActionType::ClawArm, 0.f});
}

void URobotManager::EnqueueClawOpenClaw(){
    ActionQueue.Add({EActionType::ClawClaw, 1.f});
}

void URobotManager::EnqueueClawCloseClaw(){
    ActionQueue.Add({EActionType::ClawClaw, 0.f});
}

void URobotManager::EnqueueLiftRaiseArm(){
    ActionQueue.Add({EActionType::LiftArm, 1.f});
}

void URobotManager::EnqueueLiftLowerArm(){
    ActionQueue.Add({EActionType::LiftArm, 0.f});
}

void URobotManager::EnqueueLiftOpenClaw(){
    ActionQueue.Add({EActionType::LiftClaw, 1.f});
}

void URobotManager::EnqueueLiftCloseClaw(){
    ActionQueue.Add({EActionType::LiftClaw, 0.f});
}
