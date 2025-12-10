#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default ScavTrap")
{
    hit_point = 100;
    energy_point = 50;
    attack_damage = 20;

    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    hit_point = 100;
    energy_point = 50;
    attack_damage = 20;

    std::cout << "ScavTrap parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& sc_tr) : ClapTrap(sc_tr)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& sc_tr)
{
    if (this != &sc_tr)
    {
        ClapTrap::operator=(sc_tr);

        hit_point = sc_tr.hit_point;
        energy_point = sc_tr.energy_point;
        attack_damage = sc_tr.attack_damage;
    }
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (hit_point <= 0)
    {
        std::cout << "ScavTrap " << name << " is dead and cannot attack!" << std::endl;
        return;
    }

    if (energy_point <= 0)
    {
        std::cout << "ScavTrap " << name << " has no energy to attack!" << std::endl;
        return;
    }

    energy_point--;

    std::cout << "ScavTrap " << name << " attacks " << target
              << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << name << " has entered Gate Keeper mode!" << std::endl;
}
