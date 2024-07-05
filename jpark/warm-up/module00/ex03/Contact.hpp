#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {
	private :
        std::string _name;
        std::string _phoneNumber;
        std::string _nickName;

    public :
        Contact();
        ~Contact();

        const std::string	&getName(void) const;
		const std::string	&getNickName(void) const;
		const std::string	&getPhoneNumber(void) const;
        void				setName(const std::string& name);
        void				setNickName(const std::string& nickName);
        void				setPhoneNumber(const std::string& phoneNumber);
};

#endif
