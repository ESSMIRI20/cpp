#include <iostream>

template <typename T>
Array<T>::Array() : data(NULL), len(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]()), len(n)
{
}

template <typename T>
Array<T>::Array(const Array& other) : data(NULL), len(other.len)
{
    if (len)
    {
        data = new T[len];
        for (unsigned int i = 0; i < len; i++)
            data[i] = other.data[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this == &other)
        return *this;

    delete[] data;

    len = other.len;
    if (len != 0)
        data = new T[len];
    else
        data = NULL;

    for (unsigned int i = 0; i < len; i++)
        data[i] = other.data[i];

    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] data;
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= len)
        throw std::out_of_range("+ Array index out of bounds");
    return data[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
    if (i >= len)
        throw std::out_of_range("- Array index out of bounds");
    return data[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return len;
}