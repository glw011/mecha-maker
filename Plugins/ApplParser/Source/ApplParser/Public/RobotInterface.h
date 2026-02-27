#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RobotInterface.generated.h"

UCLASS(Blueprintable)
class APPLPARSER_API URobotInterface : public UObject{
  
  GENERATED_BODY()

  // all terminal functions will go here
  public:
    UFUNCTION(BlueprintImplementableEvent, Category="Robot Commands")
    void Cmd_MoveForward(int32 Units);
    
    UFUNCTION(BlueprintImplementableEvent, Category="Robot Commands")
    void Cmd_MoveBackward(int32 Units);

    UFUNCTION(BlueprintImplementableEvent, Category="Robot Commands")
    void Cmd_TurnLeft(float Degrees);

    UFUNCTION(BlueprintImplementableEvent, Category="Robot Commands")
    void Cmd_TurnRight(float Degrees);

    UFUNCTION(BlueprintImplementableEvent, Category="Robot Commands")
    void Cmd_Wait(float Seconds);
};
