#include "Bureaucrat.hpp"

int Bureaucrat::Getgrade() const
{
    return grade;
}

std::string Bureaucrat::Getname() const
{
    return name;
}

Bureaucrat::Bureaucrat() : name("Liparit"), grade(150)
{
    std::cout<<"Bureaucrat constructor called"<<std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat assignment operator called\n";
    if (this != &other)
        grade = other.grade;
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
    std::cout<<"Bureaucrat copy constructor called"<<std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout<<"Bureaucrat destructor called"<<std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "high Grade";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "low Grade";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    std::cout<<"Bureaucrat constructor called"<<std::endl;
    if (grade < 1)
        throw(GradeTooHighException());
    if (grade > 150)
        throw(GradeTooLowException());
}

void Bureaucrat::signForm(AForm &form)
{
    try{
        form.beSigned(*this);
        std::cout<< name<< " signed "<< form.getName() <<std::endl;
    }
    catch (std::exception &err)
    {
        std::cout<<name<<" couldn't sign"<<form.getName()<<err.what()<<std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}