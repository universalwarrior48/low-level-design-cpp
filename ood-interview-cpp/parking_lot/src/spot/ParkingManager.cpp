#include "spot/ParkingManager.hpp"
#include <algorithm>

namespace parking_lot::spot {

ParkingManager::ParkingManager(std::map<vehicle::VehicleSize, std::vector<std::shared_ptr<ParkingSpot>> availableSpots)
    : availableSpots_(std::move(availableSpots)) {}

std::shared_ptr<ParkingSpot> ParkingManager::findSpotForVehicle(const std::shared_ptr<vehicle::Vehicle>& vehicle) {
    vehicle::VehicleSize vehicleSize = vehicle->getSize();

    // Start looking from the smallest spot that can fit the vehicle
    for (int sizeOrdinal = static_cast<int>(vehicleSize); 
         sizeOrdinal < static_cast<int>(vehicle::VehicleSize::LARGE) + 1; 
         ++sizeOrdinal) {
        auto size = static_cast<vehicle::VehicleSize>(sizeOrdinal);
        auto it = availableSpots_.find(size);
        if (it != availableSpots_.end()) {
            for (const auto& spot : it->second) {
                if (spot->isAvailable()) {
                    return spot;  // Return the first available spot
                }
            }
        }
    }
    return nullptr;  // No suitable spot found
}

std::shared_ptr<ParkingSpot> ParkingManager::parkVehicle(const std::shared_ptr<vehicle::Vehicle>& vehicle) {
    std::shared_ptr<ParkingSpot> spot = findSpotForVehicle(vehicle);
    if (spot != nullptr) {
        spot->occupy(vehicle);
        // Record the parking spot for the vehicle
        vehicleToSpotMap_[vehicle] = spot;
        // Remove the spot from the available list
        auto& spots = availableSpots_[spot->getSize()];
        spots.erase(std::remove(spots.begin(), spots.end(), spot), spots.end());
        return spot;  // Parking successful
    }
    return nullptr;  // No spot found for this vehicle
}

void ParkingManager::unparkVehicle(const std::shared_ptr<vehicle::Vehicle>& vehicle) {
    auto it = vehicleToSpotMap_.find(vehicle);
    if (it != vehicleToSpotMap_.end()) {
        std::shared_ptr<ParkingSpot> spot = it->second;
        vehicleToSpotMap_.erase(it);
        spot->vacate();
        availableSpots_[spot->getSize()].push_back(spot);
    }
}

std::shared_ptr<ParkingSpot> ParkingManager::findVehicleSpot(const std::shared_ptr<vehicle::Vehicle>& vehicle) const {
    auto it = vehicleToSpotMap_.find(vehicle);
    if (it != vehicleToSpotMap_.end()) {
        return it->second;
    }
    return nullptr;
}

} // namespace parking_lot::spot
