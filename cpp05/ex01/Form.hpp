#pragma once
#include <exception>
#include <iostream>
#include <ostream>
#include <string>

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    public:
        class GradeTooHighException: public std::exception
        {
            virtual const char * what() const throw();
        };
        class GradeTooLowException: public std::exception
        {
            virtual const char *what() const throw();
        };
    public:
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        Form(const Form& other);
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        Form& operator=(const Form& other);
        void beSigned(const Bureaucrat &b);
        ~Form();
};
std::ostream& operator<<(std::ostream& out,const Form &form);