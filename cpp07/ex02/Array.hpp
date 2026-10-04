#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array
{
    private:
        T*              data;
        unsigned int    len;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        T& operator[](unsigned int i);
        const T& operator[](unsigned int i) const;

        unsigned int size() const;
};

#include "Array.tpp"

#endif