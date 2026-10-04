#include "Span.hpp"

Span::Span() : max_Size(0) {}

Span::Span(unsigned int N) : max_Size(N) {}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        max_Size = other.max_Size;
        data = other.data;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
    if (data.size() >= max_Size)
        throw std::runtime_error("Span is full");

    data.push_back(n);
}

int Span::longestSpan() const
{
    if (data.size() < 2)
        throw std::runtime_error("Not enough elements");

    int min = *std::min_element(data.begin(), data.end());
    int max = *std::max_element(data.begin(), data.end());

    return max - min;
}

int Span::shortestSpan() const
{
    if (data.size() < 2)
        throw std::runtime_error("Not enough elements");

    std::vector<int> tmp = data;
    std::sort(tmp.begin(), tmp.end());

    int shortest = tmp[1] - tmp[0];

    for (size_t i = 1; i < tmp.size() - 1; i++)
    {
        int diff = tmp[i + 1] - tmp[i];
        if (diff < shortest)
            shortest = diff;
    }

    return shortest;
}