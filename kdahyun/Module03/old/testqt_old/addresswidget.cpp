/****************************************************************************
**super important
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "adddialog.h"
#include "addresswidget.h"
#include "finddialog.h"

#include <QtWidgets>

//! [0]
AddressWidget::AddressWidget(QWidget *parent)
    : QTabWidget(parent)
{
    table = new TableModel(this);
    newAddressTab = new NewAddressTab(this);
    connect(newAddressTab, &NewAddressTab::sendDetails,
        this, &AddressWidget::addEntry);

    addTab(newAddressTab, "Phone Book");

    setupTabs();
}
//! [0]

void AddressWidget::showFindEntryDialog()
{
    FindDialog fDialog;

    if (fDialog.exec()) {
        QString name = fDialog.nameText->text();
        //QString address = fDialog.phoneText->toPlainText();

        findEntry(name);
    }

}

//! [2]
void AddressWidget::showAddEntryDialog()
{
    AddDialog aDialog;

    if (aDialog.exec()) {
        QString name = aDialog.nameText->text();
        QString phone_number = aDialog.phoneText->text();
        QString email = aDialog.emailText->text();
        bool bookmarked = aDialog.bookmarkCheckBox->isChecked();

        addEntry(name, phone_number,email);
        /*try again
        if(bookmarked==true)
            addBookEntry(name, address);
            */
    }
}
//! [2]


void AddressWidget::findEntry(QString name)
{

    int rows = table->rowCount(QModelIndex());
    int check = -1;
    for(int i = 0; i < rows; ++i) {
        QModelIndex index_name = table->index(i, 0, QModelIndex());
        QModelIndex index_number = table->index(i, 1, QModelIndex());
        QModelIndex index_number = table->index(i, 2, QModelIndex());

        QString currentName = table->data(index_name, Qt::DisplayRole).toString();
        QString currentNumber = table->data(index_number,Qt::DisplayRole).toString();
        QString currentNumber = table->data(index_email,Qt::DisplayRole).toString();
    
        if (name == currentName) {
            QMessageBox::information(this, tr("Search Name"),
            tr("The name \"%1\" and number \"%2\".").arg(currentName).arg(currentNumber));
            check = 0;
            break;
        }
    }
    
    if (check == -1) {
        QMessageBox::information(this, tr("Search Entry"), tr("The name you entered does not exist in the address book."));
    }

 }

//! [3]
void AddressWidget::addEntry(QString name, QString phone_number, QString email)
{
    if (!table->getContacts().contains({ name, number, email })) {
        table->insertRows(0, 1, QModelIndex());

        QModelIndex index_name = table->index(0, 0, QModelIndex());
        table->setData(index_name, name, Qt::EditRole);
        QModelIndex index_number = table->index(0, 1, QModelIndex());
        table->setData(index_number, number, Qt::EditRole);
        QModelIndex index_email = table->index(0, 2, QModelIndex());
        table->setData(index_email, number, Qt::EditRole);

        removeTab(indexOf(newAddressTab));
    } else {
        QMessageBox::information(this, tr("Duplicate Name"),
            tr("The name \"%1\" already exists.").arg(name));
    }
}
//! [3]

void AddressWidget::addBookEntry(QString name, QString phone_number)
{
    if (!table->getContacts().contains({ name, phone_number })) {
        table->insertRows(0, 1, QModelIndex());

        QModelIndex index = table->index(0, 0, QModelIndex());
        table->setData(index, name, Qt::EditRole);
        index = table->index(0, 1, QModelIndex());
        table->setData(index, phone_number, Qt::EditRole);
        removeTab(indexOf(newAddressTab));
    } else {
        QMessageBox::information(this, tr("Duplicate Name"),
            tr("The name \"%1\" already exists.").arg(name));
    }
}

//! [4a]
void AddressWidget::editEntry()
{
    // currentWidget()은 현재 화면에 보이는 위젯을 포인터로 반환하는 함수입니다.
    QTableView *temp = static_cast<QTableView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    QModelIndexList indexes = selectionModel->selectedRows();
    QString name;
    QString phone_number;
    QString email;

    int row = proxy->mapToSource(indexes.first()).row();
    QModelIndex nameIndex = table->index(row, 0, QModelIndex());
    name = table->data(nameIndex,Qt::DisplayRole).toString();

    QModelIndex phone_numberIndex = table->index(row, 1, QModelIndex());
    phone_number = table->data(phone_numberIndex,Qt::DisplayRole).toString();

    QModelIndex emailIndex = table->index(row, 2, QModelIndex());
    email = table->data(emailIndex,Qt::DisplayRole).toString();
//! [4a]

//! [4b]
    AddDialog aDialog;
    aDialog.setWindowTitle(tr("Edit a Contact"));

    aDialog.nameText->setReadOnly(true);
    aDialog.nameText->setText(name);
    aDialog.phoneText->setText(phone_number);
    aDialog.emailText->setText(email);

    if (aDialog.exec()) {
        QString newNumber = aDialog.phoneText->text();
        QString newEmail = aDialog.emailText->text();
        if (newNumber != phone_number || newEmail != email) {
            QModelIndex phone_index = table->index(row, 1, QModelIndex());
            QModelIndex email_index = table->index(row, 2, QModelIndex());

            table->setData(phone_index, newNumber, Qt::EditRole);
            table->setData(email_index, newEmail, Qt::EditRole);
        }
    }
}
//! [4b]

//! [5]
void AddressWidget::removeEntry()
{
    QTableView *temp = static_cast<QTableView*>(currentWidget());
    QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(temp->model());
    QItemSelectionModel *selectionModel = temp->selectionModel();

    QModelIndexList indexes = selectionModel->selectedRows();

    foreach (QModelIndex index, indexes) {
        int row = proxy->mapToSource(index).row();
        table->removeRows(row, 1, QModelIndex());
    }

    if (table->rowCount(QModelIndex()) == 0) {
        insertTab(0, newAddressTab, "Address Book");
    }
}
//! [5]

//! [1]
void AddressWidget::setupTabs()
{
    // Create a QSortFilterProxyModel.
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(table);

    // Create a QTableView.
    QTableView *tableView = new QTableView;

    // Set the model for the table view.
    tableView->setModel(proxyModel);

    // Set other properties for the table view.
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->horizontalHeader()->setStretchLastSection(true);
    tableView->verticalHeader()->show();
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    tableView->setSortingEnabled(true);

    // Connect signals and slots.
    // &QAction::triggered    &QItemSelectionModel::selectionChanged                   
    connect(tableView->selectionModel(),
        &QItemSelectionModel::selectionChanged,
        this, &AddressWidget::selectionChanged);

    // Add a new tab with the table view.                    
    addTab(tableView, tr("All Contacts"));
}


//! [1]
               
//! [7]
void AddressWidget::readFromFile(const QString &fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("Unable to open file"),
            file.errorString());
        return;
    }

    QList<Contact> contacts;
    QDataStream in(&file);
    in >> contacts;

    if (contacts.isEmpty()) {
        QMessageBox::information(this, tr("No contacts in file"),
                                 tr("The file you are attempting to open contains no contacts."));
    } else {
        for (const auto &contact: qAsConst(contacts))
            addEntry(contact.name, contact.address);
    }
}
//! [7]

//! [6]
void AddressWidget::writeToFile(const QString &fileName)
{
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    }

    QDataStream out(&file);
    out << table->getContacts();
}
//! [6]
