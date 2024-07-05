#include <iostream>
#include <iomanip>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}

void	PhoneBook::add(void) {
    if (_contacts.size() > 1000) {
        std::cout << "you have exceeded the maximum number of contacts in your phonebook.\nplease remove existing one to add a new one.\n";
        return ;
    }

    std::string input;
    Contact newContact;

    std::cout << "name: ";
    std::getline(std::cin, input);
    newContact.setName(input);

    std::cout << "nickname: ";
    std::getline(std::cin, input);
    newContact.setNickName(input);

    std::cout << "phone number: ";
    std::getline(std::cin, input);
    for (const Contact& contact: _contacts) {
        if (input == contact.getPhoneNumber()) {
            std::cout << "error: duplicated phone number." << std::endl;
            return ;
        }
    }
    newContact.setPhoneNumber(input);

    _contacts.push_back(newContact);
}

void	PhoneBook::search(void) {
	int	idxToPrint;
    char input;

    listUpContacts(_contacts);

    if (_contacts.size() == 0) {
        return ;
    }

    std::cout << "do you want to see a detail of a contact? (y/n): ";
    std::cin >> input;
    std::cin.ignore();
    if (input == 'y' || input == 'Y') {
        idxToPrint = getIdxToPrint();
        if (idxToPrint == -1) {
            return ;
        }
        printInformation(idxToPrint);
        std::cout << "do you want to bookmark this contact? (y/n): ";
        std::cin >> input;
        std::cin.ignore();
        if (input == 'y' || input == 'Y') {
            _bookmarkedContacts.push_back(_contacts[idxToPrint]);
        }
    }
}

void	PhoneBook::remove() {
    char input;

    std::cout << "\n(1)press 1 to remove by an index (2)press 2 to remove by a phone number.\npress any other key to cancle.\ninput: ";
    std::cin >> input;
    std::cin.ignore();

    if (input == '1') {
        int indexToRemove;

        std::cout << "index you want to remove: ";
        std::cin >> indexToRemove;
        std::cin.ignore();

        if (indexToRemove >= 0 && indexToRemove < _contacts.size()) {
            removeContact(_contacts, indexToRemove);
            removeContact(_bookmarkedContacts, indexToRemove);
        } else {
            printError(INDEX_OUT_OF_RANGE);
        }
    } else if (input == '2') {
        std::string phoneNumberToRemove;

        std::cout << "phone number you want to remove: ";
        std::cin >> phoneNumberToRemove;
        std::cin.ignore();
        removeContact(_contacts, phoneNumberToRemove);
        removeContact(_bookmarkedContacts, phoneNumberToRemove);
        std::cout << std::endl;
    }
}

void	PhoneBook::bookmark() {
    std::cout << "\n----- Bookmarked Contacts -----";
    listUpContacts(_bookmarkedContacts);
}

const std::string	PhoneBook::putDotIfLong(const std::string& str) const {
    if (str.length() <= 10) {
        return (str);
    }

    std::string ret(str.substr(0, 10));
	ret[9] = '.';
	return ret;
}

int	PhoneBook::getIdxToPrint(void) {
	int			idxToPrint;

    std::cout << "type index: ";
    std::cin >> idxToPrint;
    std::cin.ignore();

    if (idxToPrint < 0 || idxToPrint >= _contacts.size()) {
		printError(INDEX_OUT_OF_RANGE);
		return -1;
	}
	return idxToPrint;
}

void	PhoneBook::printInformation(int idxToPrint) const {
    std::cout << "\nName: " << _contacts[idxToPrint].getName() << "\n";
    std::cout << "Phone number: " << _contacts[idxToPrint].getPhoneNumber() << "\n";
    std::cout << "Nickname: " << _contacts[idxToPrint].getNickName() << "\n" << std::endl;
}

void	PhoneBook::printError(int flag) const {
	if (flag == INVALID_COMMAND)
        std::cout << "error: invalid command" << std::endl;
	else if (flag == INDEX_OUT_OF_RANGE)
        std::cout << "error: index out of range" << std::endl;
}

void	PhoneBook::removeContact(std::vector<Contact>& contacts, int indexToRemove) {
    std::vector<Contact> newContacts;

    for (size_t i = 0; i < _contacts.size(); i++) {
        if (i != indexToRemove) {
            newContacts.push_back(_contacts[i]);
        }
    }
    contacts = newContacts;
}

void	PhoneBook::removeContact(std::vector<Contact>& contacts, const std::string& phoneNumberToRemove) {
    std::vector<Contact> newContacts;

    for (const Contact& contact: _contacts) {
        if (contact.getPhoneNumber() != phoneNumberToRemove) {
            newContacts.push_back(contact);
        }
    }
    contacts = newContacts;
}

void	PhoneBook::listUpContacts(const std::vector<Contact>& contacts) const {
    std::cout << '\n';
    std::cout << std::setw(10) << "INDEX" << '|';
    std::cout << std::setw(10) << "NAME" << std::endl;

    size_t size = contacts.size();

    for (int i = 0; i < size; i++) {
        std::cout << std::setw(10);
        std::cout << i << '|';
        std::cout << std::setw(10);
        std::cout << putDotIfLong(contacts[i].getName());
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
