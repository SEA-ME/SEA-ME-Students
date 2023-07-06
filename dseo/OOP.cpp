#include <iostream>
#include <string>

class Car {
protected:
    std::string make;
    std::string model;
    int year;

public:
    Car(std::string make, std::string model, int year) : make(make), model(model), year(year) {}

    void drive() {
        std::cout << "Driving " << make << " " << model << " " << year << " edition." << std::endl;
    }

    virtual ~Car() {}
};

class AEB : public Car {
protected:
    bool close_object;
    int steering_angle;

public:
    AEB(const std::string make, const std::string model, const int year, bool close_object, int steering_angle)
        : Car(make, model, year), close_object(close_object), steering_angle(steering_angle) {}

    void drive_AEB() {
        std::cout << "Status of object is " << close_object << ", steering angle is " << steering_angle << std::endl;
    }

    void control_steering() {
        if(close_object == true){
            steering_angle += 30;
            close_object = false;
        }
    }

    ~AEB() {}
};

class ABS : public Car {
protected:
    int speed;

public:
    ABS(const std::string make, const std::string model, const int year, int speed)
        : Car(make, model, year), speed(speed) {}

    void drive_ABS() {
        std::cout << "Speed is " << speed << std::endl;
    }

    void control_speed() {
        if(speed >= 200){
            speed -= 20;
        }
    }

    ~ABS() {}
};

class Conbination : public Car {
protected:
    AEB aeb;
    ABS abs;

public:
    Conbination(const std::string make, const std::string model, const int year, bool close_object, int steering, int speed)
        : Car(make, model, year), aeb(make, model, year, close_object, steering), abs(make, model, year, speed) {}

    void drive() {
        Car::drive();
        aeb.drive_AEB();
        abs.drive_ABS();
    }

    void control_conbination() {
        aeb.control_steering();
        abs.control_speed();
    }

    ~Conbination() {}
};

int main() {
    // ...
    Conbination mycar_Conbination("mycar_ABS", "488 GTB", 2023, true, 0, 250);
    mycar_Conbination.drive();
    mycar_Conbination.control_conbination();
    mycar_Conbination.drive();
    return 0;
}
