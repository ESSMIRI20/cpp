#include <iostream>
#include <string>

class ClapTrap{
    private:
        std::string name;
        int hit_point;
        int energy_point;
        int attack_damage;
    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& cl_tr);
        ClapTrap& operator=(const ClapTrap& cl_tr);
        ~ClapTrap();
};