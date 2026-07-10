#include "vehicle/Truck.hpp"

namespace parking_lot::vehicle {

Truck::Truck(std::string licensePlate) 
    : licensePlate_(std::move(licensePlate)) {}

std::string Truck::getLicensePlate() const {
    return licensePlate_;
}

VehicleSize Truck::getSize() const {
    return VehicleSize::LARGE;  // Trucks are large-sized
}

} // namespace parking_lot::vehicle
