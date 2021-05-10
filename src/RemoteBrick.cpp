#include "RemoteBrick.h"
#include "Command.h"
#include "Platform.h"

namespace {

Engine::Direction toEngineDirection(Direction direction) {
    switch (direction) {
        case Direction::Forward:
        case Direction::Right:
            return Engine::Direction::Forward;
        case Direction::Reverse:
        case Direction::Left:
            return Engine::Direction::Backward;
    }
}

} // namespace

RemoteBrick::RemoteBrick()
    : mSerial(SerialInput::Bluetooth)
    , mDrivingEngine(Platform::getDrivePins())
    , mSteeringEngine(Platform::getSteeringPins())
{}

void RemoteBrick::loop() {
    if (mSerial.hasCommand()) {
        handleCommand(Command{mSerial.getCommand()});
    }
}

void RemoteBrick::handleCommand(Command &&command) {
    if (!command.valid()) {
        return;
    }

    switch (command.direction) {
        case Direction::Forward:
        case Direction::Reverse:
            applyEngineCommand(mDrivingEngine, command);
            break;
        case Direction::Left:
        case Direction::Right:
            applyEngineCommand(mSteeringEngine, command);
            break;
    }
}

void RemoteBrick::applyEngineCommand(Engine &engine, const Command &command) {
    switch (command.state) {
        case State::Off:
            engine.run(Engine::Direction::None);
            break;
        case State::On:
            engine.run(toEngineDirection(command.direction));
            break;
    }
}

