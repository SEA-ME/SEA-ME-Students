#include <iostream>
#include <string>

using namespace std;

class Car {
    private:
    string make;
    string model;
    int year;

    public:
    Car (const string& carMake = "", const string& carModel = "", int carYear = 0){
        make = carMake;
        model = carModel;
        year = carYear;

        cout << "Create "<< make << "\t" << model << "\t" << year << endl;
    }

    Car(const Car& other){
        make = other.make;
        model = other.model;
        year = other.year;

        cout << "Copy Car " << make << "\t" << model << "\t" << year << endl;
    }

    Car& operator=(const Car& other){
        if (this == &other){
            return *this;
        }

        make = other.make;
        model = other.model;
        year = other.year;

        cout << "Copy Car " << make << "\t" << model << "\t" << year << " using Assignment Operator" << endl;

        return *this;
    }

    virtual void drive() const {
        cout << "Driving "<< make << "\t" << model << "\t" << year << endl;
    }

    virtual ~Car(){
        cout << "Destruct Car " << make << "\t" << model << "\t" << year << endl;
    }
};

class SportsCar : public Car {
    private:
    int topSpeed;

    public:
    SportsCar(const string& carMake = "", const string& carModel = "", int carYear = 0, int carTopSpeed = 0): Car(carMake, carModel, carYear){
        topSpeed = carTopSpeed;
        cout << "Top speed is " << topSpeed << endl;
    }

    SportsCar(const SportsCar& other) : Car(other){
        topSpeed = other.topSpeed;
    }

    SportsCar& operator=(const SportsCar& other){
        if (this == &other)
        {
            return *this;
        }

        Car::operator=(other);
        topSpeed = other.topSpeed;

        return *this;
    }

    void drive() const override {
        Car::drive();
        cout << "Top speed: " << topSpeed << endl;
    }

    ~SportsCar(){
        cout << "Destruct SportsCar " << endl;
    }
};

int main()
{
    Car car1("Volkswagen", "Jetta", 2010);
    car1.drive();

    SportsCar car2("Porsche", "Taycan", 2020, 230);
    car2.drive();

    Car car3 = car1;
    SportsCar car4 = car2;

    Car car5;
    car5 = car1;

    SportsCar car6;
    car6 = car2;

    return 0;
}