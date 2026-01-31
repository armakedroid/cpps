#pragma once
#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
    private :
        std::string target;
    public :
       PresidentialPardonForm(const std::string &target);
       PresidentialPardonForm(const PresidentialPardonForm &other);
       PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
       ~PresidentialPardonForm();
       virtual void execute(Bureaucrat const & executor) const;
};
