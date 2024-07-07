#ifndef RACECAR_HPP
#define RACECAR_HPP

#include "Car.hpp"

class RaceCar: public Car {
private:
    int topSpeed;

public:
    RaceCar();
    RaceCar(const RaceCar& other);
    RaceCar(const std::string& make, const std::string& model, int year, int topSpeed);
    RaceCar& operator=(const RaceCar& other);
    ~RaceCar();

    int		getTopSpeed() const;
    void	setTopSpeed(int topSpeed);

    void drive() const override;
};

#endif
