#include "Constants.h"

#include <Arduino.h>
#include <SoftwareSerial.h>

class ControlSerial : public SoftwareSerial {
public:
    explicit ControlSerial(SerialInput input);

    [[nodiscard]] bool hasCommand();
    [[nodiscard]] String getCommand();

private:
    [[nodiscard]] bool readCommand();

    String mCmd;
};
