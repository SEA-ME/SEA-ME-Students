#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include "Car.h"
#include "SportsCar.h"
#include <vector>
#include <memory>

int main() {
    // Demonstrating Polymorphism with a vector of Vehicles
    std::vector<std::unique_ptr<Vehicle>> vehicles;

    // Adding a Car to the vehicle list
    vehicles.push_back(std::make_unique<Car>("Toyota", "Camry", 2020, 4));

    // Adding a SportsCar to the vehicle list
    vehicles.push_back(std::make_unique<SportsCar>("Ferrari", "488", 2021, 330));

    // Drive all vehicles
    for (const auto& vehicle : vehicles) {
        vehicle->drive();
    }

    return 0;
}
