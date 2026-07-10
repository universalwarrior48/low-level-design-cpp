#include "spot/CompactSpot.hpp"

namespace parking_lot::spot {

CompactSpot::CompactSpot(int spotNumber) 
    : spotNumber_(spotNumber), vehicle_(nullptr) {}

int CompactSpot::getSpotNumber() const {
    return spotNumber_;
}

bool CompactSpot::isAvailable() const {
    return vehicle_ == nullptr;
}

void CompactSpot::occupy(std::shared_ptr<vehicle::Vehicle> vehicle) {
    if (isAvailable()) {
        vehicle_ = std::move(vehicle);
    }
}

void CompactSpot::vacate() {
    vehicle_ = nullptr;
}

vehicle::VehicleSize CompactSpot::getSize() const {
    return vehicle::VehicleSize::SMALL;  // Compact spots fit small vehicles
}

} // namespace parking_lot::spot
