#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45, target) {
    std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    AForm::operator=(other);
    return *this;
}

void RobotomyRequestForm::executeAction() const {
    std::cout << "Bzzzz... bzzzzz... drilling noises..." << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << getTarget() << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed on " << getTarget() << "." << std::endl;
}
