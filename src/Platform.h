#pragma once

#include "Constants.h"

#include <utility>

namespace Platform {

[[nodiscard]] int getRxPin(SerialInput input);
[[nodiscard]] int getTxPin(SerialInput input);

[[nodiscard]] std::pair<int, int> getDrivePins();
[[nodiscard]] std::pair<int, int> getSteeringPins();


} // namespace
