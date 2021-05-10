#include "RemoteBrick.h"
#include "Command.h"

RemoteBrick::RemoteBrick()
    : mSerial(SerialInput::Bluetooth)
{}

void RemoteBrick::loop() {
    if (mSerial.hasCommand()) {
        handleCommand(Command{mSerial.getCommand()});
    }
}

void RemoteBrick::handleCommand(Command command) {

}
