#pragma once

#include "vehicle/Vehicle.hpp"

namespace parking_lot::vehicle {

class Truck : public Vehicle {
public:
    explicit Truck(std::string licensePlate);
    
    std::string getLicensePlate() const override;
    VehicleSize getSize() const override;

private:
    std::string licensePlate_;
};

} // namespace parking_lot::vehicle
