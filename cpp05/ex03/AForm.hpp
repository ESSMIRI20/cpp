#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int gradeSign;
    const int gradeExec;
    const std::string target;
public:
    AForm();
    AForm(const std::string &name, int gradeSign, int gradeExec, const std::string &target);
    AForm(const AForm &other);
    virtual ~AForm();

    AForm &operator=(const AForm &other);

    const std::string &getName() const;
    const std::string &getTarget() const;
    bool isSignedForm() const;
    int getGradeSign() const;
    int getGradeExec() const;

    void beSigned(const Bureaucrat &b);
    void execute(const Bureaucrat &executor) const;
    virtual void executeAction() const = 0;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
    class FormNotSignedException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
