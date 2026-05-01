#include "BaseMovement.h"
#include "Components/PrimitiveComponent.h"


UBaseMovement::UBaseMovement(){
    PrimaryComponentTick.bCanEverTick = true;
    GrabCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("GrabCollider"));
}

void UBaseMovement::BeginPlay(){
    Super::BeginPlay();

    RobotPawn = Cast<ARobotPawnBase>(GetOwner());
    if(!RobotPawn){
        UE_LOG(LogTemp, Warning, TEXT("UBaseMovement: owner is not an ARobotPawnBase — movement will not function"));
    }

    if(GrabCollider){
        GrabCollider->OnComponentBeginOverlap.AddDynamic(this, &UBaseMovement::OnGrabOverlap);
        GrabCollider->OnComponentEndOverlap.AddDynamic(this, &UBaseMovement::OnGrabEndOverlap);
        GrabCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
        GrabCollider->SetGenerateOverlapEvents(true);
        GrabCollider->SetCollisionResponseToAllChannels(ECR_Overlap);
        GrabCollider->SetBoxExtent(FVector(30.f, 30.f, 30.f));
    }
}

void UBaseMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction){
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if(!RobotPawn) return;

    // ---- Execute active move command ----
    if(bMoving){
        float Remaining = RobotPawn->TargetMoveDistance - RobotPawn->DistanceTraveled;
        float Step = FMath::Min(MoveSpeed * DeltaTime, Remaining);

        FVector NewLoc = RobotPawn->GetActorLocation() + RobotPawn->GetActorForwardVector() * MoveSign * Step;
        RobotPawn->SetActorLocation(NewLoc);
        RobotPawn->DistanceTraveled += Step;

        if(RobotPawn->DistanceTraveled >= RobotPawn->TargetMoveDistance){
            RobotPawn->DistanceTraveled = RobotPawn->TargetMoveDistance;
            bMoving = false;
        }
    }

    // ---- Execute active turn command ----
    if(bTurning){
        float Remaining = RobotPawn->TargetTurnAngle - RobotPawn->AngleTurned;
        float Step = FMath::Min(AngularSpeed * DeltaTime, Remaining);

        FRotator NewRot = RobotPawn->GetActorRotation();
        NewRot.Yaw += TurnSign * Step;
        RobotPawn->SetActorRotation(NewRot);
        RobotPawn->AngleTurned += Step;

        if(RobotPawn->AngleTurned >= RobotPawn->TargetTurnAngle){
            RobotPawn->AngleTurned = RobotPawn->TargetTurnAngle;
            bTurning = false;
        }
    }
}

// ---- Command execution functions ----

void UBaseMovement::MoveRob(float Distance){
    if(!RobotPawn) return;
    MoveSign = (Distance >= 0.f) ? 1.f : -1.f;
    bMoving = true;
}

void UBaseMovement::TurnRob(float Degrees){
    if(!RobotPawn) return;
    // positive degrees = left (CCW = +Yaw in Unreal)
    TurnSign = (Degrees >= 0.f) ? 1.f : -1.f;
    bTurning = true;
}

void UBaseMovement::Claw_Arm(float Alpha){
    if(!RobotPawn) return;
    if(RobotPawn->AttachedComponent != 1){
        UE_LOG(LogTemp, Warning, TEXT("Claw_Arm: Claw not attached (AttachedComponent=%d)"), RobotPawn->AttachedComponent);
        return;
    }
    RobotPawn->TargetArmAlpha = FMath::Clamp(Alpha, 0.f, 1.f);
}

void UBaseMovement::Claw_Claw(float Alpha){
    if(!RobotPawn) return;
    if(RobotPawn->AttachedComponent != 1){
        UE_LOG(LogTemp, Warning, TEXT("Claw_Claw: Claw not attached (AttachedComponent=%d)"), RobotPawn->AttachedComponent);
        return;
    }
    RobotPawn->TargetClawAlpha = FMath::Clamp(Alpha, 0.f, 1.f);
}

void UBaseMovement::Lift_Arm(float Alpha){
    if(!RobotPawn) return;
    if(RobotPawn->AttachedComponent != 2){
        UE_LOG(LogTemp, Warning, TEXT("Lift_Arm: Lift not attached (AttachedComponent=%d)"), RobotPawn->AttachedComponent);
        return;
    }
    RobotPawn->TargetArmAlpha = FMath::Clamp(Alpha, 0.f, 1.f);
}

void UBaseMovement::Lift_Claw(float Alpha){
    if(!RobotPawn) return;
    if(RobotPawn->AttachedComponent != 2){
        UE_LOG(LogTemp, Warning, TEXT("Lift_Claw: Lift not attached (AttachedComponent=%d)"), RobotPawn->AttachedComponent);
        return;
    }
    RobotPawn->TargetClawAlpha = FMath::Clamp(Alpha, 0.f, 1.f);
}

void UBaseMovement::StopMovement(){
    bMoving = false;
    bTurning = false;
}

// ---- Grab interaction ----

void UBaseMovement::OnGrabOverlap(
    UPrimitiveComponent* OverlappedComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult)
{
    if(OtherActor && OtherActor != RobotPawn){
        OverlappingObject = OtherActor;
        UE_LOG(LogTemp, Warning, TEXT("UBaseMovement: grab overlap — %s"), *OtherActor->GetName());
    }
}

void UBaseMovement::OnGrabEndOverlap(
    UPrimitiveComponent* OverlappedComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex)
{
    if(OtherActor == OverlappingObject){
        OverlappingObject = nullptr;
        UE_LOG(LogTemp, Warning, TEXT("UBaseMovement: grab overlap ended"));
    }
}

void UBaseMovement::TryGrab(){
    if(!OverlappingObject) return;

    UPrimitiveComponent* Comp = Cast<UPrimitiveComponent>(OverlappingObject->GetRootComponent());
    if(!Comp) return;

    Comp->SetSimulatePhysics(false);
    Comp->SetEnableGravity(false);
    Comp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    // Attach to pawn root — TODO: update socket/component once claw mesh is finalised
    OverlappingObject->AttachToActor(
        RobotPawn,
        FAttachmentTransformRules::KeepWorldTransform
    );

    UE_LOG(LogTemp, Warning, TEXT("UBaseMovement: grabbed %s"), *OverlappingObject->GetName());
}

void UBaseMovement::ReleaseGrab(){
    if(!OverlappingObject) return;

    UPrimitiveComponent* Comp = Cast<UPrimitiveComponent>(OverlappingObject->GetRootComponent());

    OverlappingObject->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

    if(Comp){
        Comp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
        Comp->SetSimulatePhysics(true);
        Comp->SetEnableGravity(true);
    }

    UE_LOG(LogTemp, Warning, TEXT("UBaseMovement: released grab"));
    OverlappingObject = nullptr;
}
