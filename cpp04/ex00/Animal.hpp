#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &a);
        Animal& operator=(const Animal &a);
        ~Animal();
        virtual void makeSound();
        std::string getType();
};

#endif