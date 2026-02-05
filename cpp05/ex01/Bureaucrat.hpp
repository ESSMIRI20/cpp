#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    // Constructors
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& b);
    ~Bureaucrat();

    Bureaucrat& operator=(const Bureaucrat& b);

    // Getters
    const std::string& getName() const;
    int getGrade() const;

    // Grade operations
    void incrementGrade();
    void decrementGrade();

    // Exceptions
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
    void signForm(Form& f);
};

// Operator <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
