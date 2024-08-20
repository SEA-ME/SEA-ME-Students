#ifndef CAR_H
#define CAR_H

#include <QObject>

class Car : public QObject {
    Q_OBJECT
public:
    explicit Car(int speed, int direction, QObject *parent = nullptr)
        : position(0), speed(speed), direction(direction), QObject(parent) {}

    void move() {
        position += speed * direction;
        emit positionChanged(position);
    }

    int getPosition() const { return position; }

signals:
    void positionChanged(int newPosition);

private:
    int position;
    int speed;
    int direction;
};

#endif // CAR_H
