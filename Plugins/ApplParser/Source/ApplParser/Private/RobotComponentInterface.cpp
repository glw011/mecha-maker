#include "RobotComponentInterface.h"


ApplValue URobotComponentInterface::Dispatch(const std::string& name, const std::vector<ApplValue>& args){
    if(!RobotManager){
        throw ApplRuntimeError("No RobotManager set — assign the robot's RobotManager component before running the program");
    }

    if(name == "startMove"){
        if(args.size() != 3){
            throw ApplRuntimeError("'startMove' expects 3 arguments (leftMotor, rightMotor, duration), got " + std::to_string(args.size()));
        }
        RobotManager->QueueStartMove(static_cast<float>(args[0].toDouble()), static_cast<float>(args[1].toDouble()), static_cast<float>(args[2].toDouble()));
        return ApplValue(0);
    }

    if(name == "turnLeft"){
        if(args.size() != 1){
            throw ApplRuntimeError("'turnLeft' expects 1 argument (duration), got " + std::to_string(args.size()));
        }
        RobotManager->QueueTurnLeft(static_cast<float>(args[0].toDouble()));
        return ApplValue(0);
    }

    if(name == "turnRight"){
        if (args.size() != 1){
            throw ApplRuntimeError("'turnRight' expects 1 argument (duration), got " + std::to_string(args.size()));
        }
        RobotManager->QueueTurnRight(static_cast<float>(args[0].toDouble()));
        return ApplValue(0);
    }

    if(name == "startArmMove"){
        if(args.size() != 2){
            throw ApplRuntimeError("'startArmMove' expects 2 arguments (armSpeed, duration), got " + std::to_string(args.size()));
        }
        if(RobotManager->Manipulator != EConfigManipulator::ElevLift && RobotManager->Manipulator != EConfigManipulator::ScisLift){
            throw ApplRuntimeError("'startArmMove' called but no arm manipulator is configured on this robot");
        }
        RobotManager->QueueStartArmMove(static_cast<float>(args[0].toDouble()), static_cast<float>(args[1].toDouble()));
        return ApplValue(0);
    }

    if(name == "openClaw"){
        if(args.size() != 1){
            throw ApplRuntimeError("'openClaw' expects 1 argument (duration), got " + std::to_string(args.size()));
        }
        if(RobotManager->Manipulator != EConfigManipulator::Claw){
            throw ApplRuntimeError("'openClaw' called but no claw is configured on this robot");
        }
        RobotManager->QueueStartClawMove(1, static_cast<float>(args[0].toDouble()));
        return ApplValue(0);
    }

    if(name == "closeClaw"){
        if(args.size() != 1){
            throw ApplRuntimeError("'closeClaw' expects 1 argument (duration), got " + std::to_string(args.size()));
        }
        if(RobotManager->Manipulator != EConfigManipulator::Claw){
            throw ApplRuntimeError("'closeClaw' called but no claw is configured on this robot");
        }
        RobotManager->QueueStartClawMove(0, static_cast<float>(args[0].toDouble()));
        return ApplValue(0);
    }

    // unknown function
    throw ApplRuntimeError("Unknown robot function '" + name + "' called");
}
