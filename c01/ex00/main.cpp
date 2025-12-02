#include "Zombie.hpp"

int main(void)
{
    // Heap allocation - survives outside function scope
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    
    // Stack allocation - destroyed at end of function
    randomChump("StackZombie");
    
    // Manual cleanup for heap zombie
    delete heapZombie;
    
    return (0);
}
