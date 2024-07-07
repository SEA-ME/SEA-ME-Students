#ifndef SPORTSCAR_HPP
#define SPORTSCAR_HPP

#include "Car.hpp"

class SportsCar: public Car {
private:
    int topSpeed;

public:
    SportsCar();
    SportsCar(const SportsCar& other);
    SportsCar(const std::string& make, const std::string& model, int year, int topSpeed);
    SportsCar& operator=(const SportsCar& other);
    ~SportsCar();

    int	getTopSpeed() const;

    void	setTopSpeed(int topSpeed);

    void drive() const;
};

#endif
