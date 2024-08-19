#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddContact);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::onRemoveContact);
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::onSearchContact);

    loadContacts();  // 프로그램 시작 시 저장된 연락처 불러오기
}

MainWindow::~MainWindow() {
    saveContacts();  // 프로그램 종료 시 연락처 저장
    delete ui;
}

void MainWindow::onAddContact() {
    QString name = ui->nameLineEdit->text();
    QString phoneNumber = ui->phoneLineEdit->text();
    QString email = ui->emailLineEdit->text();

    Contact contact(name, phoneNumber, email);
    contactList.addContact(contact);

    ui->contactListView->addItem(name);  // 연락처 목록에 추가

    ui->nameLineEdit->clear();
    ui->phoneLineEdit->clear();
    ui->emailLineEdit->clear();
}

void MainWindow::onRemoveContact() {
    QString name = ui->nameLineEdit->text();
    contactList.removeContact(name);

    // UI 업데이트 - 연락처 목록에서 항목 제거
    QList<QListWidgetItem*> items = ui->contactListView->findItems(name, Qt::MatchExactly);
    if (!items.empty()) {
        delete items[0];
    }

    ui->nameLineEdit->clear();
    ui->phoneLineEdit->clear();
    ui->emailLineEdit->clear();
}

void MainWindow::onSearchContact() {
    QString name = ui->nameLineEdit->text();
    Contact* contact = contactList.searchContact(name);

    if (contact) {
        ui->phoneLineEdit->setText(contact->getPhoneNumber());
        ui->emailLineEdit->setText(contact->getEmail());
    } else {
        // 검색 결과가 없을 경우 처리
        ui->phoneLineEdit->clear();
        ui->emailLineEdit->clear();
    }
}

void MainWindow::saveContacts() {
    QFile file("contacts.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (const Contact &contact : contactList.getContacts()) {
            out << contact.getName() << "," << contact.getPhoneNumber() << "," << contact.getEmail() << "\n";
        }
        file.close();
    }
}

void MainWindow::loadContacts() {
    QFile file("contacts.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            if (fields.size() == 3) {
                Contact contact(fields[0], fields[1], fields[2]);
                contactList.addContact(contact);
                ui->contactListView->addItem(contact.getName());  // UI 목록에도 추가
            }
        }
        file.close();
    }
}
