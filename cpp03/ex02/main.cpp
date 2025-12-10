#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "=== ClapTrap Test ===" << std::endl;
    ClapTrap c("Ossama");
    c.attack("Target1");
    c.beRepaired(5);
    c.takeDamage(5);

    std::cout << "\n=== ScavTrap Test ===" << std::endl;
    ScavTrap s("Guardian");
    s.attack("Enemy1");
    s.takeDamage(20);
    s.beRepaired(10);
    s.guardGate();

    std::cout << "\n=== FragTrap Test ===" << std::endl;
    FragTrap f("Fraggy");
    f.attack("Monster1");
    f.takeDamage(30);
    f.beRepaired(20);
    f.highFivesGuys();

    std::cout << "\n=== Copy Test ===" << std::endl;
    FragTrap f2 = f;  // Copy constructor
    f2.attack("Monster2");

    return 0;
}
