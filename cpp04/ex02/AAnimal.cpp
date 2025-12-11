#include "AAnimal.hpp"

AAnimal::AAnimal() : type("")
{
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &a)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = a;
}

AAnimal& AAnimal::operator=(const AAnimal &a)
{
    std::cout << "AAnimal copy assignment called" << std::endl;
    if (this != &a)
        type = a.type;
    return (*this);
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType()
{
    return (type);
}