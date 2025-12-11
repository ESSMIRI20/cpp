#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain &b) {
    std::cout << "Brain copy constructor called." << std::endl;
    *this = b;
}

Brain &Brain::operator=(const Brain &b) {
    if (this != &b) {
        for (int i = 0; i < 100; i++)
            ideas[i] = b.ideas[i];
    }
    std::cout << "Brain copy assignment called." << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called." << std::endl;
}

void Brain::setIdea(int index, const std::string &idea) {
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return ideas[index];
    return "";
}
