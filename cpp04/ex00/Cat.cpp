#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &a) : Animal()
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = a;
}

Cat& Cat::operator=(const Cat &a)
{
    std::cout << "Cat copy assignment called" << std::endl;
    if (this != &a)
        type = a.type;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound()
{
    std::cout << "meeeeeeowww" << std::endl;
}
