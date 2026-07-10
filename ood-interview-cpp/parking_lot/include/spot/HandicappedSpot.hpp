#pragma once

#include "spot/ParkingSpot.hpp"
#include "vehicle/Vehicle.hpp"

namespace parking_lot::spot {

class HandicappedSpot : public ParkingSpot {
public:
    explicit HandicappedSpot(int spotNumber);
    
    int getSpotNumber() const override;
    bool isAvailable() const override;
    void occupy(std::shared_ptr<vehicle::Vehicle> vehicle) override;
    void vacate() override;
    vehicle::VehicleSize getSize() const override;

private:
    int spotNumber_;
    std::shared_ptr<vehicle::Vehicle> vehicle_;
};

} // namespace parking_lot::spot
