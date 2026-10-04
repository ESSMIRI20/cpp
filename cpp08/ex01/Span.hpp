#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
private:
    unsigned int        max_Size;
    std::vector<int>    data;

public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int n);

    int shortestSpan() const;
    int longestSpan() const;

    template <typename It>
    void addRange(It begin, It end);
};

template <typename It>
void Span::addRange(It begin, It end)
{
    if (data.size() + std::distance(begin, end) > max_Size)
        throw std::out_of_range("Not enough space");

    data.insert(data.end(), begin, end);
}

#endif