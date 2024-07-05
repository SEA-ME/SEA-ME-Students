#include <iostream>
#include <memory>
#include <string>

class Part {
public:
    virtual void display() = 0;
    virtual ~Part() {}
};

class Motor : public Part {
public:
    Motor() { std::cout << "Motor constructor called" << std::endl; }
    ~Motor() { std::cout << "Motor destructor called" << std::endl; }
    
    void display() override {
        std::cout << "This is Motor Part" << std::endl;
    }
    Motor(const Motor &other) {}
    Motor &operator=(const Motor &other) { return *this; }
};

class WheelAndBrake : public Part {
public:
    WheelAndBrake() { std::cout << "WheelAndBrake constructor called" << std::endl; }
    ~WheelAndBrake() { std::cout << "WheelAndBrake destructor called" << std::endl; }
    
    void display() override {
        std::cout << "This is Wheel and Brake Part" << std::endl;
    }
    WheelAndBrake(const WheelAndBrake &other) {}
    WheelAndBrake &operator=(const WheelAndBrake &other) { return *this; }
};

class Instrument : public Part {
private:
    int speed;
    int rpm;
    int fuel;
    int temp;
    int gear;
    int tripMeter;
    int time;

public:
    Instrument() : speed(0), rpm(0), fuel(0), temp(0), gear(0), tripMeter(0), time(0) {
        std::cout << "Instrument constructor called" << std::endl;
    }
    ~Instrument() { std::cout << "Instrument destructor called" << std::endl; }

    Instrument(const Instrument &other) {
        speed = other.speed;
        rpm = other.rpm;
        fuel = other.fuel;
        temp = other.temp;
        gear = other.gear;
        tripMeter = other.tripMeter;
        time = other.time;
    }

    Instrument &operator=(const Instrument &other) {
        if (this != &other) {
            speed = other.speed;
            rpm = other.rpm;
            fuel = other.fuel;
            temp = other.temp;
            gear = other.gear;
            tripMeter = other.tripMeter;
            time = other.time;
        }
        return *this;
    }

    void display() override {
        std::cout << "Current status - Speed: " << speed
                  << " RPM: " << rpm << " Fuel: " << fuel
                  << " Temp: " << temp << " Gear: " << gear
                  << " Trip Meter: " << tripMeter << " Time: " << time << std::endl;
    }

    // Accessor methods
    int getSpeed() const { return speed; }
    int getRpm() const { return rpm; }
    int getFuel() const { return fuel; }
    int getTemp() const { return temp; }
    int getGear() const { return gear; }
    int getTripMeter() const { return tripMeter; }
    int getTime() const { return time; }
};

class Body : public Part {
public:
    Body() { std::cout << "Body constructor called" << std::endl; }
    ~Body() { std::cout << "Body destructor called" << std::endl; }

    void display() override {
        std::cout << "This is Body Part" << std::endl;
    }
    Body(const Body &other) {}
    Body &operator=(const Body &other) { return *this; }
};

class Transmission : public Part {
public:
    Transmission() { std::cout << "Transmission constructor called" << std::endl; }
    ~Transmission() { std::cout << "Transmission destructor called" << std::endl; }

    void display() override {
        std::cout << "This is Transmission Part" << std::endl; }
    Transmission(const Transmission &other) {}
    Transmission &operator=(const Transmission &other) { return *this; }
};

class MyCar {
private:
    std::shared_ptr<Part> motor;
    std::shared_ptr<Part> wheelAndBrake;
    std::shared_ptr<Part> instrument;
    std::shared_ptr<Part> body;
    std::shared_ptr<Part> transmission;

public:
    MyCar()
        : motor(std::make_shared<Motor>()),
          wheelAndBrake(std::make_shared<WheelAndBrake>()),
          instrument(std::make_shared<Instrument>()),
          body(std::make_shared<Body>()),
          transmission(std::make_shared<Transmission>()) {
        std::cout << "MyCar constructor called" << std::endl;
    }

    ~MyCar() { std::cout << "MyCar destructor called" << std::endl; }

    MyCar(const MyCar &other)
        : motor(other.motor),
          wheelAndBrake(other.wheelAndBrake),
          instrument(other.instrument),
          body(other.body),
          transmission(other.transmission) {
        std::cout << "MyCar copy constructor called" << std::endl; }

    MyCar &operator=(const MyCar &other) {
        if (this != &other) {
            motor = other.motor;
            wheelAndBrake = other.wheelAndBrake;
            instrument = other.instrument;
            body = other.body;
            transmission = other.transmission;
        }
        std::cout << "MyCar assignment operator called" << std::endl;
        return *this;
    }

    void displayParts() {
        motor->display();
        wheelAndBrake->display();
        instrument->display();
        body->display();
        transmission->display();
    }
};