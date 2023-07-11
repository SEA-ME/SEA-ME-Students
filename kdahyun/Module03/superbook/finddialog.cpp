#include "finddialog.h"

#include <QtWidgets>

FindDialog::FindDialog(QWidget *parent)
    : QDialog(parent)
{
    QLabel *findLabel = new QLabel(tr("Enter the name of a contact:"));
    nameText = new QLineEdit;

    findButton = new QPushButton(tr("&Find"));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(findLabel);
    layout->addWidget(lineEdit);
    layout->addWidget(findButton);

    setLayout(layout);
    setWindowTitle(tr("Find a Contact"));

    connect(findButton, &QAbstractButton::clicked, this, &QDialog::accept);
}

