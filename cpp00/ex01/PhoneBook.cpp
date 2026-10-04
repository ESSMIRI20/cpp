#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>

PhoneBook::PhoneBook()
{
    current_index = 0;
    total_contacts = 0;
}

void PhoneBook::add()
{
    std::string fn, ln, nn, pn, ds;

    std::cout << "Enter First Name: ";
    if (!std::getline(std::cin, fn)) return;
    std::cout << "Enter Last Name: ";
    if (!std::getline(std::cin, ln)) return;
    std::cout << "Enter Nickname: ";
    if (!std::getline(std::cin, nn)) return;
    std::cout << "Enter Phone Number: ";
    if (!std::getline(std::cin, pn)) return;
    std::cout << "Enter Darkest Secret: ";
    if (!std::getline(std::cin, ds)) return;

    if (fn.empty() || ln.empty() || nn.empty() || pn.empty() || ds.empty())
    {
        std::cout << "Fields cannot be empty!" << std::endl;
        return;
    }

    contacts[current_index].set_info(fn, ln, nn, pn, ds);
    current_index = (current_index + 1) % 8;
    if (total_contacts < 8)
        total_contacts++;
}

void PhoneBook::search()
{
    if (total_contacts == 0)
    {
        std::cout << "Phonebook is empty!" << std::endl;
        return;
    }

    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    for (int i = 0; i < total_contacts; i++)
        contacts[i].display_summary(i);

    std::cout << "Enter index to view details: ";
    std::string input;
    if (!std::getline(std::cin, input)) return;
    if (input.length() == 1 && std::isdigit(input[0]))
    {
        int idx = input[0] - '0';
        if (idx >= 0 && idx < total_contacts)
            contacts[idx].display_full();
        else
            std::cout << "Invalid index!" << std::endl;
    }
    else
        std::cout << "Invalid input!" << std::endl;
}
