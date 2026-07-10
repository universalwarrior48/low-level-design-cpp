#include "vehicle/Car.hpp"

namespace parking_lot::vehicle {

Car::Car(std::string licensePlate) 
    : licensePlate_(std::move(licensePlate)) {}

std::string Car::getLicensePlate() const {
    return licensePlate_;
}

VehicleSize Car::getSize() const {
    return VehicleSize::MEDIUM;  // Cars are medium-sized
}

} // namespace parking_lot::vehicle
