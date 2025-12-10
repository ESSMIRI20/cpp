#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): name(name)
{}

ClapTrap::ClapTrap(const ClapTrap& cl_tr) :
    name(cl_tr.name),
    hit_point(cl_tr.hit_point),
    energy_point(cl_tr.energy_point),
    attack_damage(cl_tr.attack_damage)
{}

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
