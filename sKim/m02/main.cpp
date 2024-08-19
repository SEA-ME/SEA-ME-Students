#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>
#include <memory>
#include <vector>

class Part {
public:
    virtual void print() const = 0; // Pure virtual function
    virtual ~Part() = default;      // Virtual destructor
};

class Engine : public Part {
public:
    void print() const override {
        std::cout << "Lamborghini V12 Engine\n";
    }
};

class Wheel : public Part {
public:
    void print() const override {
        std::cout << "Pirelli P Zero Wheel\n";
    }
};

class Brake : public Part {
public:
    void print() const override {
        std::cout << "Carbon Ceramic Brake\n";
    }
};

class Transmission : public Part {
public:
    void print() const override {
        std::cout << "7-speed ISR Transmission\n";
    }
};

class Interior : public Part {
public:
    void print() const override {
        std::cout << "Luxurious Leather Interior\n";
    }
};

class Aerodynamics : public Part {
public:
    void print() const override {
        std::cout << "Active Aerodynamics System\n";
    }
};

class Car {
public:
    Car() {
        engine_ = std::make_unique<Engine>();
        for (int i = 0; i < 4; ++i) {
            wheels_.emplace_back(std::make_unique<Wheel>());
            brakes_.emplace_back(std::make_unique<Brake>());
        }
        transmission_ = std::make_unique<Transmission>();
        interior_ = std::make_unique<Interior>();
        aerodynamics_ = std::make_unique<Aerodynamics>();
    }

    void printParts() const {
        engine_->print();
        for (int i = 0; i < 4; ++i) {
            wheels_[i]->print();
            brakes_[i]->print();
        }
        transmission_->print();
        interior_->print();
        aerodynamics_->print();
    }

private:
    std::unique_ptr<Engine> engine_;
    std::vector<std::unique_ptr<Wheel>> wheels_;
    std::vector<std::unique_ptr<Brake>> brakes_;
    std::unique_ptr<Transmission> transmission_;
    std::unique_ptr<Interior> interior_;
    std::unique_ptr<Aerodynamics> aerodynamics_;
};

int main() {
    Car lamborghiniAventador;
    lamborghiniAventador.printParts();
    return 0;
}
