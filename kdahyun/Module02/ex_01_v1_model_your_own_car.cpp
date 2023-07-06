#include <iostream>

// The abstract Part class
class Part {
public:
    virtual void print() {
        std::cout << "1" << std::endl;
    }; 
};

// The Engine class
class Engine : public Part {
public:
    void print() override {
        std::cout << "Mercedes-Benz S-Class Engine\n";
    }
};

// The Wheel class
class Wheel : public Part {
public:
    void print() override {
        std::cout << "Mercedes-Benz S-Class Wheel\n";
    }
};

// The Brake class
class Brake : public Part {
public:
    void print() override {
        std::cout << "Mercedes-Benz S-Class Brake\n";
    }
};

// The Transmission class
class Transmission : public Part {
public:
    void print() override {
        std::cout << "Mercedes-Benz S-Class Transmission\n";
    }
};

// The Light class
class Light : public Part {
public:
    void print() override {
        std::cout << "Mercedes-Benz S-Class Light\n";
    }
};

// The Car class
class Car {
private:
    Part* part;
    Engine* engine;
    Wheel* wheels;
    Brake* brakes;
    Transmission* transmission;
    Light* lights;

public:
    Car() {
        part = new Engine();
        engine = new Engine();
        wheels = new Wheel[4];
        brakes = new Brake[4];
        transmission = new Transmission();
        lights = new Light[6];
    }

    void printParts() {
        engine->print();
        part->print();
        std::cout << "hello" << std::endl;
        for (int i = 0; i < 4; ++i) {
            wheels[i].print();
            brakes[i].print();
        }
        transmission->print();
        for (int i = 0; i < 6; ++i) {
            lights[i].print();
        }
    }

    ~Car() {
        delete engine;
        delete [] wheels;
        delete [] brakes;
        delete transmission;
        delete [] lights;
    }
};

int main() {
    Car Mercedes_S_Class;
    Mercedes_S_Class.printParts();

    return 0;
}
