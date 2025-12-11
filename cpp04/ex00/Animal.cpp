#include "Animal.hpp"

Animal::Animal() : type("")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &a)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = a;
}

Animal& Animal::operator=(const Animal &a)
{
    std::cout << "Animal copy assignment called" << std::endl;
    if (this != &a)
        type = a.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound()
{
    std::cout << "Animal sound." << std::endl;
}

std::string Animal::getType()
{
    return (type);
}