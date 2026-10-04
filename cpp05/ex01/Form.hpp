#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form{
    private:
        const std::string name;
        bool isSigned;
        const int grad_sign;
        const int grad_exec;
    public:
        Form();
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        Form(const Form& f);
        ~Form();

        Form& operator=(const Form& f);

        void beSigned(const Bureaucrat& b);

        const std::string getName() const;
        bool getInd() const;
        int getGrad_sign() const;
        int getGrad_exec() const;
        class GradeTooHighException : public std::exception{
            public:
                virtual const char *what() const throw() {
                    return "Grade too High";
                }
        };
        class GradeTooLowException : public std::exception{
            public:
                virtual const char *what() const throw() {
                    return "Grade too Low";
                }
        };
};

std::ostream& operator<<(std::ostream& so, const Form& b);

#endif