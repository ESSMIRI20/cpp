#include <iostream>
#include <cstring>

int main(int ac, char **av)
{
    int i;
    size_t j;
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    for (i = 1; i < ac; i++)
    {
        for ( j = 0; j < strlen(av[i]); j++)
            std::cout << (char)toupper(av[i][j]);
    }
    std::cout << std::endl;
    return (0);
}
