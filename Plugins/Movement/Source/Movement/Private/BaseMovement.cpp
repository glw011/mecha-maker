#include "BaseMovement.h"
#include "Components/PrimitiveComponent.h"

#define DEBUG true

DEFINE_LOG_CATEGORY_STATIC(BaseMovementLog, Log, All);


UBaseMovement::UBaseMovement(){
    PrimaryComponentTick.bCanEverTick = true;

    // NOT creating GrabCollider here like before since UBoxComponent is scene component & created/attached
    // in owning actor (ARobotPawnBase > RoboRob) within Unreal, not in this non-scene component
    
    // Will wire GrabCollider once everything is finalised

}

void UBaseMovement::BeginPlay(){
    Super::BeginPlay();

    RobotPawn = Cast<ARobotPawnBase>(GetOwner());

    if(DEBUG){
        UE_LOG(BaseMovementLog, Warning, TEXT("[DBG] BaseMovement BeginPlay: RobotPawn is %s (owner class: %s)"),
            RobotPawn ? TEXT("VALID") : TEXT("NULL"),
            GetOwner() ? *GetOwner()->GetClass()->GetName() : TEXT("(no owner)"));
    }

    if(GrabCollider){

        if(DEBUG) UE_LOG(BaseMovementLog, Warning, TEXT("[DBG] BaseMovement BeginPlay: GrabCollider found, binding overlap events"));

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

    // Avoids flooding log during DEBUG
    static int32 BMTickCount = 0;
    if(DEBUG && BMTickCount < 3){
        UE_LOG(BaseMovementLog, Warning,
            TEXT("[DBG] BaseMovement Tick #%d: RobotPawn=%s bMoving=%s bTurning=%s"),
            BMTickCount,
            RobotPawn ? TEXT("valid") : TEXT("NULL"),
            bMoving   ? TEXT("true")  : TEXT("false"),
            bTurning  ? TEXT("true")  : TEXT("false"));
        ++BMTickCount;
    }

    if(!RobotPawn){
        static bool bBMNullLogged = false;
        if(DEBUG && !bBMNullLogged){
            UE_LOG(BaseMovementLog, Error, TEXT("[DBG] BaseMovement Tick: RobotPawn NULL every frame, movement blocked"));
            bBMNullLogged = true;
        }
        return;
    }

    // ---- Execute Active Move Command ----
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

    // ---- Execute Active Turn Command ----
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

// ---- Command Execution Functions ----

void UBaseMovement::MoveRob(float Distance){
    if(DEBUG) UE_LOG(BaseMovementLog, Warning, TEXT("[DBG] MoveRob called: Distance=%.2f RobotPawn=%s"), Distance, RobotPawn ? TEXT("valid") : TEXT("NULL"));
    if(!RobotPawn) return;
    MoveSign = (Distance >= 0.f) ? 1.f : -1.f;
    bMoving = true;
    if(DEBUG) UE_LOG(BaseMovementLog, Warning, TEXT("[DBG] MoveRob: bMoving set to true, MoveSign=%.1f"), MoveSign);
}

void UBaseMovement::TurnRob(float Degrees){
    if(DEBUG) UE_LOG(BaseMovementLog, Warning, TEXT("[DBG] TurnRob called: Degrees=%.2f RobotPawn=%s"), Degrees, RobotPawn ? TEXT("valid") : TEXT("NULL"));
    if(!RobotPawn) return;
    TurnSign = (Degrees >= 0.f) ? -1.f : 1.f;  // oops, CW/CCW are reversed so inverting sign here to correct
    bTurning = true;
    if(DEBUG) UE_LOG(BaseMovementLog, Warning, TEXT("[DBG] TurnRob: bTurning set to true, TurnSign=%.1f"), TurnSign);
}

void UBaseMovement::Claw_Arm(float Alpha){
    if(!RobotPawn) return;
    if(RobotPawn->AttachedComponent != 1){
        if(DEBUG) UE_LOG(LogTemp, Warning, TEXT("Claw_Arm: Claw not attached (AttachedComponent=%d)"), RobotPawn->AttachedComponent);
        return;
    }
    RobotPawn->TargetArmAlpha = FMath::Clamp(Alpha, 0.f, 1.f);
}

void UBaseMovement::Claw_Claw(float Alpha){
    if(!RobotPawn) return;
    if(RobotPawn->AttachedComponent != 1){
        if(DEBUG) UE_LOG(LogTemp, Warning, TEXT("Claw_Claw: Claw not attached (AttachedComponent=%d)"), RobotPawn->AttachedComponent);
        return;
    }
    // when closing and a grabbable is in the zone, stop at GrabClampAlpha instead of fully closed
    float EffectiveAlpha = (Alpha <= 0.f && RobotPawn->bHasGrabbableTarget) ? RobotPawn->GrabClampAlpha : Alpha;
    RobotPawn->TargetClawAlpha = FMath::Clamp(EffectiveAlpha, 0.f, 1.f);
}

void UBaseMovement::Lift_Arm(float Alpha){
    if(!RobotPawn) return;
    if(RobotPawn->AttachedComponent != 2){
        if(DEBUG) UE_LOG(LogTemp, Warning, TEXT("Lift_Arm: Lift not attached (AttachedComponent=%d)"), RobotPawn->AttachedComponent);
        return;
    }
    RobotPawn->TargetArmAlpha = FMath::Clamp(Alpha, 0.f, 1.f);
}

void UBaseMovement::Lift_Claw(float Alpha){
    if(!RobotPawn) return;
    if(RobotPawn->AttachedComponent != 2){
        if(DEBUG) UE_LOG(LogTemp, Warning, TEXT("Lift_Claw: Lift not attached (AttachedComponent=%d)"), RobotPawn->AttachedComponent);
        return;
    }
    float EffectiveAlpha = (Alpha <= 0.f && RobotPawn->bHasGrabbableTarget) ? RobotPawn->GrabClampAlpha : Alpha;
    RobotPawn->TargetClawAlpha = FMath::Clamp(EffectiveAlpha, 0.f, 1.f);
}

void UBaseMovement::StopMovement(){
    bMoving = false;
    bTurning = false;
}

void UBaseMovement::SetMoveSpeed(float InSpeed){
    if(bMoving || bTurning) return;

    if(InSpeed > 1.f && InSpeed < 400.f){
        MoveSpeed = InSpeed;
        AngularSpeed = 0.1f * InSpeed;
    }
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
        if(DEBUG) UE_LOG(LogTemp, Warning, TEXT("UBaseMovement: grab overlap: %s"), *OtherActor->GetName());
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
        if(DEBUG) UE_LOG(LogTemp, Warning, TEXT("UBaseMovement: grab overlap ended"));
    }
}

void UBaseMovement::TryGrab(){
    if(!OverlappingObject) return;

    UPrimitiveComponent* Comp = Cast<UPrimitiveComponent>(OverlappingObject->GetRootComponent());
    if(!Comp) return;

    Comp->SetSimulatePhysics(false);
    Comp->SetEnableGravity(false);
    Comp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    // Attach to pawn root 
    // TODO: update socket/component once claw mesh is finalised
    OverlappingObject->AttachToActor(
        RobotPawn,
        FAttachmentTransformRules::KeepWorldTransform
    );

    if(DEBUG) UE_LOG(LogTemp, Warning, TEXT("UBaseMovement: grabbed %s"), *OverlappingObject->GetName());
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

    if(DEBUG) UE_LOG(LogTemp, Warning, TEXT("UBaseMovement: released grab"));
    OverlappingObject = nullptr;
}
