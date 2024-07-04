#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class Contact {
public:
    std::string name;
    std::string PhoneNumber;
    std::string nickname;

    bool bookmarked;

    Contact(std::string name, std::string PhoneNumber, std::string Nickname)
        : name(name), PhoneNumber(PhoneNumber), nickname(Nickname), bookmarked(false) {}
};

class Phonebook {
private:
    std::vector<Contact> contacts;

public:
    void addContact(const std::string &name, const std::string &phoneNumber, const std::string &nickname);
    void searchContacts() const;
    void removeContact();
    void listBookmarkedContacts() const;
    void exitPhonebook() const { exit(0); }
    void bookmarkContact(int index) const;
    bool isPhoneNumberUnique(const std::string &phoneNumber) const;

    void displayContactDetails(int index) const;
};

bool Phonebook::isPhoneNumberUnique(const std::string &phoneNumber) const {
    for (std::vector<Contact>::const_iterator it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->PhoneNumber == phoneNumber) {
            return false;
        }
    }
    return true;
}

void    Phonebook::bookmarkContact(int index) const {
    if (index >= 0 && index < contacts.size()) {
        const_cast<Contact&>(contacts[index]).bookmarked = true;
        std::cout << "Contact bookmarked." << std::endl;
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}

void Phonebook::listBookmarkedContacts() const {
    if (contacts.empty()) {
        std::cout << "No contacts available" << std::endl;
        return;
    }
    std::cout << std::left << std::setw(10) << "Index" 
              << std::setw(20) << "Name" 
              << std::setw(20) << "Phone Number" 
              << std::setw(20) << "Nickname" 
              << std::endl;
    for (size_t i = 0; i < contacts.size(); i++) {
        if (contacts[i].bookmarked) {
            std::cout << std::setw(10) << i 
                      << std::setw(20) << contacts[i].name.substr(0, 16) 
                      << std::setw(20) << contacts[i].PhoneNumber.substr(0, 16) 
                      << std::setw(20) << contacts[i].nickname.substr(0, 16) 
                      << std::endl;
        }
    }
}

void Phonebook::addContact(const std::string &name, const std::string &phoneNumber, const std::string &nickname) {
    for (std::vector<Contact>::const_iterator it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->PhoneNumber == phoneNumber) {
            std::cout << "Phone number must be unique." << std::endl;
            return ;
        }
    }
    contacts.push_back(Contact(name, phoneNumber, nickname));
}

void Phonebook::searchContacts() const {
    if (contacts.empty()) {
        std::cout << "No contacts available" << std::endl;
        return;
    }

    int choice;
    std::cout << "1. By index \n2. Bookmarked list" << std::endl;
    std::cin >> choice;

    if (choice == 1)
    {
        std::cout << std::left << std::setw(10) << "Index" 
              << std::setw(20) << "Name" 
              << std::setw(20) << "Phone Number" 
              << std::setw(20) << "Nickname" 
              << std::endl;
        for (size_t i = 0; i < contacts.size(); i++) {
            std::cout << std::setw(10) << i 
                  << std::setw(20) << contacts[i].name.substr(0, 16) 
                  << std::setw(20) << contacts[i].PhoneNumber.substr(0, 16) 
                  << std::setw(20) << contacts[i].nickname.substr(0, 16) 
                  << std::endl;
            }

        std::cout << "Index? ";
        int index;
        std::cin >> index;

        if (index >= 0 && index < contacts.size()) {
            displayContactDetails(index);
            if (!contacts[index].bookmarked)
            {
                std::cout << "Do you want to bookmark this contact? (y/n): ";
                std::string response;
                std::cin >> response;
                if (response == "y")
                {
                    const_cast<Phonebook*>(this)->bookmarkContact(index);
                }
            } else {
            std::cout << "Invalid index." << std::endl;
            }
        }
    } else if (choice == 2)
        listBookmarkedContacts();
    else
        std::cout << "Invalid choice" << std::endl;
}

void Phonebook::displayContactDetails(int index) const {
    if (index >= 0 && index < contacts.size()) {
        const Contact& contact = contacts[index];
        std::cout << "Name: " << contact.name << std::endl;
        std::cout << "Phone Number: " << contact.PhoneNumber << std::endl;
        std::cout << "Nickname: " << contact.nickname << std::endl;
        std::cout << "Bookmarked: " << (contact.bookmarked ? "Yes" : "No") << std::endl;
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}


void Phonebook::removeContact() {
    if (contacts.empty()) {
        std::cout << "No contacts available" << std::endl;
        return;
    }
    std::cout << std::left << std::setw(10) << "Index" 
        << std::setw(20) << "Name" 
        << std::setw(20) << "Phone Number" 
        << std::setw(20) << "Nickname" 
        << std::endl;
    for (size_t i = 0; i < contacts.size(); i++) {
        std::cout << std::setw(10) << i 
            << std::setw(20) << contacts[i].name.substr(0, 16) 
            << std::setw(20) << contacts[i].PhoneNumber.substr(0, 16) 
            << std::setw(20) << contacts[i].nickname.substr(0, 16) 
            << std::endl;
    std::cout << "Enter the index of the contact you want to remove: ";
    int index;
    std::cin >> index;

    if (std::cin.fail() || index < 0 || index >= contacts.size()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index." << std::endl;
        return;
    }

    contacts.erase(contacts.begin() + index);
}
}

int main(int ac, char **av){
    Phonebook phonebook;
    std::string command;

    if (ac > 1)
    {
        std::cout << "Invalid number of arguments" << std::endl;
        return 1;
    }
    while (1)
    {
        std::cout << "You can use the command ADD, SEARCH, REMOVE, BOOKMARK, EXIT" << std::endl;
        std::cin >> command;

        if (std::cin.eof())
        {
            std::cout << "EOF" << std::endl;
            phonebook.exitPhonebook();
        }

        if (command == "ADD")
        {
            std::string name, phoneNumber, nickname;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            while (true) {
                std::cout << "Enter your name: (max 16 characters): ";
                std::getline(std::cin, name);
                if (name.length() <= 16)
                    break ;
                std::cout << "Name is too long." << std::endl;
            }
            while (true) {
                std::cout << "Enter phone number (max 16 characters, digits only): ";
                std::getline(std::cin, phoneNumber);
                if (phoneNumber.length() <= 16 && std::all_of(phoneNumber.begin(), phoneNumber.end(), ::isdigit)) {
                    if (phonebook.isPhoneNumberUnique(phoneNumber)) {
                        break;
                    } else {
                        std::cout << "Phone number must be unique." << std::endl;
                    }
                } else {
                    std::cout << "Invalid phone number. Please enter a valid phone number." << std::endl;
                }
            }
            while (true) {
                std::cout << "Enter nickname (max 16 characters): ";
                std::getline(std::cin, nickname);
                if (nickname.length() <= 16)
                    break ;
                std::cout << "Nickname is too long. please enter nickname" << std::endl;
            }
            phonebook.addContact(name, phoneNumber, nickname);
        } else if (command == "SEARCH")
            phonebook.searchContacts();
        else if (command == "REMOVE")
            phonebook.removeContact();
        else if (command == "BOOKMARK")
            phonebook.listBookmarkedContacts();
        else if (command == "EXIT")
            phonebook.exitPhonebook();
        else
            std::cout << "Invalid command" << std::endl;
    }
    return 0;
}
