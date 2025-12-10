#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default FragTrap")
{
    hit_point = 100;
    energy_point = 100;
    attack_damage = 30;

    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    hit_point = 100;
    energy_point = 100;
    attack_damage = 30;

    std::cout << "FragTrap parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);

    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (hit_point <= 0)
    {
        std::cout << "FragTrap " << name << " is dead and cannot attack!" << std::endl;
        return;
    }

    if (energy_point <= 0)
    {
        std::cout << "FragTrap " << name << " has no energy to attack!" << std::endl;
        return;
    }

    energy_point--;

    std::cout << "FragTrap " << name << " attacks " << target
              << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests a positive high five!" << std::endl;
}
