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

    if(ElapsedTime >= Current.Duration){
        ElapsedTime    = 0.f;
        bActionStarted = false;
        QueueIndex++;
    }
}

void URobotManager::ClearQueue(){
    ActionQueue.Empty();
    QueueIndex    = 0;
    ElapsedTime   = 0.f;
    bActionStarted = false;
}

// ---- helpers ----

float URobotManager::GetConfigSpeed() const{
    return MoveSpeed;
}

float URobotManager::GetConfigSize() const{
    return (MotorSize == EConfigMotorSize::Large) ? LargeMotorSize : SmallMotorSize;
}

void URobotManager::DispatchAction(const FRobotAction& Action){
    if(!BaseMovementComp){return;}

    switch(Action.Type){
        case EActionType::Move:
            BaseMovementComp->StartMove(Action.Arg0, Action.Arg1, Action.Duration, GetConfigSpeed(), GetConfigSize());
            break;
        case EActionType::ArmMove:
            BaseMovementComp->StartArmMove(Action.Arg0, Action.Duration);
            break;
        case EActionType::ClawMove:
            BaseMovementComp->StartClawMove(Action.IArg0, Action.Duration);
            break;
    }
}

// ---- queue methods ----

void URobotManager::QueueStartMove(float LMotor, float RMotor, float Duration){
    FRobotAction A;
    A.Type     = EActionType::Move;
    A.Arg0     = LMotor;
    A.Arg1     = RMotor;
    A.Duration = Duration;
    ActionQueue.Add(A);
}

void URobotManager::QueueStartArmMove(float ArmSpeed, float Duration){
    FRobotAction A;
    A.Type     = EActionType::ArmMove;
    A.Arg0     = ArmSpeed;
    A.Duration = Duration;
    ActionQueue.Add(A);
}

void URobotManager::QueueStartClawMove(int32 Direction, float Duration){
    FRobotAction A;
    A.Type     = EActionType::ClawMove;
    A.IArg0    = Direction;
    A.Duration = Duration;
    ActionQueue.Add(A);
}

void URobotManager::QueueTurnLeft(float Duration){
    // left turn: left motor reverse, right motor forward??
    QueueStartMove(-TurnMotorDiff, TurnMotorDiff, Duration);
}

void URobotManager::QueueTurnRight(float Duration){
    // right turn: left motor forward, right motor reverse??
    QueueStartMove(TurnMotorDiff, -TurnMotorDiff, Duration);
}
