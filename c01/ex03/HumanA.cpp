#include "HumanA.hpp"

HumanA::HumanA(Weapon w, std::string type)
{
    w.setType(type);
}

void HumanA::attack()
{
    std::cout << name + " attacks with their" + w.getType() << endl;
}