#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ApplTypes.h"

#include "RobotComponentInterface.generated.h"


UCLASS(BlueprintType, Blueprintable)
class APPLPARSER_API URobotComponentInterface : public UObject{
    GENERATED_BODY()

    public:
          
        /* dispatch method called by ApplCompiler lambda to translate function name + eval'd args into Blueprint 
        event calls and then returns the ApplValue result (ApplValue of 0 for void calls) */
        ApplValue Dispatch(const std::string& name, const std::vector<ApplValue>& args);


        //  attachment flags set by config widget before programming so dispatch method can check pre-calls
        UPROPERTY(BlueprintReadWrite, Category="Robot|ComponentFlag")
        bool ElevLiftAttached = false;

        UPROPERTY(BlueprintReadWrite, Category="Robot|ComponentFlag")
        bool ScisLiftAttached = false;

        UPROPERTY(BlueprintReadWrite, Category="Robot|ComponentFlag")
        bool ClawAttached = false;
        
        UPROPERTY(BlueprintReadWrite, Category="Robot|ComponentFlag")
        bool TankTreadAttached = false;
        
        UPROPERTY(BlueprintReadWrite, Category="Robot|ComponentFlag")
        bool FourWhlAttached = false;

        //  one event/function per component action
        //      ** RobotActor's Component Widget overrides these to trigger animation/physics in Unreal

        // --- Elevator Lift ---
        UFUNCTION(BlueprintImplementableEvent, Category="Robot|ElevLift")
        void RaiseElevLift(double ratioVal);

        UFUNCTION(BlueprintImplementableEvent, Category="Robot|ElevLift")
        void LowerElevLift(double ratioVal);
        
        // --- Scissor Lift ---
        UFUNCTION(BlueprintImplementableEvent, Category="Robot|ScisLift")
        void RaiseScisLift(double ratioVal);

        UFUNCTION(BlueprintImplementableEvent, Category="Robot|ScisLift")
        void LowerScisLift(double ratioVal);

        // --- Claw ---
        UFUNCTION(BlueprintImplementableEvent, Category="Robot|Claw")
        void OpenClaw(double ratioVal);

        UFUNCTION(BlueprintImplementableEvent, Category="Robot|Claw")
        void CloseClaw(double ratioVal);

        /* idk if these will exist??
        UFUNCTION(BlueprintImplementableEvent, Category="Robot|Claw")
        void RaiseClaw(double ratioVal);

        UFUNCTION(BlueprintImplementableEvent, Category="Robot|Claw")
        void LowerClaw(double ratioVal);
        */

        /*
        // --- SensorType (returns value back to interpreter) ---
        UFUNCTION(BlueprintImplementableEvent, Category="Robot|Sensor")
        float GetSensorReading();

        UPROPERTY(BlueprintReadWrite, Category="Robot|Components")
        bool SensorAttached = false;
        */
};
