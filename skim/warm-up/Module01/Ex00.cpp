#include <iostream>
#include <string>
#include <vector>

class Car {
private:
    std::string name;
    int speed;

public:
    Car();
    Car(const std::string &name, int speed);
    ~Car();
    Car(const Car &other);
    Car &operator=(const Car &other);

    std::string getName() const { return this->name; }
    int getSpeed() const { return this->speed; }

    void setName(const std::string &name) { this->name = name; }
    void setSpeed(int speed) { this->speed = speed; }
};

Car::Car() : name("Very common car"), speed(0) {
    std::cout << "Car created" << std::endl;
}

Car::Car(const std::string &name, int speed)
    : name(name), speed(speed) {
    std::cout << "Car Create Car's name is " << name << " and speed is " << speed << std::endl;
}

Car::~Car() {
    std::cout << "Car destroyed" << std::endl;
}

Car::Car(const Car &other) : name(other.name), speed(other.speed) {
    std::cout << "Car copied" << std::endl;
}

Car &Car::operator=(const Car &other) {
    if (this != &other)
    {
        name = other.name;
        speed = other.speed;
    }
    std::cout << "Car assigned" << std::endl;
    return *this;
}

int main() {
    Car car1("sejokim's luxury car", 420);

    // test the orthodox canonical form
    Car car2(car1); // Copy constructor
    Car car3 = car1; // Copy constructor
    Car car4; // Default constructor
    car4 = car1; // Assignment operator

    // Modify car2
    car2 = Car("Modified car", 200);

    // Create a vector of cars
    std::vector<Car> carVector;
    carVector.push_back(car1);
    carVector.push_back(car2);
    carVector.push_back(car3);
    carVector.push_back(car4);

    // Print the cars in the vector
    for (const Car& car : carVector) {
        std::cout << "Car name: " << car.getName() << ", Speed: " << car.getSpeed() << std::endl;
    }
}