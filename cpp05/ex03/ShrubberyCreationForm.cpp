#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    AForm::operator=(other);
    return *this;
}

void ShrubberyCreationForm::executeAction() const {
    std::ofstream out((getTarget() + "_shrubbery").c_str());
    if (!out)
        return;
    out << "       _-_\n" << std::endl;
    out << "    /~~   ~~\\\n" << std::endl;
    out << " /~~         ~~\\\n" << std::endl;
    out << "{               }\n" << std::endl;
    out << " \\  _-     -_  /\n" << std::endl;
    out << "   ~  \\\\ //  ~\n" << std::endl;
    out << "_- -   | | _- _\n" << std::endl;
    out << "  _ -  | |   -_\n" << std::endl;
    out << "      // \\\\\n" << std::endl;
}
