#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl;

    j->makeSound(); // Woof! Woof!
    i->makeSound(); // Meow! Meow!

    delete j; // calls Dog destructor + Brain
    delete i; // calls Cat destructor + Brain

    return 0;
}
