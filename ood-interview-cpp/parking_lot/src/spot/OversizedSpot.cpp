#include "spot/OversizedSpot.hpp"

namespace parking_lot::spot {

OversizedSpot::OversizedSpot(int spotNumber) 
    : spotNumber_(spotNumber), vehicle_(nullptr) {}

int OversizedSpot::getSpotNumber() const {
    return spotNumber_;
}

bool OversizedSpot::isAvailable() const {
    return vehicle_ == nullptr;
}

void OversizedSpot::occupy(std::shared_ptr<vehicle::Vehicle> vehicle) {
    if (isAvailable()) {
        vehicle_ = std::move(vehicle);
    }
}

void OversizedSpot::vacate() {
    vehicle_ = nullptr;
}

vehicle::VehicleSize OversizedSpot::getSize() const {
    return vehicle::VehicleSize::LARGE;  // Oversized spots fit large vehicles
}

} // namespace parking_lot::spot
