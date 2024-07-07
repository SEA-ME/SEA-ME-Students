#ifndef CAR_HPP
#define CAR_HPP

#include <string>

class Car {
private:
    std::string	make;
    std::string model;
    int			year;

public:
    Car();
    Car(const Car& other);
    Car(const std::string& make, const std::string& model, int year);
    Car& operator=(const Car& other);
    virtual ~Car();

    const std::string&	getMake() const;
    const std::string&	getModel() const;
    int					getYear() const;
    void 				setMake(const std::string& make);
    void 				setModel(const std::string& model);
    void 				setYear(int year);

    virtual void drive() const = 0;
};

#endif
