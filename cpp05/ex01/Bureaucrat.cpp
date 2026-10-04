#include "Bureaucrat.hpp"
#include "Form.hpp"
Bureaucrat::Bureaucrat() : name("Default"), grade(1) {
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
     if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
    std::cout << "Parameterized constructor called" << std::endl;    
}

Bureaucrat::Bureaucrat(const Bureaucrat& b): name(b.name), grade(b.grade)
{
    std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &b)
        grade = b.grade;
    return (*this);
}

const std::string Bureaucrat::getName() const{
    return (name);
}

int Bureaucrat::getGrade() const{
    return (grade);
}

void Bureaucrat::increment_grade(){
    if (grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::dencrement_grade(){
    if (grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
    return (os);
}
