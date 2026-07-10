#pragma once

#include "vehicle/VehicleSize.hpp"
#include <memory>

namespace parking_lot::vehicle {

class Motorcycle : public Vehicle {
public:
    explicit Motorcycle(std::string licensePlate);
    
    std::string getLicensePlate() const override;
    VehicleSize getSize() const override;

private:
    std::string licensePlate_;
};

} // namespace parking_lot::vehicle
