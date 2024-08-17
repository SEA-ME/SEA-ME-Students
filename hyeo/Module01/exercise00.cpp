#include <iostream>
#include <string>

using namespace std;

class Car {
    private:
    string name;
    int speed;

    public:
    Car (const string& carName = "", int carSpeed = 0){
        name = carName;
        speed = carSpeed;

        cout << "Create Car    [" << name << "]" << endl;
    }

    Car(const Car& other){
        name = other.name;
        speed = other.speed;

        cout << "Copy Car    [" << name << "]" << endl;
    }

    Car& operator=(const Car& other){
        if (this == &other){
            return *this;
        }

        name = other.name;
        speed = other.speed;

        cout << "Copy Car [" << name << "] using Assignment Operator" << endl;

        return *this;
    }

    ~Car(){
        cout << "Destruct Car [" << name << "]" << endl;
    }
};

int main()
{
    Car car1("Volkswagen", 200);
    Car car2 = car1;
    Car car3;
    car3 = car1;

    return 0;
}