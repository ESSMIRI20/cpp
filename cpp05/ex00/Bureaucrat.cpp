#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(1) {}

Bureaucrat::~Bureaucrat()
{
    std::cout << "destructur called !" << std::endl;
}

Bureaucrat::Bureaucrat(int grade)
{
    if(grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        this->grade = grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("error : GradeTooHighException");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("error : GradeTooLowException");
}

// Bureaucrat::Bureaucrat(const Bureaucrat& b) name(b.name) {};

const std::string Bureaucrat::getName()
{
    return (name);
}

int Bureaucrat::getGrade()
{
    return (grade);
}

void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

