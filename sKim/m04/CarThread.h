#ifndef CARTHREAD_H
#define CARTHREAD_H

#include <QThread>
#include "Car.h"
#include "RaceTrack.h"
#include <QMutex>

class CarThread : public QThread {
    Q_OBJECT
public:
    CarThread(Car *car, RaceTrack *raceTrack, QObject *parent = nullptr)
        : car(car), raceTrack(raceTrack), QThread(parent) {}

    void run() override {
        while (car->getPosition() < raceTrack->getFinishLine()) {
            mutex.lock(); // 동기화 처리
            car->move();
            mutex.unlock();
            msleep(10); // 자동차 움직임 간격
        }
        emit carFinished();
    }

signals:
    void carFinished();

private:
    Car *car;
    RaceTrack *raceTrack;
    QMutex mutex;
};

#endif // CARTHREAD_H
