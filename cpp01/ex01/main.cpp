#include "Zombie.hpp"

int main(void)
{
    Zombie* z = zombieHorde(4, "ossama");
    for (int i = 0; i < 4; i++)
    {
        z->announce();
    }

    delete[] z;
    return (0);
}
