#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& con, int value)
{
    typename T::iterator it = std::find(con.begin(), con.end(), value);
    if (it == con.end())
        throw std::runtime_error("Value not found");
    return it;
}

#endif