#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), target(other.target)
{
    std::cout<<"ShrubberyCreationForm copy constructor called"<<std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout<<"ShrubberyCreationForm assignment operator called"<<std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    checkExecute(executor);

    std::ofstream file((target + "_shrubbery").c_str());
    if (!file)
        return;

    file <<
        "       _-_\n"
        "    /`     `\\\n"
        "   |  .-. .-.|\n"
        "   |  | | | ||\n"
        "   |  |_| |_| |\n"
        "    \\         /\n"
        "      `-.__.-'\n";
    file.close();
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout<<"ShrubberyCreationForm constructor called"<<std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout<<"ShrubberyCreationForm destructor called"<<std::endl;
}

