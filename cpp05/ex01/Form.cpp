#include "Form.hpp"
#include "Bureaucrat.hpp"

std::string Form::getName() const
{
    return name;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout<<"Form constructor called"<<std::endl;
    if (gradeToExecute < 1 || gradeToSign< 1)
        throw GradeTooHighException();
    if (gradeToExecute > 150 || gradeToSign > 150)
        throw GradeTooLowException();
}


Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout<<"Form copy constructor called"<<std::endl;
}

std::ostream& operator<<(std::ostream& out, const Form &form)
{
    out<<"Form "<< form.getName()<<"| Signed: "<<form.getIsSigned()<<"| gradeToSign: " << form.getGradeToSign()<<"| grade toExecute: "<< form.getGradeToExecute();
    return out;
}

Form::~Form()
{
    std::cout<<"Form destructor called"<<std::endl;
}

const char * Form::GradeTooHighException::what() const throw()
{
    return ("Form : grade too high");
}

const char * Form::GradeTooLowException::what() const throw()
{
    return ("Form grade too Low");
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.Getgrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}
