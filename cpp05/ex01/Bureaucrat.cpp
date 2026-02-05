#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : name("Default"), grade(1) {
    std::cout << "Default constructor called" << std::endl;
}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
    std::cout << "Parameterized constructor called" << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& b)
    : name(b.name), grade(b.grade)
{
    std::cout << "Copy constructor called" << std::endl;
}

// Destructor
Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called" << std::endl;
}

// Assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b) {
    if (this != &b)
        this->grade = b.grade; // name is const
    return *this;
}

// Getters
const std::string& Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

// Increment grade (higher rank)
void Bureaucrat::incrementGrade() {
    if (grade <= 1)
        throw GradeTooHighException();
    grade--;
}

// Decrement grade (lower rank)
void Bureaucrat::decrementGrade() {
    if (grade >= 150)
        throw GradeTooLowException();
    grade++;
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low";
}

// Operator <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}

void Bureaucrat::signForm(Form& f)
{
    try {
        f.beSigned(*this);
        std::cout << name << " signed " << f.getName() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << name << " couldn't sign "
                  << f.getName() << " because "
                  << e.what() << std::endl;
    }
}