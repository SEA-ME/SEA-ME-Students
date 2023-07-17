#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QPropertyAnimation>
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    game test_game;
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
//    virtual void keyReleaseEvent(QKeyEvent *event) override;

public slots:
    void update();

private:
    void carMovement();
    Ui::MainWindow *ui;
    QPropertyAnimation *animation;
    bool m_upDir, m_rightDir, m_downDir, m_leftDir;
};
#endif // MAINWINDOW_H
