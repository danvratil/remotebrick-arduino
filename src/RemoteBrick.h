#include "ControlSerial.h"
#include "Command.h"

class RemoteBrick
{
public:
    explicit RemoteBrick();

    void loop();

private:
    void handleCommand(Command command);

    ControlSerial mSerial;
};
