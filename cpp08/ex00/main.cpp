#include "easyfind.hpp"
#include <deque>
#include <exception>

int main()
{
    std::deque<int> val;
    val.push_back(14);
    val.push_back(4);
    val.push_back(144);
    val.push_back(33);
    try
    {
        std::deque<int>::iterator it = easyfind(val, 33);
        std::cout<<"your number = "<<*it<<std::endl;
    }
    catch (const std::exception& err)
    {
        std::cout<<err.what()<<std::endl;
    }
    try
    {
        std::deque<int>::iterator it= easyfind(val, 93);
        std::cout<<"your number = "<<*it<<std::endl;
    }
    catch (const std::exception& err)
    {
        std::cout<<err.what()<<std::endl;
    }
}