#include "iter.hpp"

void increment(int &x)
{
    x++;
}

void print(const int &x)
{
    std::cout << x << " ";
}

int main()
{
    int arr[] = {1, 2, 3, 4};

    std::cout << "Original: ";
    iter(arr, 4, print);
    std::cout << std::endl;

    iter(arr, 4, increment);

    std::cout << "After increment: ";
    iter(arr, 4, print);
    std::cout << std::endl;


    const int carr[] = {10, 20, 30};

    std::cout << "Const array: ";
    iter(carr, 3, print);
    std::cout << std::endl;

    return 0;
}