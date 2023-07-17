#include <iostream>
#include <vector>
#include <map>

struct Contact {
    std::string name;
    std::string phoneNumber;
    std::string nickname;
    bool isBookmarked;
};

std::vector<Contact> phonebook;
std::map<std::string, int> phoneMap;

void add() {
    Contact newContact;
    std::string bookmark_status;
    std::cout << "Enter Name: ";
    std::cin.ignore();
    getline(std::cin, newContact.name);
    std::cout << "Enter Phone number: ";
    std::cin >> newContact.phoneNumber;

    // check if the phone number already exists
    if (phoneMap.find(newContact.phoneNumber) != phoneMap.end()) {
        std::cout << "Error: This phone number already exists. Try a different number.\n";
        return;
    }

    std::cout << "Enter Nickname: ";
    std::cin >> newContact.nickname;
    std::cout << "Bookmark Status(y/n): ";
    std::cin >> bookmark_status;

    if(bookmark_status=="y")
        newContact.isBookmarked = true;
    else
        newContact.isBookmarked = false;

    phonebook.push_back(newContact);
    phoneMap[newContact.phoneNumber] = phonebook.size() - 1;
}


void search() {
    std::string searchQuery;
    std::cout << "Enter Name or Phone Number: ";
    std::cin >> searchQuery;

    for (int i = 0; i < phonebook.size(); ++i) {
        if (phonebook[i].name == searchQuery || phonebook[i].phoneNumber == searchQuery) {
            std::cout << "index : "<<i<<" name : "<< phonebook[i].name <<  std::endl;
        }
    }

    int index;
    std::cout << "Enter Index to View Details: ";
    std::cin >> index;

    if (index >= 0 && index < phonebook.size()) {
        std::cout << "Name: " << phonebook[index].name << std::endl;
        std::cout << "Phone Number: " << phonebook[index].phoneNumber << std::endl;
        std::cout << "Nickname: " << phonebook[index].nickname << std::endl;

        std::string bookmark;
        std::cout << "Would you like to bookmark this contact? (y/n): ";
        std::cin >> bookmark;

        if (bookmark == "y") {
            phonebook[index].isBookmarked = true;
        }
    }
    else {
        std::cout<<"Wrong index. Search again"<< std::endl;
    }
}

void remove() {
    std::string removalQuery;
    std::cout << "Enter Index or Phone Number to Remove: ";
    std::cin >> removalQuery;

    if (phoneMap.find(removalQuery) != phoneMap.end()) {
        int index = phoneMap[removalQuery];
        phonebook.erase(phonebook.begin() + index);
        phoneMap.erase(removalQuery);
    } 
    else {
        std::cout<<"There is any information in this phonebook"<< std::endl;
        /*
        int index = std::stoi(removalQuery);
        if (index >= 0 && index < phonebook.size()) {
            phoneMap.erase(phonebook[index].phoneNumber);
            phonebook.erase(phonebook.begin() + index);
        }*/
    }
}

void bookmark() {
    for (int i = 0; i < phonebook.size(); ++i) {
        if (phonebook[i].isBookmarked) {
            std::cout << i << ". " << phonebook[i].name << phonebook[i].phoneNumber << std::endl;
        }
    }
}

int main() {
    std::string command;
    while (command != "EXIT") {
        std::cout << "Enter command (ADD, SEARCH, REMOVE, BOOKMARK, EXIT): ";
        std::cin >> command;
        if (command == "ADD") {
            add();
        } else if (command == "SEARCH") {
            search();
        } else if (command == "REMOVE") {
            remove();
        } else if (command == "BOOKMARK") {
            bookmark();
        } else if (command != "EXIT") {
            std::cout << "Invalid command!" << std::endl;
        }
    }

    return 0;
}
