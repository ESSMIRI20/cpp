#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : name("Default"), hit_point(10), energy_point(10), attack_damage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): 
    name(name),
    hit_point(10),
    energy_point(10),
    attack_damage(0)
{
    std::cout << "Parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& cl_tr) :
    name(cl_tr.name),
    hit_point(cl_tr.hit_point),
    energy_point(cl_tr.energy_point),
    attack_damage(cl_tr.attack_damage)
{
    std::cout << "copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& cl_tr)
{
    if (this != &cl_tr)
    {
        name = cl_tr.name;
        hit_point = cl_tr.hit_point;
        energy_point = cl_tr.energy_point;
        attack_damage = cl_tr.attack_damage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (hit_point <= 0)
    {
        std::cout << "ClapTrap " << name << " is dead and cannot attack!\n";
        return;
    }
    if (energy_point <= 0)
    {
        std::cout << "ClapTrap " << name << " has no energy to attack!\n";
        return;
    }

    energy_point--;
    std::cout << "ClapTrap " << name << " attacks " << target
              << ", causing " << attack_damage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hit_point -= amount;
    if (hit_point < 0)
        hit_point = 0;

    std::cout << "ClapTrap " << name << " takes " << amount
              << " points of damage! Hit points left: "
              << hit_point << "\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hit_point <= 0)
    {
        std::cout << "ClapTrap " << name << " is dead and cannot be repaired!\n";
        return;
    }
    if (energy_point <= 0)
    {
        std::cout << "ClapTrap " << name << " has no energy to repair!\n";
        return;
    }

    energy_point--;
    hit_point += amount;

    std::cout << "ClapTrap " << name << " repairs itself for "
              << amount << " hit points! New HP: "
              << hit_point << "\n";
}