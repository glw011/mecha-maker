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
    
    // DELETE THIS IF STILL NOT SHOW UP
    ClawRightPivot = CreateDefaultSubobject<USceneComponent>(TEXT("ClawRightPivot"));
}

void UBaseMovement::BeginPlay()
{
    Super::BeginPlay();

    Character = Cast<ACharacter>(GetOwner());

    TArray<USkeletalMeshComponent*> Meshes;
    Character->GetComponents<USkeletalMeshComponent>(Meshes);

    // DELETE THIS IF STILL NOT SHOW UP
    TArray<UMeshComponent*> RegMesh;
    Character->GetComponents<UMeshComponent>(RegMesh);

    for (auto* Mesh : Meshes)
    {
        // CHANGE THIS WHEN CLAW GETS MADE
        if (Mesh->GetName() == "SKM_Arm") ArmMesh = Mesh;
        else if (Mesh->GetName() == "Claw_Right") ClawMeshRight = Mesh;
        else if (Mesh->GetName() == "Claw_Left") ClawMeshLeft = Mesh; 
    }

    // DELETE THIS IF STILL NOT SHOW UP
    for (auto* Mesh : RegMesh)
    {
        if (Mesh->GetName() == "ClawGuide") ClawGuide = Mesh;
    }

    // DELETE THIS IF STILL NOT SHOW UP
    if (ClawRightPivot && ClawGuide) 
    {
        ClawRightPivot->AttachToComponent(
            ClawGuide,
            FAttachmentTransformRules::SnapToTargetNotIncludingScale,
            FName("Claw_Right")
        );
    }

    // DELETE THIS IF STILL NOT SHOW UP
    if (ClawMeshRight && ClawRightPivot)
    {
        ClawMeshRight->AttachToComponent(
            ClawRightPivot,
            FAttachmentTransformRules::KeepRelativeTransform
        );
        ClawMeshRight->SetRelativeLocation(FVector(-0.3f,7.f,2.f));
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

void UBaseMovement::StartLiftMove(int32 InDir, float LiftDuration){
    // TODO: implement 
    /**
     * - Logic on my end will use this function for calls to move lift up/down 
     * - I assumed the call to move the lift will mirror StartClawMove function
     * - If that isn't true just implement the function using a different name and I'll call it from in here
     * - Do not change the signature of this function, will mess up RobotManager
    */
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