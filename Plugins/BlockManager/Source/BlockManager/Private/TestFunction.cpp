#include "TestFunction.h"
#include "Engine/Engine.h"

void UTestFunction::PrintMessage(const FString& Message, float Duration)
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(
            -1,
            Duration,
            FColor::Blue,
            Message
        );
    }
}