#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = a;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &a)
{
    std::cout << "WrongAnimal copy assignment called" << std::endl;
    if (this != &a)
        type = a.type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound()
{
    std::cout << "WrongAnimal sound." << std::endl;
}

std::string WrongAnimal::getType()
{
    return (type);
}