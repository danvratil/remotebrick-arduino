#include "Engine.h"

#include <Arduino.h>

Engine::Engine(std::pair<int, int> pins)
    : mPins(pins)
{}

void Engine::stop() {
    digitalWrite(mPins.first, LOW);
    digitalWrite(mPins.second, LOW);
}

void Engine::run(Engine::Direction direction) {
    if (direction == mCurrentDirection) {
        return;
    }

    switch (direction) {
        case Direction::None:
            digitalWrite(mPins.first, LOW);
            digitalWrite(mPins.second, LOW);
            break;
        case Direction::Forward:
            digitalWrite(mPins.second, LOW);
            digitalWrite(mPins.first, HIGH);
            break;
        case Direction::Backward:
            digitalWrite(mPins.first, LOW);
            digitalWrite(mPins.second, HIGH);
            break;
    }

    mCurrentDirection = direction;
}

void Engine::stop() {
    run(Direction::None);
}
