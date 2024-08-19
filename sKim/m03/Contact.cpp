#include "Contact.h"

Contact::Contact(const QString &name, const QString &phoneNumber, const QString &email)
    : name(name), phoneNumber(phoneNumber), email(email) {}

QString Contact::getName() const {
    return name;
}

QString Contact::getPhoneNumber() const {
    return phoneNumber;
}

QString Contact::getEmail() const {
    return email;
}

void Contact::setName(const QString &name) {
    this->name = name;
}

void Contact::setPhoneNumber(const QString &phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Contact::setEmail(const QString &email) {
    this->email = email;
}
