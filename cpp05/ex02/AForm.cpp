#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), isSigned(false), gradeSign(150), gradeExec(150), target("Default") {}

AForm::AForm(const std::string &name, int gradeSign, int gradeExec, const std::string &target)
    : name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec), target(target) {
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned), gradeSign(other.gradeSign), gradeExec(other.gradeExec), target(other.target) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other)
        isSigned = other.isSigned;
    return *this;
}

const std::string &AForm::getName() const { return name; }

const std::string &AForm::getTarget() const { return target; }

bool AForm::getSigned() const { return isSigned; }

int AForm::getGradeSign() const { return gradeSign; }

int AForm::getGradeExec() const { return gradeExec; }

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > gradeSign)
        throw GradeTooLowException();
    isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const {
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeExec)
        throw GradeTooLowException();
    executeAction();
}

const char *AForm::GradeTooHighException::what() const throw() { return "Grade too high"; }
const char *AForm::GradeTooLowException::what() const throw() { return "Grade too low"; }
const char *AForm::FormNotSignedException::what() const throw() { return "Form not signed"; }

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << form.getName() << " [target=" << form.getTarget() << ", signed=" << (form.getSigned() ? "yes" : "no")
       << ", sign=" << form.getGradeSign() << ", exec=" << form.getGradeExec() << "]";
    return os;
}
