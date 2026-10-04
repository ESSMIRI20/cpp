#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av)
{
    try
    {
        if (ac < 2)
            throw std::logic_error("Error");

        PmergeMe p(av);

        p.parseInput(ac);

        std::cout << "Before: ";
        std::vector<int> &v = p.getVector();
        for (size_t i = 0; i < v.size(); ++i)
        {
            std::cout << v[i];
            if (i + 1 < v.size())
                std::cout << " ";
        }
        std::cout << std::endl;

        p.sortVector();
        p.sortDeque();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
