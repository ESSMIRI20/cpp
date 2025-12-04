#include <iostream>
#include <string>

class Weapon{
    private:
        std::string type;
    public:
        std::string getType();
        std::string setType(std::string type);
};