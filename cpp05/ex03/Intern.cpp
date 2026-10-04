#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

static AForm *createShrubbery(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(const std::string &target) {
    return new RobotomyRequestForm(target);
}

static AForm *createPardon(const std::string &target) {
    return new PresidentialPardonForm(target);
}

Intern::Intern() {}
Intern::Intern(const Intern &other) { (void)other; }
Intern::~Intern() {}
Intern &Intern::operator=(const Intern &other) { (void)other; return *this; }

AForm *Intern::makeForm(const std::string &name, const std::string &target) const {
    struct FormType {
        const char *name;
        AForm *(*create)(const std::string &);
    }
    forms[] = {
        {"shrubbery creation", createShrubbery},
        {"robotomy request", createRobotomy},
        {"presidential pardon", createPardon}
    };

    for (int i = 0; i < 3; ++i) {
        if (name == forms[i].name) {
            AForm *form = forms[i].create(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }

    std::cout << "Intern could not create form \"" << name << "\"" << std::endl;
    return NULL;
}
