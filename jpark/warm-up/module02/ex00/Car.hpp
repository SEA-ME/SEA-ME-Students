#include <string>

class Car {

private:
    std::string name;
    int 		speed;

public:
    Car();
    Car(const Car& other);
    Car(const std::string& name, int speed);
    Car& operator=(const Car& other);
    ~Car();

    const std::string& getName() const;
    int 				getSpeed() const;
};
