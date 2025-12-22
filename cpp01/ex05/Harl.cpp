#include "Harl.hpp"

Harl::Harl() {}

void Harl::complain(std::string name)
{
	std::string arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcs[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

	for (int i = 0; i < (int)(arr->length()); i++)
	{
		if (name == arr[i])
		{
			(this->*(funcs[i]))();
			return ;
		}
	}
	std::cout<<"Command not found"<<std::endl;
}

void Harl::error()
{
	std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}

void Harl::warning()
{
	std::cout<<"I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month."<<std::endl;
}

void Harl::info()
{
	std::cout<<"I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!"<<std::endl;
}

void Harl::debug()
{
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"<<std::endl;
}