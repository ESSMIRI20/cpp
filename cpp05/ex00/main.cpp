#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat *b = new Bureaucrat(75);
        std::cout << "Initial grade: " << b->getGrade() << std::endl;

        b->incrementGrade();
        std::cout << "After increment: " << b->getGrade() << std::endl;

        b->decrementGrade();
        std::cout << "After decrement: " << b->getGrade() << std::endl;

        delete b;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "----------------------------" << std::endl;

    try {
        Bureaucrat *bHigh = new Bureaucrat(1);
        std::cout << "Initial grade: " << bHigh->getGrade() << std::endl;

        bHigh->incrementGrade();

        delete bHigh;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "----------------------------" << std::endl;

    try {
        Bureaucrat *bLow = new Bureaucrat(150);
        std::cout << "Initial grade: " << bLow->getGrade() << std::endl;

        bLow->decrementGrade();

        delete bLow;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
