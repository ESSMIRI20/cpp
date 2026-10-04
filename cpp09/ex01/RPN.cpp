
#include "RPN.hpp"

RPN::RPN() : s("") {}

RPN::RPN(const RPN &r) : s(r.s)
{
}

RPN::RPN(std::string str) : s(str)
{
}

RPN &RPN::operator=(const RPN &r)
{
    if (this != &r)
        s = r.s;
    return (*this);
}

RPN::~RPN(){}

int calc(int a, int b, char c)
{
    if (c == '-')
        return (a - b);
    else if (c == '+')
        return (a + b);
    else if (c == '*')
        return (a * b);
    return (a / b);
}

int RPN::calculate()
{
    std::stack<int> nbr;

    for (size_t i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
            nbr.push(s[i] - 48);
        else if (s[i] == '-' || s[i] == '+' || s[i] == '/' || s[i] == '*')
        {
            if (nbr.size() == 1 || nbr.empty())
                throw std::logic_error("Error");
            int b = nbr.top();
            nbr.pop();
            int a = nbr.top();
            nbr.pop();
            if (b == 0 && s[i] == '/')
                throw std::logic_error("Error: Division by 0");
            int c = calc(a, b, s[i]);
            nbr.push(c);
        }
        else if (s[i] != ' ')
            throw std::logic_error("Error");
    }
    if (nbr.size() != 1)
        throw std::logic_error("Error");
    return nbr.top();
}
