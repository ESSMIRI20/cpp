#include "ClapTrap.hpp"

int main()
{
    ClapTrap c("ossama");
    c.attack("test1");
    c.beRepaired(5);
    c.takeDamage(5);
    c.beRepaired(5);
    c.takeDamage(6);
    c.beRepaired(5);
    c.attack("test1");
    return (0);
}