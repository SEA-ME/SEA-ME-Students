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
    {
        std::cout << "-----uniquePtr example-----" << std::endl;
        std::unique_ptr<Car> uniquePtr = std::make_unique<Car>("Ford", 100);
        std::cout << uniquePtr->getName() << std::endl;
    }

    {
        std::cout << "-----sharedPtr example-----" << std::endl;
        std::shared_ptr<Car> sharedPtr1 = std::make_shared<Car>("Kia", 80);
        {
            std::shared_ptr<Car> sharedPtr2 = sharedPtr1;
            std::cout << "Shared pointer use count: " << sharedPtr1.use_count() << std::endl;
        }
        std::cout << "Shared pointer use count after scope: " << sharedPtr1.use_count() << std::endl;
    }

    {
        std::cout << "-----weakPtr example-----" << std::endl;
        std::shared_ptr<Car> sharedPtr1 = std::make_shared<Car>("Kia", 80);
        std::weak_ptr<Car> weakPtr = sharedPtr1;

        if (!weakPtr.lock()) {
            std::cout << "The object has been destroyed." << std::endl;
        }

        std::cout << "Destroy object" << std::endl;
        sharedPtr1.reset();

        if (!weakPtr.lock()) {
            std::cout << "The object has been destroyed." << std::endl;
        }
    }
}

int main() {
    memoryLeakExample();
    danglingPointerExample();
    smartPointerExample();

    return 0;
}
