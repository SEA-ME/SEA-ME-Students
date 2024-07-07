#include <iostream>
#include "Car.hpp"

int main()
{
    Car car1("volkswagen", 200);
    Car car2;

    std::cout << "[car1] name: " << car1.getName() << " speed: " << car1.getSpeed() << std::endl;
    std::cout << "[car2] name: " << car2.getName() << " speed: " << car2.getSpeed() << std::endl;

    car2 = car1;
    std::cout << "[car2] name: " << car2.getName() << " speed: " << car2.getSpeed() << std::endl;

    Car car3("kia", 100);
    Car car4(car3);

    std::cout << "[car4] name: " << car4.getName() << " speed: " << car4.getSpeed() << std::endl;

    return 0;
}
