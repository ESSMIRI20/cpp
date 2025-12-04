#include "Zombie.hpp"

int main(void)
{
    Zombie* heapZombie = newZombie("test1");
    heapZombie->announce();
    
    randomChump("test2");
    
    delete heapZombie;
    
    return (0);
}
