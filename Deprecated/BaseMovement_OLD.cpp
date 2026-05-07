#include "BaseMovement.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Components/SkeletalMeshComponent.h"
#include "Components/PrimitiveComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "Components/MeshComponent.h"


UBaseMovement::UBaseMovement()
{
    PrimaryComponentTick.bCanEverTick = true;
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
}

void UBaseMovement::BeginPlay()
{
    Super::BeginPlay();

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

        GrabCollider->OnComponentBeginOverlap.AddDynamic(this, &UBaseMovement::OnGrabOverlap);
        GrabCollider->OnComponentEndOverlap.AddDynamic(this, &UBaseMovement::OnGrabEndOverlap);

        GrabCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
        GrabCollider->SetGenerateOverlapEvents(true);
        GrabCollider->SetCollisionResponseToAllChannels(ECR_Overlap);
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
    }
}

void UBaseMovement::StartMove(float FlLeftMotor, float FlRightMotor, float FlDuration, float FlSpeed, float FlSize)
{

    Character = Cast<ACharacter>(GetOwner());

    if (!Character) return;

    Character->GetCharacterMovement()->MaxWalkSpeed = FlSpeed;

    LeftMotor = FlLeftMotor;
    RightMotor = FlRightMotor;
    Duration = FlDuration;
    Speed = FlSpeed;

    CurrentTime = 0.f;

    AngularSpeed = ((LeftMotor - RightMotor) / 100) * (Speed / FlSize);

    bIsMoving = true;
}

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
}

void UBaseMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    

    if (bIsMoving)
    {
        CurrentTime += DeltaTime;
        ExecuteMovement(DeltaTime);

        if (CurrentTime >= Duration)
            bIsMoving = false;
    
    }

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


}

void UBaseMovement::ExecuteMovement(float DeltaTime)
{

    FVector Forward = Character->GetActorForwardVector();

    float MoveSpeed = (((LeftMotor + RightMotor) * 0.5f)/ 100);
    Character->AddMovementInput(Forward, MoveSpeed);

    float Alpha = CurrentTime / Duration;
    Alpha = FMath::Clamp(Alpha, 0.f, 1.f);

    FRotator CurrentRot = Character->GetActorRotation();
    CurrentRot.Yaw += AngularSpeed * DeltaTime;

    Character->SetActorRotation(CurrentRot);

}

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

void UBaseMovement::OnGrabOverlap(
    UPrimitiveComponent* OverlappedComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult)
{
    if (OtherActor && OtherActor != Character)
    {
        UE_LOG(LogTemp, Warning, TEXT("OVERLAP TRIGGERED"));
        OverlappingObject = OtherActor;
        UE_LOG(LogTemp, Warning, TEXT("Root: %s"), *OverlappingObject->GetRootComponent()->GetName());
    }
}

void UBaseMovement::OnGrabEndOverlap(
    UPrimitiveComponent* OverlappedComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex)
{
    if (OtherActor == OverlappingObject)
    {
        if (!bIsCloseClaw && !bIsMovingArm) 
        {
            UE_LOG(LogTemp, Warning, TEXT("OVERLAP ENDED"))
            OverlappingObject = nullptr;
        }
    }
}

void UBaseMovement::TryGrab()
{
    UE_LOG(LogTemp, Warning, TEXT("Try grab RUNNING"));
    if (!OverlappingObject) return;

    UPrimitiveComponent* Comp = Cast<UPrimitiveComponent>(OverlappingObject->GetRootComponent());
    UE_LOG(LogTemp, Warning, TEXT("Root: %s"), *OverlappingObject->GetRootComponent()->GetName());
    if (!Comp) return;

    Comp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    Comp->SetSimulatePhysics(false);
    Comp->SetEnableGravity(false);

    // CHANGE THIS WHEN CLAW GETS MADE
    OverlappingObject->AttachToComponent(
        ArmMesh,
        FAttachmentTransformRules::SnapToTargetNotIncludingScale,
        FName("Cmpnt_Claw_Arm_Claw_L")
    );

    UE_LOG(LogTemp, Warning, TEXT("GRABBED OBJECT"));
    
}

void UBaseMovement::ReleaseGrab() 
{
    if (!OverlappingObject) return;

    UPrimitiveComponent* Comp = Cast<UPrimitiveComponent>(OverlappingObject->GetRootComponent());

    if (!Comp) return;

    OverlappingObject->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

    Comp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    Comp->SetSimulatePhysics(true);
    Comp->SetEnableGravity(true);

    OverlappingObject = nullptr;

    UE_LOG(LogTemp, Warning, TEXT("RELEASED OBJECT"));

}