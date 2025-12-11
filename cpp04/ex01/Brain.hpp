#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
private:
    std::string ideas[100];

public:
    Brain();
    Brain(const Brain &b);
    Brain &operator=(const Brain &b);
    ~Brain();

    void setIdea(int index, const std::string &idea);
    std::string getIdea(int index) const;
};

#endif
