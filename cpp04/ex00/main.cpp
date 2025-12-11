#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"



int main()
{
    Animal* meta = new Animal();
    Animal* j = new Dog();
    Animal* i = new Cat();
    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << "Wrong Animal & Wrong Cat" << std::endl;

    WrongAnimal* m = new WrongAnimal();
    WrongAnimal* f = new WrongCat();
    std::cout << f->getType() << " " << std::endl;
    f->makeSound(); //will output the WrongCat sound!
    m->makeSound();
    // ...
    return 0;
}