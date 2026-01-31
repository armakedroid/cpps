#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Liparit", 50);
		Form form("Form", 40, 20);
		std::cout<<form<<std::endl;
		bob.signForm(form);

		Bureaucrat poghos("Poghos", 10);
		poghos.signForm(form);
		std::cout<<form<<std::endl;
	}
	catch (const std::exception& e)
    {
        std::cerr<< e.what() << std::endl;
    }
}