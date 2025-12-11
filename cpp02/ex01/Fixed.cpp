#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    fixed_point = 0;
}

Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    fixed_point = n << fractional_bits;
}

Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    fixed_point = roundf(f * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed &f){
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &f) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f)
        fixed_point = f.fixed_point;
    return *this;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return fixed_point;
}

void Fixed::setRawBits(int const raw) {
    fixed_point = raw;
}

float Fixed::toFloat() const {
    return (float)fixed_point / (1 << fractional_bits);
}

int Fixed::toInt() const {
    return fixed_point >> fractional_bits;
}

std::ostream& operator<<(std::ostream &out, const Fixed &f) {
    out << f.toFloat();
    return out;
}
