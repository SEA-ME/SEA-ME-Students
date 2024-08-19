#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "Contact.h"
#include <QList>

class ContactList {
public:
    void addContact(const Contact &contact);
    void removeContact(const QString &name);
    Contact* searchContact(const QString &name);

    QList<Contact> getContacts() const;

private:
    QList<Contact> contacts;
};

#endif // CONTACTLIST_H
