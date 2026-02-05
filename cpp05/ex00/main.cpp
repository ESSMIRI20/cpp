#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat b("Alice", 75);
        std::cout << b << std::endl;

        b.incrementGrade();
        std::cout << b << std::endl;

        b.decrementGrade();
        std::cout << b << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "------------------------" << std::endl;

    try {
        Bureaucrat high("Bob", 1);
        high.incrementGrade();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "------------------------" << std::endl;

    try {
        Bureaucrat low("Charlie", 150);
        low.decrementGrade();
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
