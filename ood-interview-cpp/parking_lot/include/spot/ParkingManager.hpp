#pragma once

#include "spot/ParkingSpot.hpp"
#include "vehicle/Vehicle.hpp"
#include "vehicle/VehicleSize.hpp"
#include <map>
#include <vector>
#include <memory>

namespace parking_lot::spot {

class ParkingManager {
public:
    explicit ParkingManager(std::map<vehicle::VehicleSize, std::vector<std::shared_ptr<ParkingSpot>>> availableSpots);
    
    std::shared_ptr<ParkingSpot> findSpotForVehicle(const std::shared_ptr<vehicle::Vehicle>& vehicle);
    std::shared_ptr<ParkingSpot> parkVehicle(const std::shared_ptr<vehicle::Vehicle>& vehicle);
    void unparkVehicle(const std::shared_ptr<vehicle::Vehicle>& vehicle);
    
    // Used for testing
    std::shared_ptr<ParkingSpot> findVehicleSpot(const std::shared_ptr<vehicle::Vehicle>& vehicle) const;

private:
    std::map<vehicle::VehicleSize, std::vector<std::shared_ptr<ParkingSpot>>> availableSpots_;
    std::map<std::shared_ptr<vehicle::Vehicle>, std::shared_ptr<ParkingSpot>> vehicleToSpotMap_;
};

} // namespace parking_lot::spot
