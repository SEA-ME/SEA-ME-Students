#ifndef RACINGGAME_H
#define RACINGGAME_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>
#include <QList>
#include "Car.h"
#include "RaceTrack.h"
#include "CarThread.h"

class RacingGame : public QMainWindow {
    Q_OBJECT

public:
    RacingGame(QWidget *parent = nullptr)
        : QMainWindow(parent), raceTrack(new RaceTrack(1000, 900)) {

        QVBoxLayout *layout = new QVBoxLayout;

        QPushButton *startButton = new QPushButton("Start Race", this);
        QPushButton *pauseButton = new QPushButton("Pause Race", this);
        QPushButton *exitButton = new QPushButton("Exit Game", this);

        layout->addWidget(startButton);
        layout->addWidget(pauseButton);
        layout->addWidget(exitButton);

        QWidget *centralWidget = new QWidget(this);
        centralWidget->setLayout(layout);
        setCentralWidget(centralWidget);

        connect(startButton, &QPushButton::clicked, this, &RacingGame::startRace);
        connect(pauseButton, &QPushButton::clicked, this, &RacingGame::pauseRace);
        connect(exitButton, &QPushButton::clicked, this, &RacingGame::exitGame);
    }

private slots:
    void startRace() {
        // 각 자동차에 대해 스레드를 생성하고 시작
        for (int i = 0; i < 3; ++i) { // 예시로 3대의 자동차 사용
            Car *car = new Car(10 + i * 5, 1); // 각기 다른 속도 설정
            carList.append(car);

            CarThread *carThread = new CarThread(car, raceTrack);
            threadList.append(carThread);

            connect(carThread, &CarThread::carFinished, this, &RacingGame::onCarFinished);

            carThread->start();
        }
    }

    void pauseRace() {
        // 스레드를 일시정지하는 예제 (구현되지 않음)
    }

    void exitGame() {
        QApplication::quit();
    }

    void onCarFinished() {
        // 자동차의 레이스 종료 처리 (구현되지 않음)
    }

private:
    RaceTrack *raceTrack;
    QList<Car*> carList;
    QList<QThread*> threadList;
};

#endif // RACINGGAME_H
