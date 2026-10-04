#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : name("test"), grad_sign(2), grad_exec(2)
{
    std::cout << "Default constructor called ." << std::endl;
}

Form::Form(const std::string& name, int grad_sign, int grad_exec)
    : name(name), isSigned(false),
      grad_sign(grad_sign), grad_exec(grad_exec)
{
    if (grad_sign < 1 || grad_exec < 1)
        throw GradeTooHighException();
    if (grad_sign > 150 || grad_exec > 150)
        throw GradeTooLowException();
    std::cout << "param constructor called ." << std::endl;
}

Form::Form(const Form& f)
    : name(f.name), isSigned(f.isSigned),
      grad_sign(f.grad_sign), grad_exec(f.grad_exec) {
    std::cout << "copy constructor called ." << std::endl;
}

Form::~Form(){
    std::cout << "Destructor called ." << std::endl;
}

Form& Form::operator=(const Form& f)
{
    if (this != &f)
        this->isSigned = f.isSigned;
    std::cout << "Copy assignment operator called ." << std::endl;
    return *this;
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > grad_sign)
        throw GradeTooLowException();
    isSigned = true;
}

const std::string Form::getName() const{
    return name;
}

bool Form::getInd() const{
    return isSigned;
}

int Form::getGrad_exec() const{
    return grad_exec;
}

int Form::getGrad_sign() const{
    return grad_sign;
}

std::ostream& operator<<(std::ostream& os, const Form& f){
    os << f.getName() << ", Form grade sign" << f.getGrad_sign() << ", Form grade exec" << f.getGrad_exec() << "." << std::endl;
    return (os);
}