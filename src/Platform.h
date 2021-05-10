#pragma once

#include "Constants.h"

#include <utility>

namespace Platform {

int getRxPin(SerialInput input);
int getTxPin(SerialInput input);

std::pair<int, int> getDrivePins();
std::pair<int, int> getSteeringPins();


} // namespace
