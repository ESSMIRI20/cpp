#include <iostream>
#include <string>
#include <exception>

class Bureaucrat{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(int grade);
        Bureaucrat(const Bureaucrat &b);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat& b);
        const std::string getName();
        int getGrade();
        void incrementGrade();
        void decrementGrade();
    public:
        class GradeTooHighException : public std::exception{
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            const char* what() const throw();
        };
};
