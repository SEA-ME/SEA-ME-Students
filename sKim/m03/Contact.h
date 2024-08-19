#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class Contact {
public:
    Contact(const QString &name = "", const QString &phoneNumber = "", const QString &email = "");

    QString getName() const;
    QString getPhoneNumber() const;
    QString getEmail() const;

    void setName(const QString &name);
    void setPhoneNumber(const QString &phoneNumber);
    void setEmail(const QString &email);

private:
    QString name;
    QString phoneNumber;
    QString email;
};

#endif // CONTACT_H
