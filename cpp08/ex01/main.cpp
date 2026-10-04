#include "Span.hpp"
#include <ctime>

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
     std::srand(std::time(NULL));

    // Span sp(10000);
    // sp.addNumber(6);
    // sp.addNumber(3);
    // sp.addNumber(17);
    // sp.addNumber(9);
    // sp.addNumber(11);

    // std::vector<int> v;
    // v.reserve(10000);

    // for (int i = 0; i < 10000; i++)
    // {
    //     int n = std::rand();
    //     v.push_back(n);
    // }

    // sp.addRange(v.begin(), v.end());

    // std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    // std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    return 0;
}