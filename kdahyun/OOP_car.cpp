#include <iostream>
#include <string>

class Car {
protected:
    std::string make;
    std::string model;
    int year;

public:
    Car(std::string make, std::string model, int year) : make(make), model(model), year(year) {}

    virtual void drive() {
        std::cout << "Driving " << make << " " << model << " " << year << " edition." << std::endl;
    }

    virtual ~Car() {
        //std::cout << "Car destructor called." << std::endl;
    }
};

class AEB : public Car {
protected:
    bool close_object;
    int steering_angle;

public:
    AEB(const std::string make, const std::string model, const int year, bool close_object, int steering_angle)
        : Car(make, model, year), close_object(close_object), steering_angle(steering_angle) {
    }

    virtual void drive() override {
        Car::drive();
        std::cout << "Status of object is " << close_object << ", steering angle is " << steering_angle<< std::endl;
    }

    virtual void control_steering(){
        if(close_object==true){
            steering_angle+=30;
            close_object = false;
            //steering_angle(steering_angle);
        }
    }

    ~AEB() {
        //std::cout << "SportsCar destructor called." << std::endl;
    }
};

class ABS : public Car {
protected:
    int speed;

public:
    ABS(const std::string make, const std::string model, const int year, int speed)
        : Car(make, model, year), speed(speed) {
    }

    virtual void drive() override {
        Car::drive();
        std::cout << "Speed is " << speed << std::endl;
    }

    virtual void control_speed(){
        if(speed>=200){
            speed-=20;
        }
    }

    ~ABS() {
        //std::cout << "SportsCar destructor called." << std::endl;
    }
};

class Conbination : public ABS, public AEB{
protected:

public:
    Conbination(const std::string make, const std::string model, const int year, bool close_object, int steering, int speed)
        : Car(make, model, year), ABS(close_object,steering), AEB(speed)  {
    }

    void drive() override {
        ABS::drive();
        AEB::drive();
    }

    void control_conbination(){
        AEB::control_steering();
        ABS::control_speed();
    }

    ~SportsCar() {
        //std::cout << "SportsCar destructor called." << std::endl;
    }
};

int main() {
    Car myCar("myCar", "Sonata", 2019);
    myCar.drive();

    AEB mycar_AEB("mycar_AEB", "488 GTB", 2023, true, 0);
    mycar_AEB.drive();
    mycar_AEB.control_steering();
    mycar_AEB.drive();

    ABS mycar_ABS("mycar_ABS", "488 GTB", 2023, 250);
    mycar_ABS.drive();
    mycar_ABS.control_speed();
    mycar_ABS.drive();

    Conbination mycar_Conbination("mycar_ABS", "488 GTB", 2023, true, 0, 250);
    mycar_Conbination.drive();
    mycar_Conbination.control_conbination();
    mycar_Conbination.drive();

    return 0;
}
