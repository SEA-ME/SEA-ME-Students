#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setGeometry(test_game.car0.x,test_game.car0.y,100,100);

    connect(test_game.m_timer, SIGNAL(timeout()), this, SLOT(update()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::carMovement()
{
    if (m_upDir && test_game.speed < test_game.maxSpeed)
    {
        if (test_game.speed < 0)
        {
            test_game.speed += test_game.dec;
        }
        else
        {
            test_game.speed += test_game.acc;
        }
    }

    if (m_downDir && test_game.speed > -test_game.maxSpeed)
    {
        if (test_game.speed > 0)
        {
            test_game.speed -= test_game.dec;
        }
        else
        {
            test_game.speed -= test_game.acc;
        }
    }


    if (!m_upDir && !m_downDir)
    {
        if (test_game.speed - test_game.dec > 0)
        {
            test_game.speed -= test_game.dec;
        }
        else if (test_game.speed + test_game.dec < 0)
        {
            test_game.speed += test_game.dec;
        }
        else
        {
            test_game.speed = 0;
        }
    }


    if (m_rightDir && test_game.speed!=0)
    {
        test_game.angle += test_game.turnSpeed * test_game.speed/test_game.maxSpeed;
    }

    if (m_leftDir && test_game.speed!=0)
    {
        test_game.angle -= test_game.turnSpeed * test_game.speed/test_game.maxSpeed;
    }

    test_game.car0.speed = test_game.speed;
    test_game.car0.angle = test_game.angle;

    for(int i = 0; i < 1; i++)
    {
        test_game.car0.move();
    }
    /*
    for(int i=1; i < test_game.COUNT_OF_CARS ;i++)
    {
        test_game.car[i].findTarget();
    }
    */
}

void MainWindow::update()
{
    carMovement();
    ui->label->setGeometry(test_game.car0.x,test_game.car0.y,100,100);
    std::cout<<"Hello"<<endl;
//    qDebug()<<test_game.car0.x<<test_game.car0.y;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
    case Qt::Key_W:
    {
        m_upDir = true;
    }
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
    {
        m_rightDir = true;
    }
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
    {
        m_downDir = true;
    }
        break;
    case Qt::Key_A:
    case Qt::Key_Left:
    {
        m_leftDir = true;
    }
        break;
    case Qt::Key_Z:
    {
        //renderScene();
    }
        break;
    }
    //QGraphicsScene::keyPressEvent(event);
}
/*
void GameScene::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
    case Qt::Key_W:
    {
        m_upDir = false;
    }
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
    {
        m_rightDir = false;
    }
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
    {
        m_downDir = false;
    }
        break;
    case Qt::Key_A:
    case Qt::Key_Left:
    {
        m_leftDir = false;
    }
        break;
    }
    QGraphicsScene::keyReleaseEvent(event);
}
*/
