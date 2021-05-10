#include "Platform.h"

int Platform::getTxPin(SerialInput input) {
    switch (input) {
    case SerialInput::Bluetooth:
        return static_cast<int>(Pins::BluetoothTxPin);
    case SerialInput::USB:
        return static_cast<int>(Pins::USBTxPin);
    }
}

int Platform::getRxPin(SerialInput input) {
    switch (input) {
    case SerialInput::Bluetooth:
        return static_cast<int>(Pins::BluetoothRxPin);
    case SerialInput::USB:
        return static_cast<int>(Pins::USBRxPin);
    }
}
