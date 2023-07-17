#include "adddialog.h"
#include "newaddresstab.h"

#include <QtWidgets>

NewAddressTab::NewAddressTab(QWidget *parent)
{
    Q_UNUSED(parent);

    descriptionLabel = new QLabel(tr("There are currently no contacts in your address book. "
                                      "\nClick Add to add new contacts."));

    addButton = new QPushButton(tr("Add"));

    connect(addButton, &QAbstractButton::clicked, this, &NewAddressTab::addEntry);

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(descriptionLabel);
    mainLayout->addWidget(addButton, 0, Qt::AlignCenter);

    setLayout(mainLayout);
}

void NewAddressTab::addEntry()
{
    AddDialog aDialog;

    if (aDialog.exec()) {
        QString name = aDialog.nameText->text();
        QString phone_number = aDialog.phoneText->text();
        QString email = aDialog.emailText->text();
        bool bookmarked = aDialog.bookmarkCheckbox->isChecked(); // Updated

        emit sendDetails(name, phone_number, email, bookmarked); // Updated
    }
}
