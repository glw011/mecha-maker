#include "TestFunction.h"
#include "Engine/Engine.h"

void UTestFunction::PrintVariable(int32 Val)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Variable: % d"), Val));
		UE_LOG(LogTemp, Warning, TEXT("Variable: %d"), Val);
	}
}