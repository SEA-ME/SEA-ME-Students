#include "adddialog.h"

#include <QtWidgets>

//! [0]
// Add 창을 dialog로 만듬
AddDialog::AddDialog(QWidget *parent)
    : QDialog(parent)
{
    nameLabel = new QLabel("Name");
    phoneLabel = new QLabel("PhoneNumber");
    emailLabel = new QLabel("Email");
    bookmarkLabel = new QLabel("Bookmark");  // Checkbox label

    okButton = new QPushButton("OK");
    cancelButton = new QPushButton("Cancel");

    nameText = new QLineEdit;
    phoneText = new QLineEdit;
    emailText = new QLineEdit;
    bookmarkCheckbox = new QCheckBox;

    QGridLayout *gLayout = new QGridLayout;

    gLayout->setColumnStretch(0, 1);
    gLayout->setColumnStretch(1, 1);
    gLayout->setColumnStretch(2, 1);

    gLayout->addWidget(nameLabel, 0, 0);
    gLayout->addWidget(nameText, 0, 1);

    gLayout->addWidget(phoneLabel, 1, 0);
    gLayout->addWidget(phoneText, 1, 1);

    gLayout->addWidget(emailLabel, 2, 0);
    gLayout->addWidget(emailText, 2, 1);
    
    gLayout->addWidget(bookmarkLabel, 3, 0);  // Checkbox label
    gLayout->addWidget(bookmarkCheckbox, 3, 1);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    gLayout->addLayout(buttonLayout, 4, 1, Qt::AlignRight);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);
    setLayout(mainLayout);

    connect(okButton, &QAbstractButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

    setWindowTitle(tr("Add a Contact"));
}
//! [0]
