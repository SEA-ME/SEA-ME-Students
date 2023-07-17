#ifndef CAR_H
#define CAR_H
#include <cmath>

class Car
{
public:
    Car();
    float x,y,speed,angle;
    void move(){
        x += sin(angle) * speed;
        y -= cos(angle) * speed;
        
    }
};

#endif // CAR_H
