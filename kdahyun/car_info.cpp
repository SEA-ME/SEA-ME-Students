#include <iostream>
#include <string>

class Car {
    private:
        std::string name;
        int speed;

    public:
        // Constructor
        Car(std::string name, int speed);

        // Copy constructor
        Car(const Car& other);

        // Copy assignment operator
        Car& operator=(const Car& other);

        // Destructor
        ~Car();

        // For display
        void display();
};

Car::Car(std::string name, int speed) : name(name), speed(speed) {}

Car::Car(const Car& other) : name(other.name), speed(other.speed) {}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        name = other.name;
        speed = other.speed;
    }
    return *this;
}

Car::~Car() {}

void Car::display() {
    std::cout << "Name: " << name << ", Speed: " << speed << std::endl;
}

int main() {
    // Create a Car
    Car car1("Toyota", 60);
    car1.display();

    // Create a copy of Car
    Car car2 = car1;
    car2.display();


    // Create another Car and use the assignment operator
    Car car3("Honda", 80);
    car3 = car1;
    car3.display();

    return 0;
}
