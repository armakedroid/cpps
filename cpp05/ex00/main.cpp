#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat first("Poghos", 151);
		Bureaucrat second(first);
		std::cout<<"Name is "<<second.getName()<<std::endl;
		std::cout<<"Grade is "<<second.getGrade()<<std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch (const std::exception& e)
    {
        std::cout << "Std exception: " << e.what() << std::endl;
    }
}