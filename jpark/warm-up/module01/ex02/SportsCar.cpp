#include <iostream>
#include "SportsCar.hpp"

SportsCar::SportsCar() : Car(), topSpeed(0) {
    std::cout << "SportsCar default constructor called" << std::endl;
}

SportsCar::SportsCar(const SportsCar& other)
    : Car(other), topSpeed(other.topSpeed) {
    std::cout << "SportsCar copy constructor called" << std::endl;
}

SportsCar::SportsCar(const std::string& make, const std::string& model, int year, int topSpeed)
    : Car(make, model, year), topSpeed(topSpeed) {
    std::cout << "SportsCar member initialization constructor called" << std::endl;
}

SportsCar& SportsCar::operator=(const SportsCar& other) {
    std::cout << "SportsCar copy assignment operator called" << std::endl;

    if (this != &other) {
        this->Car::operator=(other);
        this->topSpeed = other.topSpeed;
    }
    return *this;
}

SportsCar::~SportsCar() {
    std::cout << "SportsCar destructor called" << std::endl;
}

int	SportsCar::getTopSpeed() const {
    return this->topSpeed;
}

void SportsCar::setTopSpeed(int topSpeed) {
    this->topSpeed = topSpeed;
}

void SportsCar::drive() const {
    std::cout << "Driving " << this->getMake() << " " << this->getModel() << " " << this->getYear() << " edition." << std::endl;
    std::cout << "Top speed: " << this->topSpeed << " km/h." << std::endl;
}
