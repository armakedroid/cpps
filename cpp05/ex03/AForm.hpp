#pragma once
#include <exception>
#include <iostream>
#include <ostream>
#include <string>

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    protected:
        void checkExecute(Bureaucrat const & executor) const;
    public:
        virtual void execute(Bureaucrat const & executor) const = 0;
    class FormNotSignedException : public std::exception
{
    public:
        virtual const char* what() const throw();
};
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
        AForm& operator=(const AForm &other);
        AForm(const AForm& other);
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        void beSigned(const Bureaucrat &b);
        virtual ~AForm();
};
std::ostream& operator<<(std::ostream& out,const AForm &form);