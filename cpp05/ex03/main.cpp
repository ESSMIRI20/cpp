#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Intern someRandomIntern;
        Bureaucrat bob("Bob", 1);

        AForm *form1 = someRandomIntern.makeForm("shrubbery creation", "home");
        AForm *form2 = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm *form3 = someRandomIntern.makeForm("presidential pardon", "Arthur");
        AForm *form4 = someRandomIntern.makeForm("invalid form", "none");

        if (form1) {
            bob.signForm(*form1);
            bob.executeForm(*form1);
        }
        if (form2) {
            bob.signForm(*form2);
            bob.executeForm(*form2);
        }
        if (form3) {
            bob.signForm(*form3);
            bob.executeForm(*form3);
        }

        delete form1;
        delete form2;
        delete form3;
        delete form4;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
