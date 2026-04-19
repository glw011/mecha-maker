#include "RobotComponentInterface.h"


ApplValue URobotComponentInterface::Dispatch(const std::string& name, const std::vector<ApplValue>& args){
    if(!RobotManager){
        throw ApplRuntimeError("No RobotManager set — assign the robot's RobotManager component before running the program");
    }

    // ---- Movement ----

    if(name == "moveForward"){
        if(args.size() != 1){
            throw ApplRuntimeError("'moveForward' expects 1 argument (duration), got " + std::to_string(args.size()));
        }
        RobotManager->EnqueueMoveForward(static_cast<float>(args[0].toDouble()));
        return ApplValue(0);
    }

    if(name == "moveBackward"){
        if(args.size() != 1){
            throw ApplRuntimeError("'moveBackward' expects 1 argument (duration), got " + std::to_string(args.size()));
        }
        RobotManager->EnqueueMoveBackward(static_cast<float>(args[0].toDouble()));
        return ApplValue(0);
    }

    if(name == "turnLeft"){
        if(args.size() != 1){
            throw ApplRuntimeError("'turnLeft' expects 1 argument (duration), got " + std::to_string(args.size()));
        }
        RobotManager->EnqueueTurnLeft(static_cast<float>(args[0].toDouble()));
        return ApplValue(0);
    }

    if(name == "turnRight"){
        if(args.size() != 1){
            throw ApplRuntimeError("'turnRight' expects 1 argument (duration), got " + std::to_string(args.size()));
        }
        RobotManager->EnqueueTurnRight(static_cast<float>(args[0].toDouble()));
        return ApplValue(0);
    }

    // ---- Claw Arm ----

    if(name == "raiseArm"){
        if(args.size() != 0){
            throw ApplRuntimeError("'raiseArm' expects no arguments, got " + std::to_string(args.size()));
        }
        RobotManager->EnqueueRaiseArm();
        return ApplValue(0);
    }

    if(name == "lowerArm"){
        if(args.size() != 0){
            throw ApplRuntimeError("'lowerArm' expects no arguments, got " + std::to_string(args.size()));
        }
        RobotManager->EnqueueLowerArm();
        return ApplValue(0);
    }

    // ---- Actual Claw ----

    if(name == "openClaw"){
        if(args.size() != 0){
            throw ApplRuntimeError("'openClaw' expects no arguments, got " + std::to_string(args.size()));
        }
        if(RobotManager->ManipType != EManipType::Claw){
            throw ApplRuntimeError("'openClaw' called but this robot is not configured with a Claw");
        }
        RobotManager->EnqueueOpenClaw();
        return ApplValue(0);
    }

    if(name == "closeClaw"){
        if(args.size() != 0){
            throw ApplRuntimeError("'closeClaw' expects no arguments, got " + std::to_string(args.size()));
        }
        if(RobotManager->ManipType != EManipType::Claw){
            throw ApplRuntimeError("'closeClaw' called but this robot is not configured with a Claw");
        }
        RobotManager->EnqueueCloseClaw();
        return ApplValue(0);
    }

    // ---- Lift ----

    if(name == "raiseLift"){
        if(args.size() != 0){
            throw ApplRuntimeError("'raiseLift' expects no arguments, got " + std::to_string(args.size()));
        }
        if(RobotManager->ManipType != EManipType::Lift){
            throw ApplRuntimeError("'raiseLift' called but this robot is not configured with a Lift");
        }
        RobotManager->EnqueueRaiseLift();
        return ApplValue(0);
    }

    if(name == "lowerLift"){
        if(args.size() != 0){
            throw ApplRuntimeError("'lowerLift' expects no arguments, got " + std::to_string(args.size()));
        }
        if(RobotManager->ManipType != EManipType::Lift){
            throw ApplRuntimeError("'lowerLift' called but this robot is not configured with a Lift");
        }
        RobotManager->EnqueueLowerLift();
        return ApplValue(0);
    }

    // unknown function
    throw ApplRuntimeError("Unknown robot function '" + name + "' called");
}
