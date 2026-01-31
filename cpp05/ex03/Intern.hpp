#pragma once
#include <string>
#include "AForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern&);
    Intern& operator=(const Intern&);
    ~Intern();

    AForm* makeForm(const std::string& name, const std::string& target);
};
