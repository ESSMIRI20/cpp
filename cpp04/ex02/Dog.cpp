#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog &d) : AAnimal(), brain(new Brain()) {
    std::cout << "Dog copy constructor called." << std::endl;
    *this = d;
}

Dog &Dog::operator=(const Dog &d) {
    if (this != &d) {
        AAnimal::operator=(d);
        *brain = *(d.brain); // deep copy
    }
    std::cout << "Dog copy assignment called." << std::endl;
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destructor called." << std::endl;
}

void Dog::makeSound() const{
    std::cout << "Woof! Woof!" << std::endl;
}

Brain *Dog::getBrain() const {
    return brain;
}
