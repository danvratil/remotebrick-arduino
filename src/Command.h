#pragma once

#include "Constants.h"

#include <Arduino.h>

struct Command {
    explicit Command(const String &cmd);
    Command(const Command &) = default;
    Command(Command &&) noexcept = default;
    Command &operator=(const Command &) = default;
    Command &operator=(Command &&) noexcept = default;
    ~Command() = default;

    bool valid() const;

    Direction direction = static_cast<Direction>(0xff);
    State state = static_cast<State>(0xff);
};
