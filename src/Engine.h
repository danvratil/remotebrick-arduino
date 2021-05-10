#pragma once

#include <utility>

class Engine {
public:
    enum class Direction {
        None = 0,
        Forward = 1,
        Backward = 2
    };

    explicit Engine(std::pair<int, int> pins);

    void run(Direction direction);
    void stop();

private:
    std::pair<int, int> mPins;
    Direction mCurrentDirection = Direction::None;
};
