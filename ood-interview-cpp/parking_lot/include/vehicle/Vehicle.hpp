#pragma once

#include <string>
#include "vehicle/VehicleSize.hpp"

namespace parking_lot::vehicle {

class Vehicle {
public:
    virtual ~Vehicle() = default;
    virtual std::string getLicensePlate() const = 0;
    virtual VehicleSize getSize() const = 0;
};

} // namespace parking_lot::vehicle
