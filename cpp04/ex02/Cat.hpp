#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
private:
    Brain *brain;

public:
    Cat();
    Cat(const Cat &c);
    Cat &operator=(const Cat &c);
    ~Cat();

    virtual void makeSound() const;
    Brain *getBrain() const;
};

#endif
