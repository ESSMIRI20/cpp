#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int fixed_point;
    static const int fractional_bits;

public:
    Fixed();
    Fixed(const int n);
    Fixed(const float f);
    Fixed(const Fixed &f);
    ~Fixed();

    Fixed& operator=(const Fixed &f);

    int getRawBits(void) const;
    void setRawBits(int const raw);

    float toFloat(void) const;
    int toInt(void) const;

    bool operator>(const Fixed &f) const;
    bool operator<(const Fixed &f) const;
    bool operator>=(const Fixed &f) const;
    bool operator<=(const Fixed &f) const;
    bool operator==(const Fixed &f) const;
    bool operator!=(const Fixed &f) const;

    Fixed operator+(const Fixed &f) const;
    Fixed operator-(const Fixed &f) const;
    Fixed operator*(const Fixed &f) const;
    Fixed operator/(const Fixed &f) const;

    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);

    static Fixed& min(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream &out, const Fixed &f);

#endif
