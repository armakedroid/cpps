#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
    std::cout<<"Intern constructor called"<<std::endl;
}

Intern::Intern(const Intern&)
{
    std::cout<<"Intern copy constructor called"<<std::endl;
}

Intern& Intern::operator=(const Intern&) 
{
    std::cout<<"Intern assignment operator called"<<std::endl;
    return *this;
}

Intern::~Intern() 
{
    std::cout<<"Intern destructor called"<<std::endl;
}

static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*creators[3])(const std::string&) = {
        &createShrubbery,
        &createRobotomy,
        &createPresidential
    };

    for (int i = 0; i < 3; i++) {
        if (names[i] == name) {
            std::cout << "Intern creates " << name << std::endl;
            return creators[i](target);
        }
    }

    std::cerr << "Intern cannot create form: " << name << std::endl;
    return NULL;
}