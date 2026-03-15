#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "TestFunction.generated.h"

UCLASS() 
class MyPlugin_Api UTestFunction : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public: 

	UFUNCTION(BlueprintCallable, Category = "BlockManager")
	static void PrintVariable(int 32 Val);

};
