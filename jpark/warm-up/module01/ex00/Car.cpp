#include <iostream>
#include "Car.hpp"

Car::Car(): name("A car"), speed(0) {}

Car::Car(const Car& other): name(other.name), speed(other.speed) {}

Car::Car(const std::string& name, int speed): name(name), speed(speed) {}

Car& Car::operator=(const Car& other) {
    this->name = other.name;
    this->speed = other.speed;

    return *this;
}

Car::~Car() {
    std::cout << this->name << " destructor called" << std::endl;
}

const std::string& Car::getName() const {
    return this->name;
}

int Car::getSpeed() const {
    return this->speed;
}
