#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

class RPN
{
    private:
        std::stack<int> s;
    public:
        void sol(std::string sa);
        RPN();
        ~RPN();
        RPN&operator=(const RPN& other);
        RPN(const RPN& other);
};