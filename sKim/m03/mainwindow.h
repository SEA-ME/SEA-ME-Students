#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ContactList.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddContact();
    void onRemoveContact();
    void onSearchContact();
    void saveContacts();
    void loadContacts();

private:
    Ui::MainWindow *ui;
    ContactList contactList;
};

#endif // MAINWINDOW_H
