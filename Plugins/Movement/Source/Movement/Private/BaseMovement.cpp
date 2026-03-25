#include "BaseMovement.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UBaseMovement::UBaseMovement()
{
    PrimaryComponentTick.bCanEverTick = true;
    bIsMoving = false;
}

void UBaseMovement::BeginPlay()
{
    Super::BeginPlay();
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

void UBaseMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!bIsMoving) return;

    CurrentTime += DeltaTime;

    ExecuteMovement(DeltaTime);

    if (CurrentTime >= Duration)
    {
        bIsMoving = false;
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