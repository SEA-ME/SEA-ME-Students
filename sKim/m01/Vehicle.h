#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
protected:
    std::string make;
    std::string model;
    int year;

public:
    // Constructor
    Vehicle(const std::string& vehicleMake = "Unknown", const std::string& vehicleModel = "Unknown", int vehicleYear = 0)
        : make(vehicleMake), model(vehicleModel), year(vehicleYear) {}

    // Pure virtual function for driving
    virtual void drive() const = 0;

    // Getter and Setter methods
    std::string getMake() const { return make; }
    void setMake(const std::string& vehicleMake) { make = vehicleMake; }

    std::string getModel() const { return model; }
    void setModel(const std::string& vehicleModel) { model = vehicleModel; }

    int getYear() const { return year; }
    void setYear(int vehicleYear) { year = vehicleYear; }

    // Virtual destructor
    virtual ~Vehicle() {}
};

#endif // VEHICLE_H
