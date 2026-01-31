#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "DEBUG level" << std::endl;
}

void Harl::info()
{
    std::cout << "INFO level" << std::endl;
}

void Harl::warning()
{
    std::cout << "WARNING level" << std::endl;
}

void Harl::error()
{
    std::cout << "ERROR level" << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*funcs[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*funcs[i])();
            return;
        }
    }

    std::cout << "[UNKNOWN] Level not recognized.\n";
}