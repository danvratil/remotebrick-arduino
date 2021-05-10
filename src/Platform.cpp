#include "Platform.h"

int Platform::getTxPin(SerialInput input) {
    switch (input) {
    case SerialInput::Bluetooth:
        return static_cast<int>(Pins::BluetoothTxPin);
    case SerialInput::USB:
        return static_cast<int>(Pins::USBTxPin);
    }

    __builtin_unreachable();
}

int Platform::getRxPin(SerialInput input) {
    switch (input) {
    case SerialInput::Bluetooth:
        return static_cast<int>(Pins::BluetoothRxPin);
    case SerialInput::USB:
        return static_cast<int>(Pins::USBRxPin);
    }

    __builtin_unreachable();
}

std::pair<int, int> Platform::getDrivePins() {
    return {static_cast<int>(Pins::Engine1Pin1),
            static_cast<int>(Pins::Engine1Pin2)};
}

std::pair<int, int> Platform::getSteeringPins() {
    return {static_cast<int>(Pins::Engine2Pin1),
            static_cast<int>(Pins::Engine2Pin2)};
}
