#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Contact {
    public:
    string name;
    string phoneNumber;
    string nickname;
    bool isBookmarked;

    Contact(string n, string p, string nn){
        name = n;
        phoneNumber = p;
        nickname = nn;
        isBookmarked = false;
    }
};

class PhoneBook {
    private:
    vector<Contact> contacts;

    public:
    void add();
    void search();
    void remove();
    void bookmark();
    void exit();
};

void PhoneBook::add()
{
    string name, phoneNumber, nickname;

    cout << "Name: ";
    getline(cin, name);
    cout << "Phone Number: ";
    getline(cin, phoneNumber);

    for (int i = 0;i < contacts.size();i++)
    {
        if(phoneNumber.compare(contacts[i].phoneNumber))
        {
            cout << "Error: Already have this number." << endl;
            return;
        }
    }
    
    cout << "Nickname: ";
    getline(cin, nickname);

    contacts.emplace_back(name, phoneNumber, nickname);
    cout << "Contact added successfully." << endl;
}

void PhoneBook::search()
{
    if (contacts.empty())
    {
        cout << "Phonebook is empty." << endl;
        return;
    }

    cout << "[Contacts List]" << endl;
    for (int i = 0; i < contacts.size(); i++)
    {
        cout << "[" << i+1 << "]    " << contacts[i].name << "(" << contacts[i].nickname << ")" << endl;
    }
    
    int mode, index;
    cout << "Enter mode detail(1) or bookmark(2): ";
    cin >> mode;
    cin.ignore();

    if (mode == 1)
    {
        cout << "Enter index to view details (0 to cancel): ";
        cin >> index;
        cin.ignore();

        if (index > 0 && index <= contacts.size())
        {
            cout << "[" << index << "]    " << contacts[index-1].name << "(" << contacts[index-1].nickname << ")  " << contacts[index-1].phoneNumber;
        }
    }
    else if (mode == 2)
    {
        cout << "Enter index to bookmark (0 to cancel): ";
        cin >> index;
        cin.ignore();

        if (index > 0 && index <= contacts.size())
        {
            contacts[index-1].isBookmarked = true;
            cout << contacts[index-1].name << "(" << contacts[index-1].nickname << ")" << " is bookmarked!" << endl;
        }
        
    }
}

void PhoneBook::remove()
{
    if (contacts.empty())
    {
        cout << "Phonebook is empty." << endl;
        return;
    }

    string input;
    cout << "Enter index or phone number to remove(ONLY NUMBER): ";
    getline(cin, input);

    if (stoi(input) > 0 && stoi(input) < contacts.size())
    {
        contacts.erase(contacts.begin() + stoi(input) - 1);
        cout << "Contact removed successfully." << endl;
    }
    else
    {
        bool find = false;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (input == contacts[i].phoneNumber)
            {
                cout << "[" << i << "]  " << contacts[i].name << "(" << contacts[i].nickname << ")   " << contacts[i].phoneNumber << endl;
            }
        }
    }
}

void PhoneBook::bookmark()
{
    if (contacts.empty())
    {
        cout << "Phonebook is empty." << endl;
        return;
    }

    int marking = 0;

    for (int i = 0; i < contacts.size(); i++)
    {
        if (contacts[i].isBookmarked == true)
        {
            cout << contacts[i].name << "(" << contacts[i].nickname << ")   " << contacts[i].phoneNumber << endl;
            marking += 1;
        }
    }

    if (marking == 0)
    {
        cout << "No bookmark" << endl;
    }
}

void PhoneBook::exit()
{
    cout << "Exiting the program." << endl;
}

int main()
{
    PhoneBook phonebook;
    string command;

    while (true)
    {
        cout << "Enter a command (ADD(1), SEARCH(2), REMOVE(3), BOOKMARK(4), EXIT(5)): ";
        getline(cin, command);
        //cout << command << endl;

        if (command.compare("ADD"))
        {
            phonebook.add();
            break;
        }
        else if (command.compare("SEARCH"))
        {
            phonebook.search();
            break;
        }
        else if (command.compare("REMOVE"))
        {
            phonebook.remove();
            break;
        }
        else if (command.compare("BOOKMARK"))
        {
            phonebook.bookmark();
            break;
        }
        else if (command.compare("EXIT"))
        {
            phonebook.exit();
            break;
        }
        else
        {
            cout << "Invalid command. Please try again." << endl;
            break;
        }
    }

    return 0;
}