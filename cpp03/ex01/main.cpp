#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== ClapTrap Test ===" << std::endl;
    ClapTrap c("Ossama");

    c.attack("Target1");
    c.beRepaired(5);
    c.takeDamage(5);
    c.beRepaired(5);
    c.takeDamage(6);
    c.beRepaired(5);
    c.attack("Target2");

    std::cout << "\n=== ScavTrap Test ===" << std::endl;
    ScavTrap s1("Guardian");

    s1.attack("Enemy1");
    s1.takeDamage(20);
    s1.beRepaired(10);
    s1.guardGate();
    s1.takeDamage(100);
    s1.attack("Enemy2");
    s1.beRepaired(10);

    std::cout << "\n=== ScavTrap Copy Test ===" << std::endl;
    ScavTrap s2 = s1;
    s2.guardGate();
    s2.attack("Enemy3");

    return 0;
}
