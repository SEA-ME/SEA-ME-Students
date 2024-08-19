#include "ContactList.h"

void ContactList::addContact(const Contact &contact) {
    contacts.append(contact);
}

void ContactList::removeContact(const QString &name) {
    for (int i = 0; i < contacts.size(); ++i) {
        if (contacts[i].getName() == name) {
            contacts.removeAt(i);
            return;
        }
    }
}

Contact* ContactList::searchContact(const QString &name) {
    for (int i = 0; i < contacts.size(); ++i) {
        if (contacts[i].getName() == name) {
            return &contacts[i];
        }
    }
    return nullptr;
}

QList<Contact> ContactList::getContacts() const {
    return contacts;
}
