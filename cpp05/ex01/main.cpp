#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try{
        Form f("form", 1, 1);
        Bureaucrat b("test2", 2);
        b.signForm(f);
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    return (0);
}