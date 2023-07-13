#include "adddialog.h"
#include "bookmarktab.h"

#include <QtWidgets>

BookmarkTab::BookmarkTab(QWidget *parent)
{
    Q_UNUSED(parent);

    descriptionLabel = new QLabel(tr("There are currently no contacts in your address book. "
                                      "\nClick Add to add new contacts."));

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(descriptionLabel);
    setLayout(mainLayout);
}
