#include "Command.h"

Command::Command(const String &cmd)
{
    if (cmd.length() != 2) {
        return;
    }

    switch (cmd[0]) {
        case '+':
            state = State::On;
            break;
        case '-':
            state = State::Off;
            break;
    }

    switch (cmd[1]) {
        case 'F':
            direction = Direction::Forward;
            break;
        case 'L':
            direction = Direction::Left;
            break;
        case 'R':
            direction = Direction::Right;
            break;
        case 'B':
            direction = Direction::Reverse;
            break;
        default:
            state = static_cast<State>(0xff);
            break;
    }
}

bool Command::valid() const
{
    return static_cast<uint8_t>(state) != 0xff
        && static_cast<uint8_t>(direction) != 0xff;
}
