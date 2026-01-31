#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat first("Liparit", 15);
		Bureaucrat second(first);
		std::cout<<"Name is "<<second.Getname()<<std::endl;
		std::cout<<"Grade is "<<second.Getgrade()<<std::endl;
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
