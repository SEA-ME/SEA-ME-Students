//improve that default copy conscructor is shallow copy
#include <iostream>
#include <string>

class Car {
    private:
        std::string name_;
        int speed_;
        int *m_;

    public:
        // Constructor
        Car(std::string name, int speed, int *m);

        // Destructor
        ~Car();

        // For display
        void display();

        void printM();

        void setM(int idx, int t){m_[idx]=t;}
};

Car::Car(std::string name, int speed, int *m) {
    name_=name;
    speed_=speed;
    m_=new int[5];
    std::copy(m,m+5,m_);
}


Car::~Car() {}

void Car::display() {
    std::cout << "Name: " << name_ << ", Speed: " << speed_ << std::endl;
}

void Car::printM(){
    for(int i=0;i<5;i++){std::cout<<m_[i]<<" ";}
    std::cout<<std::endl;
}

int main() {
    // Create a Car
    int arr[5]={0,1,2,3,4};
    Car car1("Toyota", 60, arr);
    car1.display();
    car1.printM();

    // Create a copy of Car
    Car car2 = car1;
    car2.display();
    car2.printM();

    car2.setM(2,80);
    std::cout<<"After the change of m"<<std::endl;
    car2.printM();
    car1.printM();

    return 0;
}
