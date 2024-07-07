#include "SportsCar.hpp"

int main() {
    Car car("Volvo", "XC60", 230);

    car.drive();

    SportsCar sportsCar("Ferrari", "Roma", 2023, 340);

    sportsCar.drive();

    return 0;
}
