#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
	std::cout<<"Bureaucrat constructor called"<<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cp) : name(cp.name), grade(cp.grade)
{
	std::cout<<"Bureaucrat copy constructor called"<<std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& op)
{
	if (this != &op)
	{
		grade = op.grade;
	}
	std::cout<<"Bureaucrat copy assignment operator called"<<std::endl;
	return *this;
}

const std::string Bureaucrat::getName()
{
	return this->name;
}

int Bureaucrat::getGrade()
{
	return this->grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<"Bureaucrat destructor called"<<std::endl;
}