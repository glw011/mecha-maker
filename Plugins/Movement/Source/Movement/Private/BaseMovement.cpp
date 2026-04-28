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
        if (Mesh->GetName() == "SKM_Arm") ArmMesh = Mesh;
        else if (Mesh->GetName() == "Claw_Right") ClawMeshRight = Mesh;
        else if (Mesh->GetName() == "Claw_Left") ClawMeshLeft = Mesh; 
        else if (Mesh->GetName() == "Lift") LiftMesh = Mesh;
    }


    if(GrabCollider && ArmMesh)
    {
        // CHANGE THIS WHEN CLAW GETS MADE
        GrabCollider->AttachToComponent(ArmMesh, 
            FAttachmentTransformRules::SnapToTargetNotIncludingScale,
            FName("Claw_Right"));

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

void UBaseMovement::StartArmMove(float FlArmSpeed, float FlArmDuration)
{
    ArmSpeed = FlArmSpeed;

    ArmDuration = FlArmDuration;
    ArmTime = 0.f;

    Character = Cast<ACharacter>(GetOwner());

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
    ClawDuration = FlClawDuration;
    ClawTime = 0.f;

    Character = Cast<ACharacter>(GetOwner());
    
    if (InDir == 1) {
        bIsOpenClaw = true;
    }

    else {
        bIsCloseClaw = true;
    }
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

        if (ArmTime >= ArmDuration)
            bIsMovingArm = false;
    }

    if (bIsOpenClaw)
    {
        ClawTime += DeltaTime;
        ExecuteOpenClaw(DeltaTime);

        if (ClawTime >= ClawDuration){
            bIsOpenClaw = false;
            ReleaseGrab();
        }
    }

    if (bIsCloseClaw)
    {
        UE_LOG(LogTemp, Warning, TEXT("Claw is closing"));
        ClawTime += DeltaTime;
        ExecuteCloseClaw(DeltaTime);

        if (ClawTime >= ClawDuration)
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

    if(bIsLiftMoving && OverlappingObject) 
    {
        TryGrab();
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
    ArmCurrent += ArmSpeed * DeltaTime;
    ArmCurrent = FMath::Clamp(ArmCurrent, -100.f, 100.f);

    if(!ArmMesh) return;

    FRotator NewRot = FRotator(0.f, -90.f, ArmCurrent);
    ArmMesh->SetRelativeRotation(NewRot);

}

void UBaseMovement::ExecuteOpenClaw(float DeltaTime)
{
    ClawCurrentRight += 30 * DeltaTime;
    ClawCurrentRight = FMath::Clamp(ClawCurrentRight, -50.f, 20.f);

    ClawCurrentLeft -= 30 * DeltaTime;
    ClawCurrentLeft = FMath::Clamp(ClawCurrentLeft, -50.f, 20.f);

    if (!ClawMeshRight || !ClawMeshLeft) return;

    FRotator NewRotRight = FRotator(0.f, ClawCurrentRight, 0.f);
    ClawMeshRight->SetRelativeRotation(NewRotRight);

    FRotator NewRotLeft = FRotator(0.f, ClawCurrentLeft, 0.f);
    ClawMeshLeft->SetRelativeRotation(NewRotLeft);
}

void UBaseMovement::ExecuteCloseClaw(float DeltaTime)
{
    ClawCurrentRight -= 30 * DeltaTime;
    ClawCurrentRight = FMath::Clamp(ClawCurrentRight, -50.f, 20.f);

    ClawCurrentLeft += 30 * DeltaTime;
    ClawCurrentLeft = FMath::Clamp(ClawCurrentLeft, -50.f, 20.f);

    if (!ClawMeshRight || !ClawMeshLeft) return;

    FRotator NewRotRight = FRotator(0.f, ClawCurrentRight, 0.f);
    ClawMeshRight->SetRelativeRotation(NewRotRight);

    FRotator NewRotLeft = FRotator(0.f, ClawCurrentLeft, 0.f);
    ClawMeshLeft->SetRelativeRotation(NewRotLeft);

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
        ClawMeshRight,
        FAttachmentTransformRules::SnapToTargetNotIncludingScale,
        FName("Catcher")
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