#include <iostream>
#include <string>

class Car {
protected:
    std::string make;
    std::string model;
    int year;

public:
    Car(std::string make, std::string model, int year) : make(make), model(model), year(year) {}

    virtual void drive() {
        std::cout << "Driving " << make << " " << model << " " << year << " edition." << std::endl;
    }

    virtual ~Car() {
        //std::cout << "Car destructor called." << std::endl;
    }
};

class SportsCar : public Car {
private:
    int topSpeed;

public:
    SportsCar(const std::string make, const std::string model, const int year, int topSpeed)
        : Car(make, model, year), topSpeed(topSpeed) {
    }

    void drive() override {
        Car::drive();
        std::cout << "Top speed is c " << topSpeed << "." << std::endl;
    }

    ~SportsCar() {
        //std::cout << "SportsCar destructor called." << std::endl;
    }
};

int main() {
    Car myCar("Hyundai", "Sonata", 2019);
    myCar.drive();

    SportsCar mySportCar("Ferrari", "488 GTB", 2023, 330);
    mySportCar.drive();

    return 0;
}
