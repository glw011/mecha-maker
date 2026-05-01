#include "RobotComponentInterface.h"


ApplValue URobotComponentInterface::Dispatch(const std::string& name, const std::vector<ApplValue>& args){
    if(!RobotManager){
        throw ApplRuntimeError("No RobotManager set — assign the robot's RobotManager component before running the program");
    }

    // ---- Move functions ----

    if(name == "moveForward"){
        if(args.size() != 1){
            throw ApplRuntimeError("'moveForward' expects 1 argument (distance), got " + std::to_string(args.size()));
        }
        RobotManager->EnqueueMoveForward(static_cast<float>(args[0].toDouble()));
        return ApplValue(0);
    }

    if(name == "moveBackward"){
        if(args.size() != 1){
            throw ApplRuntimeError("'moveBackward' expects 1 argument (distance), got " + std::to_string(args.size()));
        }
        RobotManager->EnqueueMoveBackward(static_cast<float>(args[0].toDouble()));
        return ApplValue(0);
    }

    if(name == "turnLeft"){
        if(args.size() != 1){
            throw ApplRuntimeError("'turnLeft' expects 1 argument (degrees), got " + std::to_string(args.size()));
        }
        RobotManager->EnqueueTurnLeft(static_cast<float>(args[0].toDouble()));
        return ApplValue(0);
    }

    if(name == "turnRight"){
        if(args.size() != 1){
            throw ApplRuntimeError("'turnRight' expects 1 argument (degrees), got " + std::to_string(args.size()));
        }
        RobotManager->EnqueueTurnRight(static_cast<float>(args[0].toDouble()));
        return ApplValue(0);
    }

    // ---- Claw component functions ----

    if(name == "claw_raiseArm"){
        if(args.size() != 0){
            throw ApplRuntimeError("'claw_raiseArm' expects no arguments, got " + std::to_string(args.size()));
        }
        if(RobotManager->ManipType != EManipType::Claw){
            throw ApplRuntimeError("'claw_raiseArm' called but robot is not configured with a Claw");
        }
        RobotManager->EnqueueClawRaiseArm();
        return ApplValue(0);
    }

    if(name == "claw_lowerArm"){
        if(args.size() != 0){
            throw ApplRuntimeError("'claw_lowerArm' expects no arguments, got " + std::to_string(args.size()));
        }
        if(RobotManager->ManipType != EManipType::Claw){
            throw ApplRuntimeError("'claw_lowerArm' called but robot is not configured with a Claw");
        }
        RobotManager->EnqueueClawLowerArm();
        return ApplValue(0);
    }

    if(name == "claw_openClaw"){
        if(args.size() != 0){
            throw ApplRuntimeError("'claw_openClaw' expects no arguments, got " + std::to_string(args.size()));
        }
        if(RobotManager->ManipType != EManipType::Claw){
            throw ApplRuntimeError("'claw_openClaw' called but robot is not configured with a Claw");
        }
        RobotManager->EnqueueClawOpenClaw();
        return ApplValue(0);
    }

    if(name == "claw_closeClaw"){
        if(args.size() != 0){
            throw ApplRuntimeError("'claw_closeClaw' expects no arguments, got " + std::to_string(args.size()));
        }
        if(RobotManager->ManipType != EManipType::Claw){
            throw ApplRuntimeError("'claw_closeClaw' called but robot is not configured with a Claw");
        }
        RobotManager->EnqueueClawCloseClaw();
        return ApplValue(0);
    }

    // ---- Lift component functions ----

    if(name == "lift_raiseArm"){
        if(args.size() != 0){
            throw ApplRuntimeError("'lift_raiseArm' expects no arguments, got " + std::to_string(args.size()));
        }
        if(RobotManager->ManipType != EManipType::Lift){
            throw ApplRuntimeError("'lift_raiseArm' called but robot is not configured with a Lift");
        }
        RobotManager->EnqueueLiftRaiseArm();
        return ApplValue(0);
    }

    if(name == "lift_lowerArm"){
        if(args.size() != 0){
            throw ApplRuntimeError("'lift_lowerArm' expects no arguments, got " + std::to_string(args.size()));
        }
        if(RobotManager->ManipType != EManipType::Lift){
            throw ApplRuntimeError("'lift_lowerArm' called but robot is not configured with a Lift");
        }
        RobotManager->EnqueueLiftLowerArm();
        return ApplValue(0);
    }

    if(name == "lift_openClaw"){
        if(args.size() != 0){
            throw ApplRuntimeError("'lift_openClaw' expects no arguments, got " + std::to_string(args.size()));
        }
        if(RobotManager->ManipType != EManipType::Lift){
            throw ApplRuntimeError("'lift_openClaw' called but robot is not configured with a Lift");
        }
        RobotManager->EnqueueLiftOpenClaw();
        return ApplValue(0);
    }

    if(name == "lift_closeClaw"){
        if(args.size() != 0){
            throw ApplRuntimeError("'lift_closeClaw' expects no arguments, got " + std::to_string(args.size()));
        }
        if(RobotManager->ManipType != EManipType::Lift){
            throw ApplRuntimeError("'lift_closeClaw' called but robot is not configured with a Lift");
        }
        RobotManager->EnqueueLiftCloseClaw();
        return ApplValue(0);
    }

    // unknown function
    throw ApplRuntimeError("Unknown robot function '" + name + "' called");
}
