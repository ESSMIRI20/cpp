#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
    private:
        std::string name;
    public:
        void setName(std::string name);
        ~Zombie(void);
        void    announce(void);
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);
Zombie* newZombie(std::string name);
Zombie* zombieHorde(int N, std::string name);

#endif
