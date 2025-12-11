#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &a) : Animal()
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = a;
}

Dog& Dog::operator=(const Dog &a)
{
    std::cout << "Dog copy assignment called" << std::endl;
    if (this != &a)
        type = a.type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound()
{
    std::cout << "Dog sound " << std::endl;
}
