#include <iostream>
#include <string>
#include <vector>

class Vehicle {
public:
    virtual void drive() = 0; // Pure virtual function abstract class
    virtual ~Vehicle() {} // Virtual destructor
};


class Car : public Vehicle {
private:
    std::string name;
    int speed;
    std::string make;
    std::string model;
    int year;

public:
    Car();
    Car(const std::string &name, int speed, const std::string &make, const std::string &model, int year);
    ~Car();
    Car(const Car &other);
    Car &operator=(const Car &other);

    std::string getName() const { return this->name; }
    int getSpeed() const { return this->speed; }
    std::string getMake() const { return this->make; }
    std::string getModel() const { return this->model; }
    int getYear() const { return this->year; }

    void setName(const std::string &name) { this->name = name; }
    void setSpeed(int speed) { this->speed = speed; }
    void drive() override;
};

Car::Car() : name(""), speed(0), make(""), model(""), year(0) {
    std::cout << "Car created" << std::endl;
}

Car::Car(const std::string &name, int speed, const std::string &make, const std::string &model, int year)
    : name(name), speed(speed), make(make), model(model), year(year) {
    std::cout << "Car parameterized constructor called" << std::endl;
}

Car::~Car() {
    std::cout << "Car destroyed" << std::endl;
}

Car::Car(const Car &other) : name(other.name), speed(other.speed), make(other.make), model(other.model), year(other.year) {
    std::cout << "Car copy constructor called" << std::endl;
}

Car &Car::operator=(const Car &other) {
    if (this != &other)
    {
        name = other.name;
        speed = other.speed;
        make = other.make;
        model = other.model;
        year = other.year;
    }
    std::cout << "Car assignment operator called" << std::endl;
    return *this;
}

void    Car::drive() {
    std::cout << "This car was created by " << getMake() << " in " << getYear() << " and its model is " << getModel() << std::endl;
}

class SportsCar : public Car {
private:
    int topSpeed;

public:
    SportsCar();
    SportsCar(const std::string &name, const int speed, const std::string &make, const std::string &model, const int year, int topSpeed);
    ~SportsCar();
    SportsCar(const SportsCar &other);
    SportsCar &operator=(const SportsCar &other);

    int getTopSpeed() const { return this->topSpeed; }
    void setTopSpeed(int topSpeed) { this->topSpeed = topSpeed; }
};

SportsCar::SportsCar() : Car(), topSpeed(0) {
    std::cout << "SportsCar created" << std::endl;
}

SportsCar::SportsCar(const std::string &name, int speed, const std::string &make, const std::string &model, const int year, int topSpeed)
    : Car(name, speed, make, model, year), topSpeed(topSpeed) {
    std::cout << "SportsCar parameterized constructor called" << std::endl;
}

SportsCar::~SportsCar() {
    std::cout << "SportsCar destroyed" << std::endl;
}

SportsCar::SportsCar(const SportsCar &other) : Car(other), topSpeed(other.topSpeed) {
    std::cout << "SportsCar copy constructor called" << std::endl;
}

SportsCar &SportsCar::operator=(const SportsCar &other) {
    if (this != &other)
    {
        Car::operator=(other);
        topSpeed = other.topSpeed;
    }
    std::cout << "SportsCar assignment operator called" << std::endl;
    return *this;
}

int main()
{
    Car car1("Car1", 100, "Toyota", "Camry", 2020);
    car1.drive();

    SportsCar sportsCar1("Expensive", 200, "BMW", "520D", 2021, 300);
    sportsCar1.drive();

    Vehicle *vehicle1 = &car1;
    Vehicle *vehicle2 = &sportsCar1;

    std::cout << "==========================================================" << std::endl;

    vehicle1->drive();
    vehicle2->drive();

    return 0;
}