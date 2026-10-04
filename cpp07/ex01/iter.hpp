#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T, typename Func>
void iter(T *array, const std::size_t length, Func func)
{
    std::size_t i = 0;
    while (i < length)
    {
        func(array[i]);
        i++;
    }
}

#endif