#include <iostream>
#include <string>

class Basic_info {
protected:
    int steering;
    int speed;
    int brake;

public:
    Basic_info(int steering, int speed, int brake) 
        : steering(steering), speed(speed), brake(brake) {}

    virtual void drive() {
        std::cout << "Steering info : " << steering << ", Speed info : " << speed << ", Brake info : " << brake << std::endl;
    }

    virtual void control() {}

    virtual ~Basic_info() {}
};

class AEB : public Basic_info {
protected:
    bool close_object;

public:
    AEB(int steering, int speed, int brake, bool close_object) 
        : Basic_info(steering, speed, brake), close_object(close_object) {}

    void drive() override {
        Basic_info::drive();
        std::cout << "AEB drive function" << std::endl;
        //print about close_object too
    }

    void control() override {
        if(close_object){
            steering += 30;
            close_object = false;
        }
    }

    ~AEB() override {}
};

class ABS : public Basic_info {
public:
    ABS(int steering, int speed, int brake) : Basic_info(steering, speed, brake) {}

    void drive() override {
        Basic_info::drive();
        control();
    }

    void control() override {
        if(speed >= 200){
            brake += 10;
            speed -= 20;
        }
    }

    ~ABS() override {}
};

class Booster : public Basic_info {
public:
    Booster(int steering, int speed, int brake) : Basic_info(steering, speed, brake) { }

    void drive() override {
        Basic_info::drive();
        control();
    }

    void control() override {
        speed += 50;
    }

    ~Booster() override {}
};

class Car {
private:
    Basic_info* aeb;
public:
    Car(int steering, int speed, int brake, bool close_object) {
        aeb = new AEB(steering, speed, brake, close_object);
    }
    
    void print_Car() {
        aeb->drive();
    }

    void control_Car() {
        aeb->control();
    }
    
    ~Car() {
        delete aeb;
    }
};


class Autonomouscar {
private:
    Basic_info* aeb;
    Basic_info* abs;
public:
    Autonomouscar(int steering, int speed, int brake, bool close_object) {
        aeb = new AEB(steering, speed, brake, close_object);
    }

    void print_Autonomouscar() {
        aeb->drive();
        abs->drive();
    }

    ~Autonomouscar() {
        delete aeb;
        delete abs;
    }
};


class Supercar {
private:
    Basic_info* aeb;
    Basic_info* abs;
    Basic_info* booster;

public:
    Supercar(int steering, int speed, int brake, bool close_object) {
        aeb = new AEB(steering, speed, brake, close_object);
        abs = new ABS(steering, speed, brake);
        booster = new Booster(steering, speed, brake);
    }
    
    void print_Car() {
        aeb->drive();
        abs->drive();
        booster->drive();
    }
    
    ~Supercar() {
        delete aeb;
        delete abs;
        delete booster;
    }
};


int main() {
    // ...
    Car mycar_Conbination(0, 200,0, true);
    mycar_Conbination.print_Car();
    mycar_Conbination.control_Car();
    mycar_Conbination.print_Car();

    return 0;
}