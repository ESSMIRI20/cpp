#include "Weapon.hpp"

class HumanA{
    private:
        std::string name;
    public:
        HumanA(Weapon w, std::string type);
        void attack();
};