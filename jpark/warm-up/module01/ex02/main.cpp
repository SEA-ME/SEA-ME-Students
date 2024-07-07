#include <iostream>

#include "SportsCar.hpp"
#include "RaceCar.hpp"

int main() {
    // Car car("Volvo", "XC60", 230); /* error */

    SportsCar sportsCar("Ferrari", "Roma", 2023, 340);
    RaceCar raceCar("Ferrari", "F1-75", 2022, 370);

    std::cout << std::endl;

    SportsCar dummy;
    dummy.drive();
    dummy = sportsCar;
    dummy.drive();

    std::cout << std::endl;

    // Polymorphism
    Car& car1 = sportsCar;
    Car& car2 = raceCar;
    car1.drive();
    car2.drive();

    return 0;
}
