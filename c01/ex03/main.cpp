#include "Weapon.hpp"
#include "HumanA.hpp"

int main()
{

    Weapon w;

    // w.setType("klachinkof");
    HumanA a(w, "klachinkof");
    a.attack();
    return (0);
}