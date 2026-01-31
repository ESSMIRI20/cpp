#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int current_index;
    int total_contacts;

public:
    PhoneBook();
    void add();
    void search();
};

#endif
