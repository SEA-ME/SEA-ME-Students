#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>
#include <map>
#include <vector>
#include <QString>
#include <QTextStream>

class Contact {
public:
    QString name;
    QString phoneNumber;
    QString nickname;
    bool isBookmarked;

    Contact(QString name, QString phoneNumber, QString nickname) :
        name(name), phoneNumber(phoneNumber), nickname(nickname), isBookmarked(false) {}
};

class Phonebook {
    std::vector<Contact> contacts;

public:
    void addContact(QString name, QString phoneNumber, QString nickname) {
        for (const auto& contact : contacts) {
            if (contact.phoneNumber == phoneNumber) {
                std::cout << "Error: Phone number already exists!\n";
                return;
            }
        }
        contacts.push_back(Contact(name, phoneNumber, nickname));
        std::cout << "Contact added successfully!\n";
    }

    void searchContacts() {
        if (contacts.empty()) {
            std::cout << "No contacts found.\n";
            return;
        }

        std::cout << "Contacts:\n";
        for (size_t i = 0; i < contacts.size(); ++i) {
            std::cout << i + 1 << ". " << contacts[i].name.toStdString() << " (" << contacts[i].nickname.toStdString() << ")\n";
        }

        std::cout << "Choose a contact index to view details or 0 to go back: ";
        size_t index;
        std::cin >> index;

        if (index == 0 || index > contacts.size()) return;

        const Contact& contact = contacts[index - 1];
        std::cout << "Name: " << contact.name.toStdString() << "\n";
        std::cout << "Phone Number: " << contact.phoneNumber.toStdString() << "\n";
        std::cout << "Nickname: " << contact.nickname.toStdString() << "\n";

        std::cout << "Would you like to bookmark this contact? (yes/no): ";
        std::string choice;
        std::cin >> choice;
        if (choice == "yes") {
            contacts[index - 1].isBookmarked = true;
            std::cout << "Contact bookmarked.\n";
        }
    }

    void removeContact() {
        std::cout << "Enter contact index or phone number to remove: ";
        std::string input;
        std::cin >> input;

        bool found = false;
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->phoneNumber.toStdString() == input || std::to_string(std::distance(contacts.begin(), it) + 1) == input) {
                contacts.erase(it);
                std::cout << "Contact removed.\n";
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "Contact not found.\n";
        }
    }

    void listBookmarkedContacts() {
        std::cout << "Bookmarked Contacts:\n";
        for (const auto& contact : contacts) {
            if (contact.isBookmarked) {
                std::cout << contact.name.toStdString() << " (" << contact.phoneNumber.toStdString() << ")\n";
            }
        }
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    Phonebook phonebook;
    std::string command;

    while (true) {
        std::cout << "\nCommands: ADD, SEARCH, REMOVE, BOOKMARK, EXIT\n";
        std::cout << "Enter a command: ";
        std::cin >> command;

        QString qCommand = QString::fromStdString(command);

        if (qCommand == "ADD") {
            QString name, phoneNumber, nickname;
            QTextStream in(stdin);  // QTextStream to read input from stdin

            std::cout << "Enter Name: ";
            name = in.readLine();  // Read a line from input

            std::cout << "Enter Phone Number: ";
            phoneNumber = in.readLine();  // Read a line from input

            std::cout << "Enter Nickname: ";
            nickname = in.readLine();  // Read a line from input

            phonebook.addContact(name, phoneNumber, nickname);

        } else if (qCommand == "SEARCH") {
            phonebook.searchContacts();

        } else if (qCommand == "REMOVE") {
            phonebook.removeContact();

        } else if (qCommand == "BOOKMARK") {
            phonebook.listBookmarkedContacts();

        } else if (qCommand == "EXIT") {
            std::cout << "Exiting the application...\n";
            break;

        } else {
            std::cout << "Unknown command. Please try again.\n";
        }
    }

    return a.exec();
}

