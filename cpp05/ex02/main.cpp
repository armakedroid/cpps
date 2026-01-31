#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(0));
    try
    {
        Bureaucrat Poghos("Poghos", 50);
        Bureaucrat admin("Admin", 1);
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Liparit");
        PresidentialPardonForm pardon("Bardughemios");
        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;
        Poghos.signForm(shrub);
        Poghos.signForm(robot);
        Poghos.signForm(pardon);
        admin.signForm(pardon);
        std::cout << std::endl;
        Poghos.executeForm(shrub);
        Poghos.executeForm(robot);
        Poghos.executeForm(pardon);
        std::cout << std::endl;
        admin.executeForm(shrub);
        admin.executeForm(robot);
        admin.executeForm(pardon);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}