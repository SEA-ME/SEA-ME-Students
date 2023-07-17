
#include "finddialog.h"

#include <QtWidgets>


//! [0]
FindDialog::FindDialog(QWidget *parent)
    : QDialog(parent)
{
    findLabel = new QLabel("Enter the name of a contact:");
    findButton = new QPushButton("Find");

    nameText = new QLineEdit;
    
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(findLabel);
    layout->addWidget(nameText);
    layout->addWidget(findButton);

    setLayout(layout);
    setWindowTitle(tr("Find a Contact"));

    connect(findButton, &QAbstractButton::clicked, this, &QDialog::accept);
}
//! [0]


