#include "ControlSerial.h"
#include "Command.h"
#include "Engine.h"

class RemoteBrick
{
public:
    explicit RemoteBrick();

    void loop();

private:
    void handleCommand(Command &&command);
    void applyEngineCommand(Engine &engine, const Command &command);

    ControlSerial mSerial;
    Engine mDrivingEngine;
    Engine mSteeringEngine;
};
