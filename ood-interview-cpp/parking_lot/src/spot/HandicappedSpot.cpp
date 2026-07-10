#include "spot/HandicappedSpot.hpp"

namespace parking_lot::spot {

HandicappedSpot::HandicappedSpot(int spotNumber) 
    : spotNumber_(spotNumber), vehicle_(nullptr) {}

int HandicappedSpot::getSpotNumber() const {
    return spotNumber_;
}

bool HandicappedSpot::isAvailable() const {
    return vehicle_ == nullptr;
}

void HandicappedSpot::occupy(std::shared_ptr<vehicle::Vehicle> vehicle) {
    if (isAvailable()) {
        vehicle_ = std::move(vehicle);
    }
}

void HandicappedSpot::vacate() {
    vehicle_ = nullptr;
}

vehicle::VehicleSize HandicappedSpot::getSize() const {
    return vehicle::VehicleSize::SMALL;  // Handicapped spots fit small vehicles
}

} // namespace parking_lot::spot
