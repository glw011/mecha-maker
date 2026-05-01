#include "BaseMovement.h"
#include "Components/PrimitiveComponent.h"

DEFINE_LOG_CATEGORY_STATIC(BaseMovementLog, Log, All);


UBaseMovement::UBaseMovement(){
    PrimaryComponentTick.bCanEverTick = true;
    // GrabCollider is intentionally NOT created here — UBoxComponent is a scene component and
    // must be created/attached in the owning actor (ARobotPawnBase), not inside a non-scene component.
    // Wire GrabCollider attachment once the claw mesh socket is finalised.
}

void UBaseMovement::BeginPlay(){
    Super::BeginPlay();

    RobotPawn = Cast<ARobotPawnBase>(GetOwner());
    UE_LOG(BaseMovementLog, Warning, TEXT("[DBG] BaseMovement BeginPlay — RobotPawn is %s (owner class: %s)"),
        RobotPawn ? TEXT("VALID") : TEXT("NULL"),
        GetOwner() ? *GetOwner()->GetClass()->GetName() : TEXT("(no owner)"));

    if(GrabCollider){
        UE_LOG(BaseMovementLog, Warning, TEXT("[DBG] BaseMovement BeginPlay — GrabCollider found, binding overlap events"));
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

    // Log first 3 ticks to confirm tick is running and show state
    static int32 BMTickCount = 0;
    if(BMTickCount < 3){
        UE_LOG(BaseMovementLog, Warning,
            TEXT("[DBG] BaseMovement Tick #%d — RobotPawn=%s bMoving=%s bTurning=%s"),
            BMTickCount,
            RobotPawn ? TEXT("valid") : TEXT("NULL"),
            bMoving   ? TEXT("true")  : TEXT("false"),
            bTurning  ? TEXT("true")  : TEXT("false"));
        ++BMTickCount;
    }

    if(!RobotPawn){
        static bool bBMNullLogged = false;
        if(!bBMNullLogged){
            UE_LOG(BaseMovementLog, Error, TEXT("[DBG] BaseMovement Tick — RobotPawn NULL every frame, movement blocked"));
            bBMNullLogged = true;
        }
        return;
    }

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
    UE_LOG(BaseMovementLog, Warning, TEXT("[DBG] MoveRob called — Distance=%.2f RobotPawn=%s"),
        Distance, RobotPawn ? TEXT("valid") : TEXT("NULL"));
    if(!RobotPawn) return;
    MoveSign = (Distance >= 0.f) ? 1.f : -1.f;
    bMoving = true;
    UE_LOG(BaseMovementLog, Warning, TEXT("[DBG] MoveRob — bMoving set to true, MoveSign=%.1f"), MoveSign);
}

void UBaseMovement::TurnRob(float Degrees){
    UE_LOG(BaseMovementLog, Warning, TEXT("[DBG] TurnRob called — Degrees=%.2f RobotPawn=%s"),
        Degrees, RobotPawn ? TEXT("valid") : TEXT("NULL"));
    if(!RobotPawn) return;
    TurnSign = (Degrees >= 0.f) ? 1.f : -1.f;
    bTurning = true;
    UE_LOG(BaseMovementLog, Warning, TEXT("[DBG] TurnRob — bTurning set to true, TurnSign=%.1f"), TurnSign);
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
