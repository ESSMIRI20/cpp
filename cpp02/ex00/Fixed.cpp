#include "Fixed.hpp"

Fixed::Fixed(){
    std::cout << "Default constructor called" << std::endl;
    fixed_point = 0;
}

Fixed::Fixed(Fixed &f){
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &f){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f)
        fixed_point = f.fixed_point;
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (fixed_point);
}

void Fixed::setRawBits(int const raw)
{
    fixed_point = raw;
}

const int Fixed::fractional_bits = 8;