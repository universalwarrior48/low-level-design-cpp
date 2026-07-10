#include "vehicle/Motorcycle.hpp"

namespace parking_lot::vehicle {

Motorcycle::Motorcycle(std::string licensePlate) 
    : licensePlate_(std::move(licensePlate)) {}

std::string Motorcycle::getLicensePlate() const {
    return licensePlate_;
}

VehicleSize Motorcycle::getSize() const {
    return VehicleSize::SMALL;  // Motorcycles are small-sized
}

} // namespace parking_lot::vehicle
