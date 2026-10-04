#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    try
    {
        RPN r(av[1]);
        int result = r.calculate();
        std::cout << result << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}