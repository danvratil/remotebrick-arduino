#include "ControlSerial.h"
#include "Platform.h"

namespace{

constexpr int cmdLength = 2;

}

ControlSerial::ControlSerial(SerialInput input)
    : SoftwareSerial(Platform::getRxPin(input), Platform::getTxPin(input))
{
    begin(9600);
    mCmd.reserve(cmdLength);
}

bool ControlSerial::hasCommand()
{
    if (mCmd.length() == cmdLength) {
        return true;
    }

    return readCommand();
}

String ControlSerial::getCommand()
{
    String cmd = mCmd;
    mCmd = "";
    return cmd;
}

bool ControlSerial::readCommand()
{
    for (int i = mCmd.length(); available() && i < cmdLength; ++i) {
        mCmd += static_cast<char>(read());
    }

    return mCmd.length() == cmdLength;
}

