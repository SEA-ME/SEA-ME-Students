#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <vector>
# include "Contact.hpp"

// error flag
# define INVALID_COMMAND 0
# define INDEX_OUT_OF_RANGE 1

class PhoneBook {
	private :
        std::vector<Contact>	_contacts;
        std::vector<Contact>	_bookmarkedContacts;

        void					printInformation(int idx) const;
        int						getIdxToPrint(void);
        const std::string		putDotIfLong(const std::string& str) const;
        void					removeContact(std::vector<Contact>& contacts, int indexToRemove);
        void					removeContact(std::vector<Contact>& contacts, const std::string& phoneNumberToRemove);
        void					listUpContacts(const std::vector<Contact>& contacts) const;
	public :
        PhoneBook();
        ~PhoneBook();

		void add(void);
		void search(void);
        void remove(void);
        void bookmark(void);
		void printError(int flag) const;
};

#endif
