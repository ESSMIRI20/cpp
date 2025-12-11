#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &a) : WrongAnimal()
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = a;
}

WrongCat& WrongCat::operator=(const WrongCat &a)
{
    std::cout << "WrongCat copy assignment called" << std::endl;
    if (this != &a)
        type = a.type;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound()
{
    std::cout << "meeeeeeowww" << std::endl;
}
