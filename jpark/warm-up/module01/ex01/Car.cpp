#include "Car.hpp"

#include <iostream>

Car::Car(): make(""), model(""), year(0) {
    std::cout << "Car default constructor called" << std::endl;
}

Car::Car(const Car& other): make(other.make), model(other.model), year(other.year) {
    std::cout << "Car copy constructor called" << std::endl;
}

Car::Car(const std::string& make, const std::string& model, int year)
    : make(make), model(model), year(year) {
    std::cout << "Car member initialization constructor called" << std::endl;
}

Car&	Car::operator=(const Car& other) {
    std::cout << "Car copy assignment operator called" << std::endl;

    if (this != &other) {
        this->make = other.make;
        this->model = other.model;
        this->year = other.year;
    }
    return *this;
}

Car::~Car() {
    std::cout << "Car destructor called" << std::endl;
}

const std::string&	Car::getMake() const {
    std::cout << "Car getter called" << std::endl;
    return this->make;
}

const std::string&	Car::getModel() const {
    std::cout << "Car getter called" << std::endl;
    return this->model;
}

int	Car::getYear() const {
    std::cout << "Car getter called" << std::endl;
    return this->year;
}

void	Car::setMake(const std::string& make) {
    std::cout << "Car setter called" << std::endl;
    this->make = make;
}

void	Car::setModel(const std::string& model) {
    std::cout << "Car setter called" << std::endl;
    this->model = model;
}

void	Car::setYear(int year) {
    std::cout << "Car setter called" << std::endl;
    this->year = year;
}

void	Car::drive() const {
    std::cout << "Driving " << this->make << ' ' << this->model
              << ' ' << this->year << " edition." << std::endl;
}
