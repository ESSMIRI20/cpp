#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false),
      gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& f)
    : name(f.name), isSigned(f.isSigned),
      gradeToSign(f.gradeToSign), gradeToExecute(f.gradeToExecute) {}

Form::~Form() {}

Form& Form::operator=(const Form& f)
{
    if (this != &f)
        this->isSigned = f.isSigned; // const members can't be assigned
    return *this;
}

// Getters
const std::string& Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getGradeToSign() const { return gradeToSign; }
int Form::getGradeToExecute() const { return gradeToExecute; }

// Signing logic
void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade too low";
}

// Operator <<
std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form " << f.getName()
       << " | signed: " << f.getIsSigned()
       << " | grade to sign: " << f.getGradeToSign()
       << " | grade to execute: " << f.getGradeToExecute();
    return os;
}
