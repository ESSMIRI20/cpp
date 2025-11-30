#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact {
private:
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;

    std::string truncate(std::string str);

public:
    void set_info(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
    void display_summary(int index);
    void display_full();
};

#endif
