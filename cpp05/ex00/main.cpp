#include "Bureaucrat.hpp"

int main()
{
    try{
        Bureaucrat b("test1", 1);
        b.increment_grade();
        std::cout << b;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;

    }
    
    return (0);
}