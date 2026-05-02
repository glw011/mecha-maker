#include "BaseMovement.h"
#include "Components/PrimitiveComponent.h"

DEFINE_LOG_CATEGORY_STATIC(BaseMovementLog, Log, All);


UBaseMovement::UBaseMovement(){
    PrimaryComponentTick.bCanEverTick = true;
  
  /*
    bIsMoving = false;
    bIsMovingArm = false;
    bIsOpenClaw = false;
    bIsCloseClaw = false;
    GrabCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("GrabCollider"));

    bIsLiftMoving = false;
    LiftCurrentPos = 0.f;
    LiftTargetPos = 0.f;
    

    static ConstructorHelpers::FObjectFinder<UAnimSequence> LiftAnimFinder(TEXT("/Game/RobotAssets/ElevatorV2/Anim_ElevatorSequence"));
    if (LiftAnimFinder.Succeeded()) LiftAnim = LiftAnimFinder.Object;

    static ConstructorHelpers::FObjectFinder<UAnimSequence> ClawAnimFinder(TEXT("/Game/RobotAssets/Animations/Anim_Claw_Sequence"));
    if (ClawAnimFinder.Succeeded()) ClawAnim = ClawAnimFinder.Object;

    static ConstructorHelpers::FObjectFinder<UAnimSequence> ArmAnimFinder(TEXT("/Game/RobotAssets/Animations/Anim_Arm_Sequence"));
    if (ArmAnimFinder.Succeeded()) ArmAnim = ArmAnimFinder.Object;
  */
    // TODO: wire GrabCollider attachment after config finalized
}

void UBaseMovement::BeginPlay(){
    Super::BeginPlay();
  
  
    /*
    Character = Cast<ACharacter>(GetOwner());

    TArray<USkeletalMeshComponent*> Meshes;
    Character->GetComponents<USkeletalMeshComponent>(Meshes);


    for (auto* Mesh : Meshes)
    {
        // CHANGE THIS WHEN CLAW GETS MADE
        if (Mesh->GetName() == "ArmMesh") ArmMesh = Mesh;
        //else if (Mesh->GetName() == "Claw_Right") ClawMeshRight = Mesh;
        //else if (Mesh->GetName() == "Claw_Left") ClawMeshLeft = Mesh; 
        else if (Mesh->GetName() == "Lift") LiftMesh = Mesh;
    }


    if(GrabCollider && ArmMesh)
    {
        // CHANGE THIS WHEN CLAW GETS MADE
        GrabCollider->AttachToComponent(ArmMesh, 
            FAttachmentTransformRules::SnapToTargetNotIncludingScale,
            FName("Cmpnt_Claw_Arm_Claw_L"));
    */
    
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
      
        /*
        UE_LOG(LogTemp, Warning, TEXT("FORCED COLLISION SETTINGS"));

        // SET PICKUP AREA
        GrabCollider->SetBoxExtent(FVector(30.f,30.f,30.f));
        GrabCollider->SetRelativeLocation(FVector(-15.f, 0.f, 0.f));
    }

    if (LiftMesh && LiftAnim) 
    {
        LiftMesh->SetAnimationMode(EAnimationMode::AnimationSingleNode);
        LiftMesh->SetAnimation(LiftAnim);
        LiftMesh->SetPosition(0.f); // start fully down
        LiftMesh->Stop();
    }

    if(ArmMesh && ArmAnim)
    {
        ArmMesh->SetAnimationMode(EAnimationMode::AnimationSingleNode);
        ArmMesh->SetAnimation(ArmAnim);
        ArmMesh->SetPosition(0.f); // start fully down
        ArmMesh->Stop();
    }


    // DEBUGGING
    if (!GrabCollider)
    {
        UE_LOG(LogTemp, Error, TEXT("GrabCollider is NULL"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("GrabCollider is FOUND"));
        UE_LOG(LogTemp, Warning, TEXT("Collision Enabled: %d"), (int32)GrabCollider->GetCollisionEnabled());
        UE_LOG(LogTemp, Warning, TEXT("Generate Overlap: %d"), GrabCollider->GetGenerateOverlapEvents());
        */
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

/*
void UBaseMovement::StartArmMove(float InDir, float FlArmDuration)
{
    if(ArmMesh && ArmAnim)
    {
        ArmMesh->SetAnimationMode(EAnimationMode::AnimationSingleNode);
        ArmMesh->SetAnimation(ArmAnim);
    }

    ArmDur = FlArmDuration;
    ArmTime = 0.f;
    ArmTargetPos = (InDir == 1) ? 1.0f : 0.0f;

    bIsMovingArm = true;
}

void UBaseMovement::StartLiftMove(int32 InDir, float LiftDuration)
{
    LiftDur = LiftDuration;
    LiftTime = 0.f;
    LiftTargetPos = (InDir == 1) ? 1.0f : 0.0f; // 1 = up, -1 = down
    bIsLiftMoving = true;
}

void UBaseMovement::ExecuteLiftMovement(float DeltaTime)
{
    if (!LiftMesh || !LiftAnim) return;

    // Move current position toward target over LiftDuration seconds
    float LiftSpeed = 1.0f / LiftDur;
    LiftCurrentPos = FMath::FInterpConstantTo(LiftCurrentPos, LiftTargetPos, DeltaTime, LiftSpeed);

    // Scrub the animation to match
    float AnimLength = LiftAnim->GetPlayLength();
    LiftMesh->SetPosition(LiftCurrentPos * AnimLength);

    // Stop when reached target
    if (FMath::IsNearlyEqual(LiftCurrentPos, LiftTargetPos, 0.01f))
    {
        LiftCurrentPos = LiftTargetPos;
        bIsLiftMoving = false;
    }
}

void UBaseMovement::StartClawMove(int32 InDir, float FlClawDuration)
{
    if(ArmMesh && ClawAnim)
    {
        ArmMesh->SetAnimationMode(EAnimationMode::AnimationSingleNode);
        ArmMesh->SetAnimation(ClawAnim);
    }

    ClawDur = FlClawDuration;
    ClawTime = 0.f;
    ClawTargetPos = (InDir == 1) ? 1.0f : 0.0f; // 1 = up, -1 = down
    
    if (InDir == 1) bIsOpenClaw = true;

    if (InDir == -1) bIsCloseClaw = true;
*/

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
  
    /*

    if (bIsMovingArm)
    {
        ArmTime += DeltaTime;
        ExecuteArmMovement(DeltaTime);

        if (ArmTime >= ArmDur)
            bIsMovingArm = false;
    }

    if (bIsOpenClaw)
    {
        ClawTime += DeltaTime;
        ExecuteOpenClaw(DeltaTime);

        if (ClawTime >= ClawDur){
            bIsOpenClaw = false;
            ReleaseGrab();
        }
    }

    if (bIsCloseClaw)
    {
        UE_LOG(LogTemp, Warning, TEXT("Claw is closing"));
        ClawTime += DeltaTime;
        ExecuteCloseClaw(DeltaTime);

        if (ClawTime >= ClawDur)
        {
            bIsCloseClaw = false;
        }
    }

    if(bIsCloseClaw && OverlappingObject) 
    {
        TryGrab();
    }

    if(bIsLiftMoving && OverlappingObject) TryGrab();

    if (bIsLiftMoving)
    {
        LiftTime += DeltaTime;
        ExecuteLiftMovement(DeltaTime);
    }
    */

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


/*
void UBaseMovement::ExecuteArmMovement(float DeltaTime)
{
    if (!ArmMesh || !ArmAnim) return;

    // Move current position toward target over LiftDuration seconds
    float ArmSpeed = 1.0f / ArmDur;
    ArmCurrentPos = FMath::FInterpConstantTo(ArmCurrentPos, ArmTargetPos, DeltaTime, ArmSpeed);

    // Scrub the animation to match
    float AnimLength = ArmAnim->GetPlayLength();
    ArmMesh->SetPosition(ArmCurrentPos * AnimLength);

    // Stop when reached target
    if (FMath::IsNearlyEqual(ArmCurrentPos, ArmTargetPos, 0.01f))
    {
        ArmCurrentPos = ArmTargetPos;
        bIsMovingArm = false;
    }

}

void UBaseMovement::ExecuteOpenClaw(float DeltaTime)
{
    if (!ArmMesh || !ClawAnim) return;

    // Move current position toward target over LiftDuration seconds
    float ClawSpeed = 1.0f / ClawDur;
    ClawCurrentPos = FMath::FInterpConstantTo(ClawCurrentPos, ClawTargetPos, DeltaTime, ClawSpeed);

    // Scrub the animation to match
    float AnimLength = ClawAnim->GetPlayLength();
    ArmMesh->SetPosition(ClawCurrentPos * AnimLength);

    // Stop when reached target
    if (FMath::IsNearlyEqual(ClawCurrentPos, ClawTargetPos, 0.01f))
    {
        ClawCurrentPos = ClawTargetPos;
        bIsOpenClaw = false;
        bIsCloseClaw = false;
    }
}

void UBaseMovement::ExecuteCloseClaw(float DeltaTime)
{
    ClawCurrentRight -= 30 * DeltaTime;
    ClawCurrentRight = FMath::Clamp(ClawCurrentRight, -50.f, 20.f);

    ClawCurrentLeft += 30 * DeltaTime;
    ClawCurrentLeft = FMath::Clamp(ClawCurrentLeft, -50.f, 20.f);

    if (!ArmMesh) return;

    //FRotator NewRotRight = FRotator(0.f, ClawCurrentRight, 0.f);
    //ClawMeshRight->SetRelativeRotation(NewRotRight);

    //FRotator NewRotLeft = FRotator(0.f, ClawCurrentLeft, 0.f);
    //ClawMeshLeft->SetRelativeRotation(NewRotLeft);

}
*/
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

    /*
    // CHANGE THIS WHEN CLAW GETS MADE
    OverlappingObject->AttachToComponent(
        ArmMesh,
        FAttachmentTransformRules::SnapToTargetNotIncludingScale,
        FName("Cmpnt_Claw_Arm_Claw_L")      
    */
  
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
