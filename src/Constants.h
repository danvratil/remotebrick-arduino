#pragma once

#include <Arduino.h> // uint8_t

enum class SerialInput {
    USB,
    Bluetooth
};

enum class Pins : int {
    USBRxPin = 0,
    USBTxPin = 1,
    BluetoothRxPin = 2,
    BluetoothTxPin = 3,

    Engine1Pin1 = 8,
    Engine1Pin2 = 9,
    Engine2Pin1 = 10,
    Engine2Pin2 = 11
};

enum class Direction : uint8_t {
    Forward = 1,
    Reverse = 2,
    Left = 3,
    Right = 4
};

enum class State : uint8_t {
    Off = 0,
    On = 1
};

