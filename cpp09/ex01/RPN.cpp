#include "RPN.hpp"

RPN::RPN(){}

RPN& RPN::operator=(const RPN &other)
{
    if (this != &other)
        this->s = other.s;
    return (*this);
}

RPN::RPN(const RPN &other)
{
    this->s = other.s;
}

void RPN::sol(const std::string s)
{
    std::stringstream ss(s);
    std::string tok;
    
    while(ss >> tok)
    {
        if (tok == '-' || tok == '+' || tok == '*' || tok == '/')
        {
            if (s.size() < 2)
            {
                std::cerr<<"error"<<std::endl;
                return ;
            }
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            int res;
            if (tok == '-')
                res = a - b;
            else if (tok == '+')
                res = a + b;
            else if (tok == '*')
                res = a * b;
            else
            {
                if (b == 0)
                {
                    std::cerr<<"You can't divide to 0"<<std::endl;
                    return ;
                }
                res = a / b;
            }
            s.push(res);
        }
        else if (tok.length() == 1 && isdigit(tok[0]))
        {
            int val = std::stoi(tok);
            s.push(val);
        }
        else
        {
            std::cerr<<"error"<<std::endl;
            return ;
        }
    }
    if (s.size() != 1)
    {
        std::cerr<<"error"<<std::endl;
        return ;
    }
    std::cout<<s.top()<<std::endl;
}