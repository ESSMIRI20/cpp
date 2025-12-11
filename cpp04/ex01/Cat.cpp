#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
    type = "Cat";
    std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const Cat &c) : Animal(), brain(new Brain()) {
    std::cout << "Cat copy constructor called." << std::endl;
    *this = c; // deep copy via assignment operator
}

Cat &Cat::operator=(const Cat &c) {
    if (this != &c) {
        Animal::operator=(c);      // copy base class members
        *brain = *(c.brain);       // deep copy Brain
    }
    std::cout << "Cat copy assignment called." << std::endl;
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound() {
    std::cout << "Meow! Meow!" << std::endl;
}

Brain *Cat::getBrain() const {
    return brain;
}
