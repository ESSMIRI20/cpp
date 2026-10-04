#include <string>
#include <iostream>

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &b);
        ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &b);
        const std::string getName() const;
        int getGrade() const;
        void increment_grade();
        void dencrement_grade();
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
std::ostream& operator<<(std::ostream& so, const Bureaucrat& b);