#pragma once

#include "vehicle/Vehicle.hpp"

namespace parking_lot::vehicle {

class Car : public Vehicle {
public:
    explicit Car(std::string licensePlate);
    
    std::string getLicensePlate() const override;
    VehicleSize getSize() const override;

private:
    std::string licensePlate_;
};

} // namespace parking_lot::vehicle
