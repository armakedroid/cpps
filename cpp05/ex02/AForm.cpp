#include "AForm.hpp"
#include "Bureaucrat.hpp"

std::string AForm::getName() const
{
    return name;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout<<"AForm constructor called"<<std::endl;
    if (gradeToExecute < 1 || gradeToSign< 1)
        throw GradeTooHighException();
    if (gradeToExecute > 150 || gradeToSign > 150)
        throw GradeTooLowException();
}


AForm& AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout<<"AForm copy constructor called"<<std::endl;
}

std::ostream& operator<<(std::ostream& out, const AForm &Aform)
{
    out<<"AForm "<< Aform.getName()<<"| Signed: "<<Aform.getIsSigned()<<"| gradeToSign: " << Aform.getGradeToSign()<<"| grade toExecute: "<< Aform.getGradeToExecute();
    return out;
}

void AForm::checkExecute(Bureaucrat const & executor) const
{
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.Getgrade() > gradeToExecute)
        throw GradeTooLowException();
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "AForm is not signed";
}

AForm::~AForm()
{
    std::cout<<"AForm destructor called"<<std::endl;
}

const char * AForm::GradeTooHighException::what() const throw()
{
    return ("AForm : grade too high");
}

const char * AForm::GradeTooLowException::what() const throw()
{
    return ("AForm grade too Low");
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.Getgrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}
