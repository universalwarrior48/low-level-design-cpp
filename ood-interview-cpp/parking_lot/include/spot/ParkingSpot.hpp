#pragma once

#include "vehicle/VehicleSize.hpp"
#include <memory>

namespace parking_lot::vehicle {
class Vehicle;
}

namespace parking_lot::spot {

class ParkingSpot {
public:
    virtual ~ParkingSpot() = default;
    [[nodiscard]] virtual bool isAvailable() const = 0;
    virtual void occupy(std::shared_ptr<vehicle::Vehicle> vehicle) = 0;
    virtual void vacate() = 0;
    [[nodiscard]] virtual int getSpotNumber() const = 0;
    [[nodiscard]] virtual vehicle::VehicleSize getSize() const = 0;
};

} // namespace parking_lot::spot
