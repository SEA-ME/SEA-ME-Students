#include <iostream>
#include "RaceCar.hpp"

RaceCar::RaceCar() : Car(), topSpeed(0) {
    std::cout << "RaceCar default constructor called" << std::endl;
}

RaceCar::RaceCar(const RaceCar& other)
    : Car(other), topSpeed(other.topSpeed) {
    std::cout << "RaceCar copy constructor called" << std::endl;
}

RaceCar::RaceCar(const std::string& make, const std::string& model, int year, int topSpeed)
    : Car(make, model, year), topSpeed(topSpeed) {
    std::cout << "RaceCar member initialization constructor called" << std::endl;
}

RaceCar& RaceCar::operator=(const RaceCar& other) {
    std::cout << "RaceCar copy assignment operator called" << std::endl;

    if (this != &other) {
        this->Car::operator=(other);
        this->topSpeed = other.topSpeed;
    }
    return *this;
}

RaceCar::~RaceCar() {
    std::cout << "RaceCar destructor called" << std::endl;
}

int	RaceCar::getTopSpeed() const {
    return this->topSpeed;
}

void RaceCar::setTopSpeed(int topSpeed) {
    this->topSpeed = topSpeed;
}

void RaceCar::drive() const {
    std::cout << "3.. 2.. 1.. Go!" << std::endl;
    std::cout << "Driving " << this->getMake() << " " << this->getModel() << " " << this->getYear() << " edition." << std::endl;
    std::cout << "Top speed: " << this->topSpeed << " km/h." << std::endl;
}
