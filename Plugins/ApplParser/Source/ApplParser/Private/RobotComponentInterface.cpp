#include "RobotComponentInterface.h"

DEFINE_LOG_CATEGORY_STATIC(RobotDispatchLog, Log, All);

ApplValue URobotComponentInterface::Dispatch(const std::string& name, const std::vector<ApplValue>& args){
    UE_LOG(RobotDispatchLog, Warning, TEXT("[DBG] Dispatch called: fn='%s' args=%d"),
        UTF8_TO_TCHAR(name.c_str()), (int)args.size());

    if(!RobotManager){
        UE_LOG(RobotDispatchLog, Error, TEXT("[DBG] Dispatch FAILED — RobotManager is NULL"));
        throw ApplRuntimeError("No RobotManager set — assign the robot's RobotManager component before running the program");
    }

    UE_LOG(RobotDispatchLog, Warning, TEXT("[DBG] RobotManager is valid, routing '%s'"),
        UTF8_TO_TCHAR(name.c_str()));

    // ---- Move functions ----

    if(name == "moveForward"){
        if(args.size() != 1){
            throw ApplRuntimeError("'moveForward' expects 1 argument (distance), got " + std::to_string(args.size()));
        }
        float dist = static_cast<float>(args[0].toDouble());
        UE_LOG(RobotDispatchLog, Warning, TEXT("[DBG] Enqueuing MoveForward(%.2f)"), dist);
        RobotManager->EnqueueMoveForward(dist);
        return ApplValue(0);
    }

    if(name == "moveBackward"){
        if(args.size() != 1){
            throw ApplRuntimeError("'moveBackward' expects 1 argument (distance), got " + std::to_string(args.size()));
        }
        float dist = static_cast<float>(args[0].toDouble());
        UE_LOG(RobotDispatchLog, Warning, TEXT("[DBG] Enqueuing MoveBackward(%.2f)"), dist);
        RobotManager->EnqueueMoveBackward(dist);
        return ApplValue(0);
    }

    if(name == "turnLeft"){
        if(args.size() != 1){
            throw ApplRuntimeError("'turnLeft' expects 1 argument (degrees), got " + std::to_string(args.size()));
        }
        float deg = static_cast<float>(args[0].toDouble());
        UE_LOG(RobotDispatchLog, Warning, TEXT("[DBG] Enqueuing TurnLeft(%.2f)"), deg);
        RobotManager->EnqueueTurnLeft(deg);
        return ApplValue(0);
    }

    if(name == "turnRight"){
        if(args.size() != 1){
            throw ApplRuntimeError("'turnRight' expects 1 argument (degrees), got " + std::to_string(args.size()));
        }
        float deg = static_cast<float>(args[0].toDouble());
        UE_LOG(RobotDispatchLog, Warning, TEXT("[DBG] Enqueuing TurnRight(%.2f)"), deg);
        RobotManager->EnqueueTurnRight(deg);
        return ApplValue(0);
    }

    // ---- Claw component functions ----

    if(name == "claw_raiseArm"){
        if(args.size() != 0) throw ApplRuntimeError("'claw_raiseArm' expects no arguments, got " + std::to_string(args.size()));
        if(RobotManager->ManipType != EManipType::Claw) throw ApplRuntimeError("'claw_raiseArm' called but robot is not configured with a Claw");
        UE_LOG(RobotDispatchLog, Warning, TEXT("[DBG] Enqueuing ClawRaiseArm"));
        RobotManager->EnqueueClawRaiseArm();
        return ApplValue(0);
    }
    if(name == "claw_lowerArm"){
        if(args.size() != 0) throw ApplRuntimeError("'claw_lowerArm' expects no arguments, got " + std::to_string(args.size()));
        if(RobotManager->ManipType != EManipType::Claw) throw ApplRuntimeError("'claw_lowerArm' called but robot is not configured with a Claw");
        UE_LOG(RobotDispatchLog, Warning, TEXT("[DBG] Enqueuing ClawLowerArm"));
        RobotManager->EnqueueClawLowerArm();
        return ApplValue(0);
    }
    if(name == "claw_openClaw"){
        if(args.size() != 0) throw ApplRuntimeError("'claw_openClaw' expects no arguments, got " + std::to_string(args.size()));
        if(RobotManager->ManipType != EManipType::Claw) throw ApplRuntimeError("'claw_openClaw' called but robot is not configured with a Claw");
        UE_LOG(RobotDispatchLog, Warning, TEXT("[DBG] Enqueuing ClawOpenClaw"));
        RobotManager->EnqueueClawOpenClaw();
        return ApplValue(0);
    }
    if(name == "claw_closeClaw"){
        if(args.size() != 0) throw ApplRuntimeError("'claw_closeClaw' expects no arguments, got " + std::to_string(args.size()));
        if(RobotManager->ManipType != EManipType::Claw) throw ApplRuntimeError("'claw_closeClaw' called but robot is not configured with a Claw");
        UE_LOG(RobotDispatchLog, Warning, TEXT("[DBG] Enqueuing ClawCloseClaw"));
        RobotManager->EnqueueClawCloseClaw();
        return ApplValue(0);
    }

    // ---- Lift component functions ----

    if(name == "lift_raiseArm"){
        if(args.size() != 0) throw ApplRuntimeError("'lift_raiseArm' expects no arguments, got " + std::to_string(args.size()));
        if(RobotManager->ManipType != EManipType::Lift) throw ApplRuntimeError("'lift_raiseArm' called but robot is not configured with a Lift");
        UE_LOG(RobotDispatchLog, Warning, TEXT("[DBG] Enqueuing LiftRaiseArm"));
        RobotManager->EnqueueLiftRaiseArm();
        return ApplValue(0);
    }
    if(name == "lift_lowerArm"){
        if(args.size() != 0) throw ApplRuntimeError("'lift_lowerArm' expects no arguments, got " + std::to_string(args.size()));
        if(RobotManager->ManipType != EManipType::Lift) throw ApplRuntimeError("'lift_lowerArm' called but robot is not configured with a Lift");
        UE_LOG(RobotDispatchLog, Warning, TEXT("[DBG] Enqueuing LiftLowerArm"));
        RobotManager->EnqueueLiftLowerArm();
        return ApplValue(0);
    }
    if(name == "lift_openClaw"){
        if(args.size() != 0) throw ApplRuntimeError("'lift_openClaw' expects no arguments, got " + std::to_string(args.size()));
        if(RobotManager->ManipType != EManipType::Lift) throw ApplRuntimeError("'lift_openClaw' called but robot is not configured with a Lift");
        UE_LOG(RobotDispatchLog, Warning, TEXT("[DBG] Enqueuing LiftOpenClaw"));
        RobotManager->EnqueueLiftOpenClaw();
        return ApplValue(0);
    }
    if(name == "lift_closeClaw"){
        if(args.size() != 0) throw ApplRuntimeError("'lift_closeClaw' expects no arguments, got " + std::to_string(args.size()));
        if(RobotManager->ManipType != EManipType::Lift) throw ApplRuntimeError("'lift_closeClaw' called but robot is not configured with a Lift");
        UE_LOG(RobotDispatchLog, Warning, TEXT("[DBG] Enqueuing LiftCloseClaw"));
        RobotManager->EnqueueLiftCloseClaw();
        return ApplValue(0);
    }

    UE_LOG(RobotDispatchLog, Error, TEXT("[DBG] Dispatch: unknown function '%s'"), UTF8_TO_TCHAR(name.c_str()));
    throw ApplRuntimeError("Unknown robot function '" + name + "' called");
}
