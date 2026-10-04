#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <sstream>
#include <stack>
#include <exception>
#include <iostream>

class RPN{
    private:
        std::string s;
    public:
        RPN();
        RPN(const RPN &r);
        RPN(std::string str);
        RPN &operator=(const RPN &r);
        ~RPN();

        int calculate();
};

#endif