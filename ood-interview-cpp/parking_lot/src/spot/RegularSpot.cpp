#include "spot/RegularSpot.hpp"

namespace parking_lot::spot {

RegularSpot::RegularSpot(int spotNumber) 
    : spotNumber_(spotNumber), vehicle_(nullptr) {}

int RegularSpot::getSpotNumber() const {
    return spotNumber_;
}

bool RegularSpot::isAvailable() const {
    return vehicle_ == nullptr;  // Available if no vehicle is occupying
}

void RegularSpot::occupy(std::shared_ptr<vehicle::Vehicle> vehicle) {
    if (isAvailable()) {
        vehicle_ = std::move(vehicle);
    }
    // Spot is already occupied - do nothing
}

void RegularSpot::vacate() {
    vehicle_ = nullptr;  // Make the spot available
}

vehicle::VehicleSize RegularSpot::getSize() const {
    return vehicle::VehicleSize::MEDIUM;  // Regular spots fit medium vehicles
}

} // namespace parking_lot::spot
