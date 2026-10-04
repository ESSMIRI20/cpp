#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        AForm *f1 = new ShrubberyCreationForm("home");
        AForm *f2 = new RobotomyRequestForm("Bender");
        AForm *f3 = new PresidentialPardonForm("Arthur");

        bob.signForm(*f1);
        bob.executeForm(*f1);

        bob.signForm(*f2);
        bob.executeForm(*f2);

        bob.signForm(*f3);
        bob.executeForm(*f3);

        delete f1;
        delete f2;
        delete f3;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
