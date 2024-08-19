#ifndef SPORTSCAR_H
#define SPORTSCAR_H

#include "Car.h"
#include <iostream>

class SportsCar : public Car {
private:
    int topSpeed;

public:
    // Constructor
    SportsCar(const std::string& carMake, const std::string& carModel, int carYear, int carTopSpeed)
        : Car(carMake, carModel, carYear), topSpeed(carTopSpeed) {
        std::cout << "SportsCar constructed: " << make << " " << model << " " << year << " with top speed " << topSpeed << " km/h" << std::endl;
    }

    // Copy Constructor
    SportsCar(const SportsCar& other)
        : Car(other), topSpeed(other.topSpeed) {
        std::cout << "SportsCar copy-constructed: " << make << " " << model << " " << year << " with top speed " << topSpeed << " km/h" << std::endl;
    }

    // Copy Assignment Operator
    SportsCar& operator=(const SportsCar& other) {
        if (this != &other) {
            Car::operator=(other); // Assign base class members
            topSpeed = other.topSpeed;
            std::cout << "SportsCar assigned: " << make << " " << model << " " << year << " with top speed " << topSpeed << " km/h" << std::endl;
        }
        return *this;
    }

    // Destructor
    ~SportsCar() {
        std::cout << "SportsCar destroyed: " << make << " " << model << " " << year << " with top speed " << topSpeed << " km/h" << std::endl;
    }

    // Drive function
    void drive() const override {
        Car::drive(); // Call base class drive function
        std::cout << "At a top speed of " << topSpeed << " km/h!" << std::endl;
    }
};

#endif // SPORTSCAR_H
