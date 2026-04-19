#include "RobotManager.h"
#include "BaseMovement.h"


URobotManager::URobotManager(){
    PrimaryComponentTick.bCanEverTick = true;
}

void URobotManager::BeginPlay(){
    Super::BeginPlay();

    if(AActor* Owner = GetOwner()){
        BaseMovementComp = Owner->FindComponentByClass<UBaseMovement>();
        if(!BaseMovementComp){
            UE_LOG(LogTemp, Warning, TEXT("URobotManager: no UBaseMovement found on owner '%s'"), *Owner->GetName());
        }
    }
}

void URobotManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction){
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if(!BaseMovementComp || ActionQueue.Num() == 0 || QueueIndex >= ActionQueue.Num()){return;}

    const FRobotAction& Current = ActionQueue[QueueIndex];

    if(!bActionStarted){
        DispatchAction(Current);
        bActionStarted = true;
    }

    ElapsedTime += DeltaTime;

    if(ElapsedTime >= GetActionWaitTime(Current.Type, Current.Duration)){
        ElapsedTime    = 0.f;
        bActionStarted = false;
        QueueIndex++;
    }
}

// --- Config ---

void URobotManager::SetCurrConfig(int32 InMotorType, int32 InManipSlot){
    MotorType = (InMotorType == 1) ? EMotorType::HiSpeedLoTorque : EMotorType::Balanced;
    ManipType = (InManipSlot == 1) ? EManipType::Lift : EManipType::Claw;
}


void URobotManager::ClearQueue(){
    ActionQueue.Empty();
    QueueIndex    = 0;
    ElapsedTime   = 0.f;
    bActionStarted = false;
    // Reset binary states to initial positions so each new run starts clean
    bArmIsUp    = true;
    bClawIsOpen = false;
    bLiftIsUp   = false;
}

float URobotManager::GetConfigSize() const{
    return (MotorType == EMotorType::HiSpeedLoTorque) ? HiSpeedMotorSize : BalancedMotorSize;
}

float URobotManager::GetActionWaitTime(EActionType ActionType, float Duration) const{
    // Returns the time (seconds) to wait after dispatching this action before moving to the next.
    // Currently equals the action's own Duration; future implementations may scale by config.
    return Duration;
}

void URobotManager::DispatchAction(const FRobotAction& Action){
    if(!BaseMovementComp){return;}

    switch(Action.Type){
        case EActionType::Move:
            BaseMovementComp->StartMove(Action.Arg0, Action.Arg1, Action.Duration, MoveSpeed, GetConfigSize());
            break;
        case EActionType::ArmMove:
            BaseMovementComp->StartArmMove(Action.Arg0, Action.Duration);
            break;
        case EActionType::ClawMove:
            BaseMovementComp->StartClawMove(Action.IArg0, Action.Duration);
            break;
        case EActionType::LiftMove:
            BaseMovementComp->StartLiftMove(Action.IArg0, Action.Duration);
            break;
    }
}

// ---- Enqueue Functions (add user's ComponentFunction to queue) ----

void URobotManager::EnqueueMoveForward(float Duration){
    FRobotAction A;
    A.Type     = EActionType::Move;
    A.Arg0     = 100.f;
    A.Arg1     = 100.f;
    A.Duration = Duration;
    ActionQueue.Add(A);
}

void URobotManager::EnqueueMoveBackward(float Duration){
    FRobotAction A;
    A.Type     = EActionType::Move;
    A.Arg0     = -100.f;
    A.Arg1     = -100.f;
    A.Duration = Duration;
    ActionQueue.Add(A);
}

void URobotManager::EnqueueTurnLeft(float Duration){
    FRobotAction A;
    A.Type     = EActionType::Move;
    A.Arg0     = -TurnMotorDiff;
    A.Arg1     =  TurnMotorDiff;
    A.Duration = Duration;
    ActionQueue.Add(A);
}

void URobotManager::EnqueueTurnRight(float Duration){
    FRobotAction A;
    A.Type     = EActionType::Move;
    A.Arg0     =  TurnMotorDiff;
    A.Arg1     = -TurnMotorDiff;
    A.Duration = Duration;
    ActionQueue.Add(A);
}

void URobotManager::EnqueueRaiseArm(){
    if(bArmIsUp){return;}
    FRobotAction A;
    A.Type     = EActionType::ArmMove;
    A.Arg0     = -ArmRotationAmount;  // negative = counter-clockwise = up ??
    A.Duration = RaiseArmDuration;
    ActionQueue.Add(A);
    bArmIsUp = true;
}

void URobotManager::EnqueueLowerArm(){
    if(!bArmIsUp){return;}
    FRobotAction A;
    A.Type     = EActionType::ArmMove;
    A.Arg0     = ArmRotationAmount;   // positive = clockwise = down ??
    A.Duration = LowerArmDuration;
    ActionQueue.Add(A);
    bArmIsUp = false;
}

void URobotManager::EnqueueOpenClaw(){
    if(bClawIsOpen){return;}
    FRobotAction A;
    A.Type     = EActionType::ClawMove;
    A.IArg0    = 1;   // 1 = open
    A.Duration = OpenClawDuration;
    ActionQueue.Add(A);
    bClawIsOpen = true;
}

void URobotManager::EnqueueCloseClaw(){
    if(!bClawIsOpen){return;}
    FRobotAction A;
    A.Type     = EActionType::ClawMove;
    A.IArg0    = 0;   // 0 = close
    A.Duration = CloseClawDuration;
    ActionQueue.Add(A);
    bClawIsOpen = false;
}

void URobotManager::EnqueueRaiseLift(){
    if(bLiftIsUp){return;}
    FRobotAction A;
    A.Type     = EActionType::LiftMove;
    A.IArg0    = 1;   // 1 = raise
    A.Duration = RaiseLiftDuration;
    ActionQueue.Add(A);
    bLiftIsUp = true;
}

void URobotManager::EnqueueLowerLift(){
    if(!bLiftIsUp){return;}
    FRobotAction A;
    A.Type     = EActionType::LiftMove;
    A.IArg0    = 0;   // 0 = lower
    A.Duration = LowerLiftDuration;
    ActionQueue.Add(A);
    bLiftIsUp = false;
}
