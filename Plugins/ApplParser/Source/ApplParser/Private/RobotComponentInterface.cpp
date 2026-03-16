#include "RobotComponentInterface.h"

static double validateRatio(const std::string& funcName, const std::vector<ApplValue>& args){
    if(args.size() != 1)
        throw ApplRuntimeError("'" + funcName + "' expects 1 argument (ratio between 0 and 1), got " +
            std::to_string(args.size()));

    double val = args[0].toDouble();
    if (val > 1.0) return 1.0;
    if (val < 0.0) return 0.0;
    return val;
}


ApplValue URobotComponentInterface::Dispatch(const std::string& name, const std::vector<ApplValue>& args){
    // --- Elevator Lift ---
    if (name == "raiseElevLift") {
        if (!ElevLiftAttached)
            throw ApplRuntimeError("'raiseElevLift' called but no elevator lift component attached");
        RaiseElevLift(validateRatio(name, args));
        return ApplValue(0);
    }
    if (name == "lowerElevLift") {
        if (!ElevLiftAttached)
            throw ApplRuntimeError("'lowerElevLift' called but no elevator lift component attached");
        LowerElevLift(validateRatio(name, args));
        return ApplValue(0);
    }

    // --- Scissor Lift ---
    if (name == "raiseScisLift") {
        if (!ScisLiftAttached)
            throw ApplRuntimeError("'raiseScisLift' called but no scissor lift component attached");
        RaiseScisLift(validateRatio(name, args));
        return ApplValue(0);
    }
    if (name == "lowerScisLift") {
        if (!ScisLiftAttached)
            throw ApplRuntimeError("'lowerScisLift' called but no scissor lift component attached");
        LowerScisLift(validateRatio(name, args));
        return ApplValue(0);
    }

    // --- Claw ---
    if (name == "openClaw") {
        if (!ClawAttached)
            throw ApplRuntimeError("'openClaw' called but no claw component attached");
        OpenClaw(validateRatio(name, args));
        return ApplValue(0);
    }
    if (name == "closeClaw") {
        if (!ClawAttached)
            throw ApplRuntimeError("'closeClaw' called but no claw component attached");
        CloseClaw(validateRatio(name, args));
        return ApplValue(0);
    }

    /*
    // --- SensorType (returns val from sensor on robot to interp) ---
    if (name == "getSensorReading") {
        if (!bSensorAttached)
            throw ApplRuntimeError("'getSensorReading' called but no sensor is attached");
        float val = GetSensorReading();
        return ApplValue(static_cast<double>(val));
    }
    */

    // unknown function name
    throw ApplRuntimeError("Unknown function '" + name + "' called");
}
