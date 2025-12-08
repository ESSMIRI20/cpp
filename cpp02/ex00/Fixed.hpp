#include <iostream>

class Fixed{
    private:
        int  fixed_point;
        static const int fractional_bits;
    public:
        Fixed();
        Fixed(Fixed &f);
        ~Fixed();
        Fixed& operator=(const Fixed &f);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};