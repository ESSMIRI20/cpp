#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& sc_tr);

    ~ScavTrap();

    ScavTrap& operator=(const ScavTrap& sc_tr);

    void attack(const std::string& target);
    void guardGate();
};

#endif
