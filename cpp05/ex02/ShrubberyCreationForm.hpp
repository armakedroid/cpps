#pragma once
#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();
        virtual void execute(Bureaucrat const & executor) const;

};