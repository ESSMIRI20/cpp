#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <vector>
#include <deque>

class PmergeMe
{
private:
    char **s;

    std::vector<int> v;
    std::deque<int> d;

    bool isValidNumber(const std::string &str);

public:
    PmergeMe();
    PmergeMe(char **av);
    PmergeMe(const PmergeMe &p);
    PmergeMe &operator=(const PmergeMe &p);
    ~PmergeMe();

    void parseInput(int ac);

    void sortVector();
    void sortDeque();

    std::vector<int> &getVector();
    std::deque<int> &getDeque();
};

#endif