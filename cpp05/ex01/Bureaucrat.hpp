#pragma once
#include <iostream>
#include <string>
#include "Form.hpp"

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
    	class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
	class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
        Bureaucrat();
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat(std::string name, int grade);
        Bureaucrat& operator=(const Bureaucrat &other);
        ~Bureaucrat();
        std::string Getname() const;
        void signForm(Form &sign);
        int Getgrade() const;
};