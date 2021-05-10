/* Project: src/remotebrick */

#include "RemoteBrick.h"

#include <Arduino.h>

// Performs initialization done by Arduino
void preInit() {
    init();
#if defined(USBCON)
    USBDevice.attach();
#endif
}

int main() {
    preInit();

    RemoteBrick remoteBrick;
    while (true) {
        remoteBrick.loop();
    }

}

