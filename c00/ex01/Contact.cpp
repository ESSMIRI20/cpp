#include "Contact.hpp"

void Contact::set_info(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
    first_name = fn;
    last_name = ln;
    nick_name = nn;
    phone_number = pn;
    darkest_secret = ds;
}

std::string Contact::truncate(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void Contact::display_summary(int index)
{
    std::cout << "|" << std::setw(10) << index
              << "|" << std::setw(10) << truncate(first_name)
              << "|" << std::setw(10) << truncate(last_name)
              << "|" << std::setw(10) << truncate(nick_name) << "|" << std::endl;
}

void Contact::display_full()
{
    std::cout << "First Name: " << first_name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nick_name << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}
