#include "Constants.h"

#include <Arduino.h>
#include <SoftwareSerial.h>

class ControlSerial : public SoftwareSerial {
public:
    explicit ControlSerial(SerialInput input);

    bool hasCommand();
    String getCommand();

private:
    bool readCommand();

    String mCmd;
};
