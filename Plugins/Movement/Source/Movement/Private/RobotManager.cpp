#include "RobotManager.h"
#include "BaseMovement.h"

DEFINE_LOG_CATEGORY_STATIC(RobotManagerLog, Log, All);


URobotManager::URobotManager(){
    PrimaryComponentTick.bCanEverTick = true;
}

void URobotManager::BeginPlay(){
    Super::BeginPlay();

    RobotPawn = Cast<ARobotPawnBase>(GetOwner());
    UE_LOG(RobotManagerLog, Warning, TEXT("[DBG] RobotManager BeginPlay — RobotPawn is %s"), RobotPawn ? TEXT("VALID") : TEXT("NULL (owner is not ARobotPawnBase)"));

    if(!RobotPawn){
        UE_LOG(RobotManagerLog, Error, TEXT("[DBG] Owner class: %s"), GetOwner() ? *GetOwner()->GetClass()->GetName() : TEXT("(no owner)"));
        return;
    }

    BaseMovementComp = RobotPawn->BaseMovementComp;
    UE_LOG(RobotManagerLog, Warning, TEXT("[DBG] RobotManager BeginPlay — BaseMovementComp is %s"), BaseMovementComp ? TEXT("VALID") : TEXT("NULL (BaseMovementComp not found on pawn)"));
}

void URobotManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction){
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    static int32 TickCount = 0;
    if(TickCount < 3){
        UE_LOG(RobotManagerLog, Warning,
            TEXT("[DBG] RobotManager Tick #%d — RobotPawn=%s BaseMovementComp=%s CanExec=%s QueueIdx=%d QueueSize=%d"),
            TickCount,
            RobotPawn        ? TEXT("valid") : TEXT("NULL"),
            BaseMovementComp ? TEXT("valid") : TEXT("NULL"),
            CanExecuteCommand ? TEXT("true") : TEXT("false"),
            QueueIndex, ActionQueue.Num());
        ++TickCount;
    }

    if(!RobotPawn || !BaseMovementComp){
        static bool bNullGuardLogged = false;
        if(!bNullGuardLogged){
            UE_LOG(RobotManagerLog, Error,
                TEXT("[DBG] Tick null-guard triggered every frame — RobotPawn=%s BaseMovementComp=%s"),
                RobotPawn        ? TEXT("valid") : TEXT("NULL"),
                BaseMovementComp ? TEXT("valid") : TEXT("NULL"));
            bNullGuardLogged = true;
        }
        return;
    }

    if(CanExecuteCommand){
        if(QueueIndex >= ActionQueue.Num()){return;}

        const FRobotAction& Action = ActionQueue[QueueIndex];
        UE_LOG(RobotManagerLog, Warning,
            TEXT("[DBG] Dispatching action — Type=%d Arg0=%.2f (QueueIdx=%d of %d)"),
            (int)Action.Type, Action.Arg0, QueueIndex, ActionQueue.Num());

        CanExecuteCommand = false;

        RobotPawn->DistanceTraveled = 0.f;
        RobotPawn->AngleTurned      = 0.f;
        RobotPawn->CommandTimer     = 0.f;

        LastTick = GetWorld()->GetTimeSeconds();

        DispatchAction(Action);
        QueueIndex++;
    }
    else{
        CurrTick = GetWorld()->GetTimeSeconds();
        float Delta = CurrTick - LastTick;
        LastTick = CurrTick;

        bool bDone = RobotPawn->IsCommandCompleted(Delta);

        if(bDone && !CanExecuteCommand){
            UE_LOG(RobotManagerLog, Warning, TEXT("[DBG] IsCommandCompleted returned true — command finished"));
        }

        CanExecuteCommand = bDone;

        if(CanExecuteCommand){
            ERobotCommand Cmd = RobotPawn->CurrCommand;
            if(Cmd == ERobotCommand::MoveForward || Cmd == ERobotCommand::MoveReverse || Cmd == ERobotCommand::TurnLeft || Cmd == ERobotCommand::TurnRight){
                RobotPawn->TargetMoveState = EBaseMoveState::Idle;
                UE_LOG(RobotManagerLog, Warning, TEXT("[DBG] TargetMoveState reset to Idle"));
            }
        }
    }
}

// ---- Config ----

void URobotManager::SetCurrConfig(int32 InMotorType, int32 InManipSlot){
    MotorType = (InMotorType == 1) ? EMotorType::HiSpeedLoTorque : EMotorType::Balanced;
    ManipType = (InManipSlot == 1) ? EManipType::Lift : EManipType::Claw;
    if(InManipSlot == 2){
        ManipType = EManipType::Lift;
    }
    else if(InManipSlot == 1){
        ManipType = EManipType::Claw;
    }
    else{ManipType = EManipType::None;}
}

// ---- Queue management ----

void URobotManager::ClearQueue(){
    UE_LOG(RobotManagerLog, Warning,
        TEXT("[DBG] ClearQueue called — had %d actions, QueueIdx was %d"), ActionQueue.Num(), QueueIndex);

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
    if(!RobotPawn || !BaseMovementComp){
        UE_LOG(RobotManagerLog, Error, TEXT("[DBG] DispatchAction early-return — RobotPawn=%s BaseMovementComp=%s"),
            RobotPawn ? TEXT("valid") : TEXT("NULL"),
            BaseMovementComp ? TEXT("valid") : TEXT("NULL"));
        return;
    }

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
            UE_LOG(RobotManagerLog, Warning,
                TEXT("[DBG] DispatchAction MoveRob — TargetMoveState set to %d (0=Idle 1=Fwd 2=Rev), dist=%.2f"),
                (int)RobotPawn->TargetMoveState, RobotPawn->TargetMoveDistance);
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
            UE_LOG(RobotManagerLog, Warning,
                TEXT("[DBG] DispatchAction TurnRob — TargetMoveState set to %d (3=Left 4=Right), deg=%.2f"),
                (int)RobotPawn->TargetMoveState, RobotPawn->TargetTurnAngle);
            BaseMovementComp->TurnRob(Action.Arg0);
            break;

        case EActionType::ClawArm:
            UE_LOG(RobotManagerLog, Warning, TEXT("[DBG] DispatchAction → Claw_Arm(%.2f)"), Action.Arg0);
            RobotPawn->CurrCommand = ERobotCommand::Cmpnt_Claw_Arm;
            BaseMovementComp->Claw_Arm(Action.Arg0);
            break;

        case EActionType::ClawClaw:
            UE_LOG(RobotManagerLog, Warning, TEXT("[DBG] DispatchAction → Claw_Claw(%.2f)"), Action.Arg0);
            RobotPawn->CurrCommand = ERobotCommand::Cmpnt_Claw_GrabClaw;
            BaseMovementComp->Claw_Claw(Action.Arg0);
            break;

        case EActionType::LiftArm:
            UE_LOG(RobotManagerLog, Warning, TEXT("[DBG] DispatchAction → Lift_Arm(%.2f)"), Action.Arg0);
            RobotPawn->CurrCommand = ERobotCommand::Cmpnt_Lift_Arm;
            BaseMovementComp->Lift_Arm(Action.Arg0);
            break;

        case EActionType::LiftClaw:
            UE_LOG(RobotManagerLog, Warning, TEXT("[DBG] DispatchAction → Lift_Claw(%.2f)"), Action.Arg0);
            RobotPawn->CurrCommand = ERobotCommand::Cmpnt_Lift_GrabClaw;
            BaseMovementComp->Lift_Claw(Action.Arg0);
            break;
    }
}

// ---- Enqueue functions ----

void URobotManager::EnqueueMoveForward(float Distance){
    ActionQueue.Add({EActionType::MoveRob, Distance});
    UE_LOG(RobotManagerLog, Warning, TEXT("[DBG] EnqueueMoveForward(%.2f) — queue size now %d"), Distance, ActionQueue.Num());
}

void URobotManager::EnqueueMoveBackward(float Distance){
    ActionQueue.Add({EActionType::MoveRob, -Distance});
    UE_LOG(RobotManagerLog, Warning, TEXT("[DBG] EnqueueMoveBackward(%.2f) — queue size now %d"), Distance, ActionQueue.Num());
}

void URobotManager::EnqueueTurnLeft(float Degrees){
    ActionQueue.Add({EActionType::TurnRob, Degrees});
    UE_LOG(RobotManagerLog, Warning, TEXT("[DBG] EnqueueTurnLeft(%.2f) — queue size now %d"), Degrees, ActionQueue.Num());
}

void URobotManager::EnqueueTurnRight(float Degrees){
    ActionQueue.Add({EActionType::TurnRob, -Degrees});
    UE_LOG(RobotManagerLog, Warning, TEXT("[DBG] EnqueueTurnRight(%.2f) — queue size now %d"), Degrees, ActionQueue.Num());
}

void URobotManager::EnqueueClawRaiseArm(){
    ActionQueue.Add({EActionType::ClawArm, 1.f});
    UE_LOG(RobotManagerLog, Warning, TEXT("[DBG] EnqueueClawRaiseArm — queue size now %d"), ActionQueue.Num());
}

void URobotManager::EnqueueClawLowerArm(){
    ActionQueue.Add({EActionType::ClawArm, 0.f});
    UE_LOG(RobotManagerLog, Warning, TEXT("[DBG] EnqueueClawLowerArm — queue size now %d"), ActionQueue.Num());
}

void URobotManager::EnqueueClawOpenClaw(){
    ActionQueue.Add({EActionType::ClawClaw, 1.f});
    UE_LOG(RobotManagerLog, Warning, TEXT("[DBG] EnqueueClawOpenClaw — queue size now %d"), ActionQueue.Num());
}

void URobotManager::EnqueueClawCloseClaw(){
    ActionQueue.Add({EActionType::ClawClaw, 0.f});
    UE_LOG(RobotManagerLog, Warning, TEXT("[DBG] EnqueueClawCloseClaw — queue size now %d"), ActionQueue.Num());
}

void URobotManager::EnqueueLiftRaiseArm(){
    ActionQueue.Add({EActionType::LiftArm, 1.f});
    UE_LOG(RobotManagerLog, Warning, TEXT("[DBG] EnqueueLiftRaiseArm — queue size now %d"), ActionQueue.Num());
}

void URobotManager::EnqueueLiftLowerArm(){
    ActionQueue.Add({EActionType::LiftArm, 0.f});
    UE_LOG(RobotManagerLog, Warning, TEXT("[DBG] EnqueueLiftLowerArm — queue size now %d"), ActionQueue.Num());
}

void URobotManager::EnqueueLiftOpenClaw(){
    ActionQueue.Add({EActionType::LiftClaw, 1.f});
    UE_LOG(RobotManagerLog, Warning, TEXT("[DBG] EnqueueLiftOpenClaw — queue size now %d"), ActionQueue.Num());
}

void URobotManager::EnqueueLiftCloseClaw(){
    ActionQueue.Add({EActionType::LiftClaw, 0.f});
    UE_LOG(RobotManagerLog, Warning, TEXT("[DBG] EnqueueLiftCloseClaw — queue size now %d"), ActionQueue.Num());
}
