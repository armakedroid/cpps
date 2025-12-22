#pragma once

#include <iostream>
#include <string>

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
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &cp);
	Bureaucrat &operator=(const Bureaucrat &op);
	const std::string getName();
	int getGrade();
	~Bureaucrat();
};
