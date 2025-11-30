#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook pb;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) break;
        if (command == "ADD")
            pb.add();
        else if (command == "SEARCH")
            pb.search();
        else if (command == "EXIT")
            break;
    }
    return (0);
}
