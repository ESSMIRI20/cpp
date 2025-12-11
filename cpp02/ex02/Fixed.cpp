#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

Fixed::Fixed() : fixed_point(0) {}

Fixed::Fixed(const int n) {
    fixed_point = n << fractional_bits;
}

Fixed::Fixed(const float f) {
    fixed_point = (int)roundf(f * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed &f) {
    *this = f;
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed &f) {
    if (this != &f)
        fixed_point = f.fixed_point;
    return *this;
}

int Fixed::getRawBits(void) const {
    return fixed_point;
}

void Fixed::setRawBits(int const raw) {
    fixed_point = raw;
}

float Fixed::toFloat(void) const {
    return (float)fixed_point / (float)(1 << fractional_bits);
}

int Fixed::toInt(void) const {
    return fixed_point >> fractional_bits;
}

bool Fixed::operator>(const Fixed &f) const { return fixed_point > f.fixed_point; }
bool Fixed::operator<(const Fixed &f) const { return fixed_point < f.fixed_point; }
bool Fixed::operator>=(const Fixed &f) const { return fixed_point >= f.fixed_point; }
bool Fixed::operator<=(const Fixed &f) const { return fixed_point <= f.fixed_point; }
bool Fixed::operator==(const Fixed &f) const { return fixed_point == f.fixed_point; }
bool Fixed::operator!=(const Fixed &f) const { return fixed_point != f.fixed_point; }

Fixed Fixed::operator+(const Fixed &f) const {
    Fixed d;
    d.setRawBits(this->fixed_point + f.fixed_point);
    return d;
}

Fixed Fixed::operator-(const Fixed &f) const {
     Fixed d;
    d.setRawBits(this->fixed_point - f.fixed_point);
    return d;
}

Fixed Fixed::operator*(const Fixed &f) const {
    Fixed d;
    long int x = this->fixed_point * f.fixed_point;
    d.setRawBits((int)x >> f.fractional_bits);
    return d;
}

Fixed Fixed::operator/(const Fixed &f) const {
    Fixed d;
    long int x = this->fixed_point << f.fractional_bits;
    d.setRawBits(x / f.fixed_point);
    return d;
}

Fixed& Fixed::operator++() {
    fixed_point++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    fixed_point++;
    return temp;
}

Fixed& Fixed::operator--() {
    fixed_point--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    fixed_point--;
    return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream &out, const Fixed &f) {
    out << f.toFloat();
    return out;
}
