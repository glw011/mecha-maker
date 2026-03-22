#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "TestFunction.generated.h"

UCLASS()
class BLOCKMANAGER_API UTestFunction : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

    public:

        UFUNCTION(BlueprintCallable, Category="MyDebug")
        static void PrintMessage(const FString& Message, float Duration = 2.0f);
};