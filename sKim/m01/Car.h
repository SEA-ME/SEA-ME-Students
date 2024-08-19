#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
#include <iostream>

class Car : public Vehicle {
private:
    int doors;

public:
    // Constructor
    Car(const std::string& carMake = "Unknown", const std::string& carModel = "Unknown", int carYear = 0, int carDoors = 4)
        : Vehicle(carMake, carModel, carYear), doors(carDoors) {
        std::cout << "Car constructed: " << make << " " << model << " " << year << " with " << doors << " doors." << std::endl;
    }

    // Copy Constructor
    Car(const Car& other)
        : Vehicle(other), doors(other.doors) {
        std::cout << "Car copy-constructed: " << make << " " << model << " " << year << " with " << doors << " doors." << std::endl;
    }

    // Copy Assignment Operator
    Car& operator=(const Car& other) {
        if (this != &other) {
            Vehicle::operator=(other);
            doors = other.doors;
            std::cout << "Car assigned: " << make << " " << model << " " << year << " with " << doors << " doors." << std::endl;
        }
        return *this;
    }

    // Destructor
    virtual ~Car() {
        std::cout << "Car destroyed: " << make << " " << model << " " << year << std::endl;
    }

    // Drive function
    void drive() const override {
        std::cout << "Driving " << make << " " << model << " " << year << " edition." << std::endl;
    }
};

#endif // CAR_H
