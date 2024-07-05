#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

const std::string&	Contact::getName(void) const {
    return _name;
}

const std::string&	Contact::getNickName(void) const {
	return _nickName;
}

const std::string&	Contact::getPhoneNumber(void) const {
    return _phoneNumber;
}

void	Contact::setName(const std::string& name) {
    _name = name;
}

void	Contact::setNickName(const std::string& nickName) {
	_nickName = nickName;
}

void	Contact::setPhoneNumber(const std::string& phoneNumber) {
    _phoneNumber = phoneNumber;
}
