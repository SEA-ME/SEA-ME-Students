#include <unistd.h>
#include <iostream>

#include "Car.hpp"

void memoryLeakExample() {
    Car* ptr = new Car("Hyundai", 70);
}

void danglingPointerExample() {
    Car* ptr = new Car("Volvo", 40);

    std::cout << "value of pointer: " << ptr << std::endl;

    delete ptr;

    std::cout << ptr->getName() << std::endl;
    std::cout << ptr->getSpeed() << std::endl;
}

void smartPointerExample() {
    std::shared_ptr<Car> ptr = std::make_shared<Car>("Kia", 80);
}

int main() {
    memoryLeakExample();
    danglingPointerExample();
    smartPointerExample();

    return 0;
}
