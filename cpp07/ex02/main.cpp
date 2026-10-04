#include <iostream>
#include "Array.hpp"

int main()
{
    try
    {
        Array<int> a(5);

        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = i * 10;

        std::cout << "Array a: ";
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << " ";
        std::cout << std::endl;

        Array<int> b = a;

        b[0] = 999;

        std::cout << "Array a after b modification: " << a[0] << std::endl;
        std::cout << "Array b: " << b[0] << std::endl;

        const Array<int> c = a;

        std::cout << "Array c size: " << c.size() << std::endl;

        std::cout << a[100] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}